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

    void add(int key, const std::string &val);
    void rem(int key);

    size_t size() const;
    size_t depth() const;

    typedef std::vector<std::tuple<int, std::string>> serial;

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
        bstn(int key, const std::string &val) : _key(key),
                                                _val(val),
                                                _l(nullptr),
                                                _r(nullptr) {}
        int _key;
        std::string _val;
        bstnp _l, _r;
    };

    void _depth(const bstnp &n, size_t depth, size_t &mdepth) const;
    void _lnr(const bstnp &n, serial &ser) const;
    void _rnl(const bstnp &n, serial &ser) const;
    void _nlr(const bstnp &n, serial &ser) const;
    void _lrn(const bstnp &n, serial &ser) const;

    bstnp _root;
    size_t _size;
};
} // namespace W

#endif