#ifndef _SLIST_H_
#define _SLIST_H_

#include <cstddef>

namespace w
{
class slist
{
public:
    slist();
    ~slist();

    slist(const slist &other) = delete;
    slist &operator=(const slist &other) = delete;

    // Get length.
    int len() const;
    // Get if empty.
    bool empty() const;
    // Insert item at front.
    void prepend(int val);
    // Insert at back.
    void append(int val);

#if 0
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
#endif

private:
    struct slistn
    {
        slistn(int val, slistn *next = nullptr) : _val(val), _next(next) {}
        int _val;
        slistn *_next;
    };

    slistn *_root;
};

} // namespace w

#endif