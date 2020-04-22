#include "slist.hpp"

namespace w
{

slist::slist() : _root(nullptr) {}

slist::~slist()
{
    while (_root)
    {
        slistn *next = _root->_next;
        delete _root;
        _root = next;
    }
}

int slist::len() const
{
    int ret;

    for (slistn *next = _root; next; ++ret, next = next->_next)
        ;

    return ret;
}

bool slist::empty() const
{
    return !_root;
}

void slist::prepend(int val)
{
    _root = new slistn(val, _root ? _root->_next : nullptr);
}

void slist::append(int val)
{
    if (!_root)
    {
        _root = new slistn(val);
    }
    else
    {
        slistn *prev = _root;

        for (; prev->_next; prev = prev->_next)
            ;

        prev->_next = new slistn(val);
    }
}

} // namespace w