#include "deplist.hpp"

namespace W
{

void deplist::add_edge(size_t from, size_t to, size_t weight)
{
    if (from >= _n || to >= _n)
    {
        throw std::out_of_range("");
    }

    _heads[from].reset(new adj(to, weight, _heads[from]));
}

} // namespace W