#include "mslist.hpp"

#include <algorithm>

namespace W
{

mslist::mslist(std::initializer_list<int> vals)
{
    auto dst = &_root;

    std::for_each(vals.begin(), vals.end(), [&](int val) {
        dst->reset(new mslistn{val});
        dst = &(*dst)->_next;
    });
}

void mslist::_add(int val)
{
    mslistnp *dst = &_root;

    for (; *dst; dst = &(*dst)->_next)
        ;

    dst->reset(new mslistn(val));
}

void mslist::_merge(const mslistn *left, const mslistn *right)
{
    mslistn *cur = _root.get();

    while (left || right)
    {
        if (right && (!left || right->_val < left->_val))
        {
            cur->_val = right->_val;
            right = right->_next.get();
        }
        else
        {
            cur->_val = left->_val;
            left = left->_next.get();
        }

        cur = cur->_next.get();
    }
}

void mslist::_sort(size_t size)
{
    if (size < 2)
    {
        // Sorted.
        return;
    }

    mslist left, right;
    const size_t left_size = size & 1 ? size / 2 + 1 : size / 2, right_size = size / 2;
    const mslistn *src = _root.get();

    for (size_t i = 0; i < size; src = src->_next.get(), ++i)
    {
        if (i < left_size)
        {
            left._add(src->_val);
        }
        else
        {
            right._add(src->_val);
        }
    }

    left._sort(left_size);
    right._sort(right_size);

    _merge(left._root.get(), right._root.get());
}

mslist::ser mslist::sort()
{
    // Get size once.
    size_t size = 0;

    for (auto cur = _root.get(); cur; cur = cur->_next.get(), ++size)
        ;

    _sort(size);

    ser ret;

    for (auto cur = _root.get(); cur; cur = cur->_next.get())
    {
        ret.push_back(cur->_val);
    }

    return ret;
}

} // namespace W