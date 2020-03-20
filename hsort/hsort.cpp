#include "hsort.hpp"

#include <algorithm>

namespace w
{

namespace
{

void siftup(int heap[], size_t index)
{
    while (index)
    {
        const auto parent = (index - 1) / 2;

        if (heap[parent] < heap[index])
        {
            std::swap(heap[parent], heap[index]);

            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapify(int arr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        siftup(arr, i);
    }
}

void siftdown(int heap[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        const size_t left = i * 2 + 1, right = i * 2 + 2;

        if (left < size)
        {
            // Child to possibly swap with:
            const auto child = right >= size || heap[right] <= heap[left] ? left : right;

            if (heap[child] > heap[i])
            {
                std::swap(heap[i], heap[child]);
                i = child;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void sort(int heap[], size_t size)
{
    for (size_t i = size; i-- > 0;)
    {
        std::swap(heap[0], heap[i]);
        siftdown(heap, i);
    }
}

} // namespace

void hsort(int arr[], size_t size)
{
    heapify(arr, size);
    sort(arr, size);
}

} // namespace w