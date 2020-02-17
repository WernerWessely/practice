#include "wv.hpp"

namespace W
{

wv::wv()
{
}

size_t wv::size() const
{
    return _size;
}

bool wv::empty() const
{
    return !_size;
}

size_t wv::capacity() const
{
    return _capacity;
}

void wv::push(int value)
{
    realloc();
}

void wv::realloc()
{
    if (_size >= _capacity / 2)
    {
    }
    else if (_size <= _capacity / 4)
    {
    }
}

} // namespace W