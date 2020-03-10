#include "trie.hpp"
#include <algorithm>

namespace W
{

void trie::add(const std::string &key, unsigned val)
{
    _add(_roots.at(key[0] - 'a'), key, 1, val);
}

void trie::_add(trienp &ch, const std::string &key, size_t next, unsigned val)
{
    trienp cur(ch ? ch : trienp(new trien()));

    if (!key[next])
    {
        // We have reached the end.
        cur->_end = true;
        cur->_val = val;
    }
    else
    {
        _add(cur->_children.at(key[next] - 'a'), key, next + 1, val);
        ++cur->_nchildren;
    }

    // In case of an exception we roll back the add, so we assign at the end.
    ch = cur;
}

size_t trie::size() const
{
    // We get the size by counting all the ends, depth first.
    return std::for_each(_roots.begin(), _roots.end(), sizor())._size;
}

void trie::sizor::operator()(const trienp &p)
{
    if (p)
    {
        if (p->_end)
        {
            ++_size;
        }

        _size += std::for_each(p->_children.begin(), p->_children.end(), sizor())._size;
    }
}

unsigned trie::get(const std::string &key) const
{
    size_t i = 0;

    for (trienp cur = _roots.at(key[i] - 'a'); cur; cur = cur->_children.at(key[++i] - 'a'))
    {
        if (!key[i + 1])
        {
            if (cur->_end)
            {
                return cur->_val;
            }

            break;
        }
    }

    throw std::out_of_range("");
}

void trie::rem(const std::string &key)
{
    _rem(_roots.at(key[0] - 'a'), key, 1);
}

void trie::_rem(trienp &ch, const std::string &key, size_t next)
{
    if (ch)
    {
        if (!key[next])
        {
            // End of word.
            if (!ch->_end)
            {
                throw std::out_of_range("");
            }

            ch->_end = false;
        }
        else
        {
            _rem(ch->_children.at(key[next] - 'a'), key, next + 1);
            --ch->_nchildren;
        }

        if (!ch->_nchildren && !ch->_end)
        {
            ch.reset();
        }
    }
    else
    {
        throw std::out_of_range("");
    }
}

} // namespace W