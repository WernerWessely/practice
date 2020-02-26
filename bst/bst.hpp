#ifndef _BST_H_
#define _BST_H_

#include <cstddef>
#include <memory>
#include <vector>
#include <tuple>

namespace W
{
class bst
{
public:
    bst() = default;
    ~bst() = default;

    bst(const bst &other) = delete;
    bst &operator=(const bst &other) = delete;

    void add(int key);
    void rem(int key);

    size_t size() const;
    size_t depth() const;

    typedef std::vector<int> serial;

    //dfs - depth first search:
    //pre-order - nlr
    void nlr(serial &ser) const;
    //in-order - lnr
    void lnr(serial &ser) const;
    //reverse-order - rnl
    void rnl(serial &ser) const;
    //post-order - lrn
    void lrn(serial &ser) const;

    //bfs - breadth first search - non-queue.
    void bfs(serial &ser) const;

private:
    struct bstn;
    typedef std::shared_ptr<bstn> bstnp;
    struct bstn
    {
        bstn(int key) : _key(key),
                        _l(nullptr),
                        _r(nullptr) {}
        int _key;
        bstnp _l, _r;
    };

    void _info(const bstnp &n, size_t d, size_t &dm, size_t &s) const;
    void _add(int key);
    void _radd(bstnp &n, int key);
    void _lnr(const bstnp &n, serial &ser) const;
    void _rnl(const bstnp &n, serial &ser) const;
    void _nlr(const bstnp &n, serial &ser) const;
    void _lrn(const bstnp &n, serial &ser) const;
    void _rrem(int key, bstnp &src, bstnp &dst);

    bstnp _root = nullptr;
};
} // namespace W

#endif