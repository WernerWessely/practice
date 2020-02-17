#include "wv.hpp"
#include <stdexcept>

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
    if (_size >= _capacity)
    {
        _capacity = _capacity ? _capacity * 2 : 1;

        std::unique_ptr<int[]> tmp(new int[(_capacity)]);

        for (size_t i = 0; i < _size; ++i)
        {
            tmp[i] = _mem[i];
        }

        _mem = std::move(tmp);
    }

    _mem[_size++] = value;
}

int wv::pop()
{
    if (!_size)
    {
        throw std::out_of_range("");
    }

    int ret = _mem[_size--];

    // TODO: Add resizing!

    return ret;
}

int wv::at(size_t index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("");
    }

    return _mem[index];
}

void wv::insert(size_t index, int value)
{
    if (index >= _size)
    {
        throw std::out_of_range("");
    }

    // TODO: continue here...
}

} // namespace W