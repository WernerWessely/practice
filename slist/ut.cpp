
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "slist.hpp"

namespace w
{

slist::slist() : _root(nullptr) {}

slist::~slist()
{
    while (_root)
    {
        slistn *tmp = _root->_next;

        delete _root;

        _root = tmp;
    }
}

} // namespace w