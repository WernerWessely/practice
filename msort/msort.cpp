#include "msort.hpp"
#include <algorithm>

namespace W
{

namespace
{

void merge(int src[], size_t from, size_t middle, size_t to, int dst[])
{
    auto i = from, j = middle, k = from;

    while (i < middle)
    {
        // Make sure to stay stable -> first first on equal.
        // Compare as long as second is not finished, else
        // copy first.
        if (j < to && src[j] < src[i])
        {
            dst[k++] = src[j++];
        }
        else
        {
            dst[k++] = src[i++];
        }
    }

    // Finish second if theres any left.
    while (j < to)
    {
        dst[k++] = src[j++];
    }
}

void top_down_merge_sort(int src[], size_t from, size_t to, int dst[])
{
    if (to - from < 2)
    {
        return; // Array of size 1 is sorted.
    }

    size_t middle = (to + from) / 2;

    top_down_merge_sort(dst, from, middle, src);
    top_down_merge_sort(dst, middle, to, src);

    merge(src, from, middle, to, dst);
}

} // namespace

void msort(int arr[], size_t from, size_t to, int buffer[])
{
    std::copy(arr, arr + (to - from), buffer);

    top_down_merge_sort(buffer, from, to, arr);
}

} // namespace W