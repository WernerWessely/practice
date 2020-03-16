#include "qsort.hpp"

#include <algorithm>

namespace w
{

namespace
{

size_t partition(int arr[], size_t l, size_t h)
{
    auto firsthigh = l;

    for (auto i = l; i < h; ++i)
    {
        if (arr[i] < arr[h])
        {
            std::swap(arr[i], arr[firsthigh++]);
        }
    }

    std::swap(arr[firsthigh], arr[h]);

    return firsthigh;
}

} // namespace

void qsort(int arr[], size_t l, size_t h)
{
    if (l >= h)
    {
        // Sorted.
        return;
    }

    const size_t p = partition(arr, l, h);

    qsort(arr, l, p);
    qsort(arr, p + 1, h);
}

} // namespace w