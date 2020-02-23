#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <cstddef>
#include <memory>
#include <vector>

namespace W
{
class pqueue
{
public:
    pqueue() = default;
    ~pqueue() = default;

    pqueue(const pqueue &other) = delete;
    pqueue &operator=(const pqueue &other) = delete;

    size_t height() const;
    size_t size() const;

    void push(size_t prio);
    size_t pop();

private:
    std::vector<size_t> _mem;
};
} // namespace W

#endif