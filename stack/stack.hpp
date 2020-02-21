#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>
#include <memory>

namespace W
{
class stack
{
public:
    stack() = default;
    ~stack() = default;
    stack(const stack &other) = delete;
    stack &operator=(const stack &other) = delete;

    size_t size() const;
    bool empty() const;

    int top() const;

    void push(int val);
    int pop();

private:
    std::unique_ptr<int[]> _mem = nullptr;
    size_t _size = 0;
    size_t _capa = 0;
};
} // namespace W

#endif