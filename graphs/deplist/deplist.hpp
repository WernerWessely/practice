#ifndef _DEPLIST_H_
#define _DEPLIST_H_

#include <cstddef>
#include <memory>

namespace W
{
class deplist
{
public:
    deplist(size_t n) : _n(n), _visits(0), _heads(new adjp[n]) {}

    void add_edge(size_t from, size_t to, size_t weight);

private:
    struct adj;
    typedef std::shared_ptr<adj> adjp;
    struct adj
    {
        adj(size_t to, size_t weight, const adjp &next) : _to(to),
                                                          _visits(0),
                                                          _weight(weight),
                                                          _next(next) {}
        size_t _to, _visits, _weight;
        adjp _next;
    };
    size_t _n, _visits;
    std::unique_ptr<adjp[]> _heads;
};
} // namespace W

#endif