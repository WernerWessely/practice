#include "slist.hpp"
#include <stdexcept>

namespace W
{

slist::~slist()
{
    while (_first)
    {
        auto next = _first->_next;
        delete _first;
        _first = next;
    }
}

size_t slist::len() const
{
    size_t len = 0;

    for (auto n = _first; n; n = n->_next, ++len)
        ;

    return len;
}

bool slist::empty() const
{
    return !!!_first;
}

void slist::prepend(int value)
{
    insert(0, value);
}

void slist::append(int value)
{
    auto cur = _first;
    snode *n = new snode(value, nullptr);

    for (; cur && cur->_next; cur = cur->_next)
        ;

    if (!cur)
    {
        _first = n;
    }
    else
    {
        cur->_next = n;
    }
}

void slist::insert(size_t index, int value)
{
    snode *cur = _first, *prev = nullptr;
    size_t len = 0;

    for (; cur && len < index; prev = cur, cur = cur->_next, ++len)
        ;

    if (index > len)
    {
        throw std::out_of_range("");
    }

    // cur is null if empty or if append.
    snode *node = new snode(value, cur);

    if (!len)
    {
        _first = node;
    }
    else
    {
        prev->_next = node;
    }
}

int slist::at(size_t index) const
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

int slist::front() const
{
    if (!_first)
    {
        throw std::out_of_range("");
    }

    return _first->_val;
}

int slist::back() const
{
    auto cur = _first;

    for (; cur && cur->_next; cur = cur->_next)
        ;

    if (!cur)
    {
        throw std::out_of_range("");
    }

    return cur->_val;
}

int slist::pop_front()
{
    if (!_first)
    {
        throw std::out_of_range("");
    }

    auto ret = _first->_val;
    auto del = _first;

    _first = _first->_next;

    delete del;

    return ret;
}

int slist::pop_back()
{
    snode *cur = _first, *prev = nullptr;

    for (; cur && cur->_next; prev = cur, cur = cur->_next)
        ;

    if (!cur)
    {
        throw std::out_of_range("");
    }

    auto ret = cur->_val;

    if (prev)
    {
        prev->_next = nullptr;
    }
    else
    {
        _first = nullptr;
    }

    delete cur;

    return ret;
}

void slist::remove(size_t index)
{
    snode *cur = _first, *prev = nullptr;

    for (size_t len = 0; cur && len < index; prev = cur, cur = cur->_next, ++len)
        ;

    if (!cur)
    {
        throw std::out_of_range("");
    }

    if (prev)
    {
        prev->_next = cur->_next;
    }
    else
    {
        _first = cur->_next;
    }

    delete cur;
}

int slist::backn(size_t n) const
{
    size_t l = len();

    if (n >= l)
    {
        throw std::out_of_range("");
    }

    const size_t index = l - n - 1;
    auto cur = _first;

    for (size_t i = 0; i < index; cur = cur->_next, ++i)
        ;

    return cur->_val;
}

int slist::backnr(size_t n) const
{
    const snode *cur = _first;
    size_t l = 0;

    if (cur)
    {
        ++l;

        if (cur->_next)
        {
            cur = _backnr(++l, n, cur->_next);
        }
    }

    if (!cur)
    {
        throw std::out_of_range("");
    }

    return cur->_val;
}

const W::slist::snode *slist::_backnr(size_t &l, size_t n, const W::slist::snode *node) const
{
    auto cur = node;

    if (cur->_next)
    {
        cur = _backnr(++l, n, cur->_next);
    }
    else
    {
        // End.
    }
}

} // namespace W