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
    if (_size >= _capacity / 2)
    {
        auto tmp = std::make_unique<int[]>((_capacity *= 2));

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
    int ret = _mem[_size--];

    if (_size <= _capacity / 4)
    {
        auto tmp = std::make_unique<int[]>((_capacity = _size));

        for (size_t i = 0; i < _size; ++i)
        {
            tmp[i] = _mem[i];
        }

        _mem = std::move(tmp);
    }

    return ret;
}

} // namespace W