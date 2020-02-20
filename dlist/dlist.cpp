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
    return !_first;
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

    if (cur)
    {
        tmp->_next = cur;
        cur->_prev = tmp;
    }
    else
    {
        // Empty or append.
        _last = tmp;
    }

    if (prev)
    {
        prev->_next = tmp;
        tmp->_prev = prev;
    }
    else
    {
        _first = tmp;
    }
}

void dlist::prepend(int value)
{
    insert(0, value);
}

void dlist::append(int value)
{
    dnode *tmp = new dnode(_last, nullptr, value);

    if (_last)
    {
        _last->_next = tmp;
        _last = tmp;
    }
    else
    {
        _first = _last = tmp;
    }
}

int dlist::at(size_t index) const
{
    size_t i = 0;

    for (auto n = _first; n; n = n->_next, ++i)
    {
        if (i == index)
        {
            return n->_val;
        }
    }

    throw std::out_of_range("");
}

int dlist::front() const
{
    if (_first)
    {
        return _first->_val;
    }

    throw std::out_of_range("");
}

int dlist::back() const
{
    if (_last)
    {
        return _last->_val;
    }

    throw std::out_of_range("");
}

int dlist::pop_front()
{
}

} // namespace W