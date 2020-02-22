#include "htable.hpp"

namespace W
{

size_t htable::size() const
{
    return _size;
}

void htable::add(const std::string &key, int val)
{
    if (!_cap)
    {
        _cap = 1;

        _tab.reset(new helem[_cap]);
    }

    _insert(_tab, key, val);
}

void htable::_insert(htab &tab, const std::string &key, int val)
{
    const size_t i = _index(key);
    helem cur = tab[i], prev = nullptr;

    for (; cur && key != cur->_key; prev = cur, cur = cur->_next)
        ;

    if (cur)
    {
        // Key alread exists, replace val.
        cur->_val = val;
    }
    else
    {
        // New key.
        cur.reset(new hentry(key, val, nullptr));

        ++_size;
    }

    if (prev)
    {
        // Bucket not empty, append.
        prev->_next = cur;
    }
    else
    {
        // Empty, first entry.
        tab[i] = cur;

        ++_bucks;
    }
}

size_t htable::_index(const std::string &key) const
{
    size_t hash = 7;

    for (auto ch : key)
    {
        hash = hash * 31 + ch;
    }

    return hash % _cap;
}

int htable::get(const std::string &key) const
{
    for (helem cur = _tab ? _tab[_index(key)] : nullptr; cur; cur = cur->_next)
    {
        if (key == cur->_key)
        {
            return cur->_val;
        }
    }

    throw std::out_of_range("");
}

void htable::remove(const std::string &key)
{
    const size_t i = _index(key);
    helem cur = _tab[i], prev = nullptr;

    for (; cur && key != cur->_key; prev = cur, cur = cur->_next)
        ;

    if (!cur)
    {
        throw std::out_of_range("");
    }

    // Unlink, cur will free.
    if (prev)
    {
        prev->_next = cur->_next;
    }
    else if (!(_tab[i] = cur->_next))
    {
        --_bucks;
    }

    --_size;
}

} // namespace W