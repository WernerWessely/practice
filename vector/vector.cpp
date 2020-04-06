#include "vector.h"

namespace w
{

int vector::size() const
{
    return _size;
}

bool vector::empty() const
{
    return !_size;
}

int vector::capacity() const
{
    return _capacity;
}

void vector::push(int value)
{
    insert(_size, value);
}

void vector::insert(int i, int value)
{
    if (i < 0 || i > _size)
    {
        throw std::out_of_range("");
    }

    _enlarge();

    // Shift up all elements at and above index.
    for (int j = _size - 1; j >= i; --j)
    {
        _mem[j + 1] = _mem[j];
    }

    ++_size;

    _mem[i] = value;
}

int vector::pop()
{
    return remove(_size - 1);
}

int vector::remove(int i)
{
    if (i < 0 || i >= _size)
    {
        throw std::out_of_range("");
    }

    int ret = _mem[i];

    // Shift down all elements above index.
    for (int j = i + 1; j < _size; ++j)
    {
        _mem[j - 1] = _mem[j];
    }

    --_size;

    return ret;
}

void vector::_enlarge()
{
    if (_size >= _capacity)
    {
        _capacity = _capacity ? _capacity * 2 : 1;

        memp tmp(new int[_capacity]);

        std::copy(_mem.get(), _mem.get() + _size, tmp.get());

        std::swap(_mem, tmp);
    }
}

int vector::at(int i) const
{
    if (i < 0 || i >= _size)
    {
        throw std::out_of_range("");
    }

    return _mem[i];
}

void vector::prepend(int value)
{
    insert(0, value);
}

void vector::reverse()
{
    for (int i = 0, j = _size - 1; i < j; ++i, --j)
    {
        std::swap(_mem[i], _mem[j]);
    }
}

} // namespace w