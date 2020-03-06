#ifndef _DEPLIST_H_
#define _DEPLIST_H_

#include <cstddef>
#include <memory>
#include <vector>

namespace W
{
class deplist
{
public:
    deplist(size_t n) : _n(n), _heads(new adjp[n]) {}

    void add_edge(size_t from, size_t to, size_t weight);

    std::vector<size_t> bfs(size_t from) const;

    std::vector<size_t> dfs(size_t from) const;

private:
    struct adj;
    typedef std::shared_ptr<adj> adjp;
    struct adj
    {
        adj(size_t to, size_t weight, const adjp &next) : _to(to),
                                                          _weight(weight),
                                                          _next(next) {}
        size_t _to, _weight;
        adjp _next;
    };

    size_t _n;
    std::unique_ptr<adjp[]> _heads;

    void _dfs(size_t from, std::vector<size_t> &ret, std::vector<bool> &vis) const;
};
} // namespace W

#endif