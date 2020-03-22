#include "bsearch.hpp"

namespace w
{

int bsearch(int arr[], int key, int from, int to)
{
    while (to >= from)
    {
        int middle = (from + to) / 2;

        if (arr[middle] > key)
        {
            to = middle - 1;
        }
        else if (arr[middle] < key)
        {
            from = middle + 1;
        }
        else if (from != to)
        {
            // We want the first match.
            to = middle;
        }
        else
        {
            return middle;
        }
    }

    return -1; // Not found.
}

int bsearchr(int arr[], int key, int from, int to)
{
    if (from > to)
    {
        return -1; // Not found.
    }

    int middle = (from + to) / 2;

    if (arr[middle] > key)
    {
        return bsearchr(arr, key, from, middle - 1);
    }

    if (arr[middle] < key)
    {
        return bsearchr(arr, key, middle + 1, to);
    }

    if (from != to)
    {
        // We want the first match.
        return bsearchr(arr, key, from, middle);
    }

    return middle;
}

} // namespace w