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
}

} // namespace W