#include "qsort.hpp"

#include <algorithm>

namespace w
{

namespace
{

size_t partition(int arr[], size_t begin, size_t end)
{
    auto firsthigh = begin;

    for (auto i = begin; i < end - 1; ++i)
    {
        if (arr[i] < arr[end - 1])
        {
            std::swap(arr[i], arr[firsthigh++]);
        }
    }

    std::swap(arr[firsthigh], arr[end - 1]);

    return firsthigh;
}

} // namespace

void qsort(int arr[], size_t begin, size_t end)
{
    if (end - begin < 2)
    {
        // Sorted.
        return;
    }

    const size_t p = partition(arr, begin, end);

    qsort(arr, begin, p);
    qsort(arr, p + 1, end);
}

} // namespace w