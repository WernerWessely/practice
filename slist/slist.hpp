#ifndef _SLIST_H_
#define _SLIST_H_

namespace W
{
class slist
{
public:
    slist() = default;
    ~slist();

    slist(const slist &other) = delete;
    slist &operator=(const slist &other) = delete;

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
    // Get reverse nth from end.
    int rbackn(size_t n) const;
    // Reverse the list.
    void reverse();

private:
    struct snode
    {
        snode(int val, snode *next) : _val(val),
                                      _next(next) {}

        int _val;
        snode *_next;
    };

    snode *_first = nullptr;
};
} // namespace W

#endif