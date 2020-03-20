#include "bsort.hpp"

#include <algorithm>

namespace w
{

void bsort(int arr[], size_t size)
{
    auto end = size;

    while (end)
    {
        size_t newend = 0;

        for (size_t i = 1; i < end; ++i)
        {
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                newend = i;
            }
        }

        end = newend;
    }
}

} // namespace w