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

private:
    wv(const wv &other);
    wv operator=(const wv &other);
    std::unique_ptr<int[]> _mem;
    size_t _size = 0;
    size_t _capacity = 2;
    void realloc();
};
} // namespace W

#endif