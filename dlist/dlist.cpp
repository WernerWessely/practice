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
    const auto del = _first;

    if (del)
    {
        _first = del->_next;

        if (_first)
        {
            _first->_prev = nullptr;
        }
        else
        {
            _last = _first;
        }

        const auto ret = del->_val;

        delete del;

        return ret;
    }

    throw std::out_of_range("");
}

int dlist::pop_back()
{
    const auto del = _last;

    if (del)
    {
        _last = del->_prev;

        if (_last)
        {
            _last->_next = nullptr;
        }
        else
        {
            _first = _last;
        }

        const auto ret = del->_val;

        delete del;

        return ret;
    }

    throw std::out_of_range("");
}

void dlist::remove(size_t index)
{
    auto del = _first;

    for (size_t i = 0; i < index && del; del = del->_next, ++i)
        ;

    if (!del)
    {
        throw std::out_of_range("");
    }

    if (del->_prev)
    {
        del->_prev->_next = del->_next;
    }
    else
    {
        _first = del->_next;
    }

    if (del->_next)
    {
        del->_next->_prev = del->_prev;
    }
    else
    {
        _last = del->_prev;
    }

    delete del;
}

int dlist::backn(size_t n) const
{
    const dnode *get = _last;

    for (size_t i = 0; get; get = get->_prev, ++i)
    {
        if (i == n)
        {
            return get->_val;
        }
    }

    throw std::out_of_range("");
}

int dlist::backnr(size_t n) const
{
    size_t i = 0;

    return _backnr(i, n, _last);
}

int dlist::_backnr(size_t &i, size_t n, const dnode *node) const
{
    if (!node)
    {
        throw std::out_of_range("");
    }

    return i == n ? node->_val : _backnr(++i, n, node->_prev);
}

void dlist::reverse()
{
    dnode *cur = _first ? _first->_next : nullptr;

    while (cur)
    {
        cur->_prev->_next = cur->_next;

        if (cur->_next)
        {
            cur->_next->_prev = cur->_prev;
        }

        cur->_next = _first;
        _first->_prev = cur;

        _first = cur;

        cur = cur->_prev->_next;

        _first->_prev = nullptr;
    }
}

} // namespace W