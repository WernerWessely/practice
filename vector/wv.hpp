#ifndef _WV_H_
#define _WV_H_

#include <memory>

namespace W
{
class wv
{
public:
    // Ctor.
    wv();
    // Current number of elements.
    size_t size() const;
    // Get if empty.
    bool empty() const;
    // Get current capacity.
    size_t capacity() const;
    // Append to end of vector.
    void push(int value);
    // Get and remove last item.
    int pop();
    // Get value at index.
    int at(size_t index) const;
    // Insert at index.
    void insert(size_t index, int value);
    // Insert at beginning.
    void prepend(int value);
    // Remove with index.
    void remove(size_t index);
    // Reverse the vector.
    void reverse();

private:
    wv(const wv &other);
    wv operator=(const wv &other);
    void enlarge();
    std::unique_ptr<int[]> _mem;
    size_t _size = 0;
    size_t _capacity = 0;
};
} // namespace W

#endif