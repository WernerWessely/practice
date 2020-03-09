#include "trie.hpp"
#include <algorithm>

namespace W
{

void trie::add(const std::string &key, unsigned val)
{
    _add(_children.at(key[0] - 'a'), key, 1, val);
    ++_nchildren;
}

void trie::_add(triep &cur, const std::string &key, size_t next, unsigned val)
{
    triep tmp(cur ? cur : triep(new trie));

    if (!key[next])
    {
        // End of word.
        tmp->_end = true;
        tmp->_val = val;
    }
    else
    {
        _add(tmp->_children.at(key[next] - 'a'), key, next + 1, val);
        ++tmp->_nchildren;
    }

    std::swap(cur, tmp);
}

} // namespace W