#include "pqueue.hpp"

namespace W
{
size_t pqueue::size() const
{
    return _mem.size();
}

size_t pqueue::height() const
{
    size_t h = 0;

    // Height of complete bi-tree is log(n) + 1.
    for (auto s = size(); s; s >>= 1, ++h)
        ;

    return h;
}

void pqueue::push(size_t prio)
{
    _mem.push_back(prio);

    size_t i = _mem.size() - 1;

    for (size_t p = (i - 1) / 2; i && _mem[i] < _mem[p]; std::swap(_mem[p], _mem[i]), i = p)
        ;
}

size_t pqueue::pop()
{
    auto l = _mem.size();

    if (!l)
    {
        throw std::out_of_range("");
    }

    auto tmp = _mem[l - 1];
    _mem.pop_back();

    std::swap(tmp, _mem[0]);

    size_t i = 0;

    while (i < l)
    {
        size_t l = i * 2 + 1, r = i * 2 + 2;

        size_t c = l < r ? r : l;

        if ()
    }
}

} // namespace W