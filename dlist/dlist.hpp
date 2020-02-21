#ifndef _DLIST_H_
#define _DLIST_H_

#include <cstddef>

namespace W
{
class dlist
{
public:
    dlist() = default;
    ~dlist();

    dlist(const dlist &other) = delete;
    dlist &operator=(const dlist &other) = delete;

    // Get length.
    size_t len() const;
    // Get if empty.
    bool empty() const;
    // Insert item at front.
    void prepend(int value);
    // Insert at back.
    void append(int value);
    // Get with index.
    int at(size_t index) const;
    // Get value at front.
    int front() const;
    // Get value at back.
    int back() const;
    // Get and remove from front.
    int pop_front();
    // Get and remove from back.
    int pop_back();
    // Insert at index.
    void insert(size_t index, int value);
    // Remove at index.
    void remove(size_t index);
    // Get reverse nth from end (non-recursive).
    int backn(size_t n) const;
    // Get reverse nth from end (recursive).
    int backnr(size_t n) const;
    // Reverse the list.
    void reverse();

private:
    struct dnode
    {
        dnode(dnode *prev, dnode *next, int val) : _prev(prev), _next(next), _val(val) {}
        dnode *_prev;
        dnode *_next;
        int _val;
    };

    int _backnr(size_t &i, size_t n, const dnode *node) const;

    dnode *_first = nullptr;
    dnode *_last = nullptr;
};
} // namespace W

#endif