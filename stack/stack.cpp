#include "stack.hpp"

namespace W
{
size_t stack::size() const
{
    return _size;
}

bool stack::empty() const
{
    return !_size;
}

int stack::top() const
{
    if (!size)
    {
        throw std::out_of_range("");
    }

    return _mem[_size - 1];
}

void stack::push(int val)
{
    if (_size == _capa)
    {
        std::unique_ptr<int[]> tmp(new int[(_capa = _capa ? _capa * 2 : 1)]);

        for (size_t i = 0; i < _size; ++i)
        {
            tmp[i] = _mem[i];
        }

        std::swap(_mem, tmp);
    }

    _mem[_size++] = val;
}

int stack::pop()
{
    if (!_size)
    {
        throw std::out_of_range("");
    }

    return _mem[_size--];
}

} // namespace W