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
    if (from >= _n)
    {
        throw std::out_of_range("");
    }

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

std::vector<size_t> deplist::dfs(size_t from) const
{
    if (from >= _n)
    {
        throw std::out_of_range("");
    }

    std::vector<size_t> ret;
    std::vector<bool> vis(_n);

    _dfs(from, ret, vis);

    return ret;
}

void deplist::_dfs(size_t from, std::vector<size_t> &ret, std::vector<bool> &vis) const
{
    vis[from] = true;
    ret.push_back(from);

    for (auto tmp = _heads[from]; tmp; tmp = tmp->_next)
    {
        if (!vis[tmp->_to])
        {
            _dfs(tmp->_to, ret, vis);
        }
    }
}

} // namespace W