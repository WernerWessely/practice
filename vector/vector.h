#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory>

namespace w
{

// Dynamic array, first version using smart pointers.
class vector
{
public:
    int size() const;

    bool empty() const;

    int capacity() const;

    // Append to end.
    void push(int value);

    // Get and remove last item.
    int pop();

    // Get value at index.
    int at(int i) const;

    // Insert at index, index must be <= size.
    void insert(int i, int value);

    // Insert at index 0.
    void prepend(int value);

    // Get and remove at index.
    int remove(int i);

    void reverse();

private:
    int _size{};
    int _capacity{};
    typedef std::unique_ptr<int[]> memp;
    memp _mem{};

    void _enlarge();
};

} // namespace w

#endif