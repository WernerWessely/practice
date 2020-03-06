#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "deplist.hpp"

namespace W
{
class graph
{
public:
    graph(size_t n) : _l(n) {}

    void add_edge(size_t from, size_t to, size_t weight);

    std::vector<size_t> bfs(size_t from) const;

    std::vector<size_t> dfs(size_t from) const;

private:
    deplist _l;
};
} // namespace W

#endif