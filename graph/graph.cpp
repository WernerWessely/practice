#include "graph.hpp"

namespace W
{

void graph::add_edge(size_t from, size_t to, size_t weight)
{
    _l.add_edge(from, to, weight);
}

std::vector<size_t> graph::bfs(size_t from) const
{
    return _l.bfs(from);
}

} // namespace W