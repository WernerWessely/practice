#include "deplist.hpp"
#include <queue>

namespace W
{

void deplist::add_edge(size_t from, size_t to, size_t weight)
{
    if (from >= _n || to >= _n || from == to)
    {
        throw std::out_of_range("");
    }

    _heads[from].reset(new adj(to, weight, _heads[from]));
}

std::vector<size_t> deplist::bfs(size_t from) const
{
    std::vector<size_t> ret;
    std::vector<bool> vis(_n);
    std::queue<size_t> next;

    next.push(from);

    while (!next.empty())
    {
        auto cur = next.front();

        for (adjp tmp = _heads[cur]; tmp; tmp = tmp->_next)
        {
            if (!vis[tmp->_to])
            {
                next.push(tmp->_to);
            }
        }

        next.pop();
        vis[cur] = true;
        ret.push_back(cur);
    }

    return ret;
}

} // namespace W