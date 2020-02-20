#include "dlist.hpp"
#include <stdexcept>

namespace W
{
dlist::~dlist()
{
    while (_first)
    {
        const auto tmp = _first->_next;
        delete _first;
        _first = tmp;
    }
}

size_t dlist::len() const
{
    size_t len = 0;

    for (auto n = _first; n; n = n->_next, ++len)
        ;

    return len;
}

bool dlist::empty() const
{
    return _first;
}

void dlist::insert(size_t index, int value)
{
    dnode *cur = _first, *prev = nullptr;
    size_t l = 0;

    for (; cur && l < index; prev = cur, cur = cur->_next, ++l)
        ;

    if (index > l)
    {
        throw std::out_of_range("");
    }

    dnode *tmp = new dnode(nullptr, nullptr, value);

    if (!cur)
    {
        // Empty or append.
        _first = _last = tmp;
    }
    else
    {
    }
}

} // namespace W