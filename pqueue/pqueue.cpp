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

    while (i)
    {
        const auto p = (i - 1) / 2; // Parent.

        if (_mem[i] < _mem[p])
        {
            std::swap(_mem[p], _mem[i]);
            i = p;
        }
        else
        {
            break;
        }
    }
}

size_t pqueue::pop()
{
    auto s = size();

    if (!s)
    {
        throw std::out_of_range("");
    }

    auto ret = _mem[0];

    if (s > 1)
    {
        std::swap(_mem[0], _mem[s - 1]);
    }

    _mem.pop_back();

    size_t i = 0;

    while (i < s)
    {
        auto l = i * 2 + 1, r = i * 2 + 2;

        if (l < s)
        {
            auto c = l;

            if (r < s && _mem[c] < _mem[r])
            {
                c = r;
            }

            std::swap(_mem[c], _mem[i]);
            i = c;
        }
        else
        {
            break;
        }
    }

    return ret;
}

} // namespace W