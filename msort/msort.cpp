#include "msort.hpp"

namespace w
{

    namespace
    {
        int len(node *l)
        {
            int n = 0;

            for (; l; l = l->_next, ++n)
                ;

            return n;
        }

        node *split(node *l)
        {
            const int n = len(l);

            if (n > 1)
            {
                node *cur = l;

                for (int i = 0;; cur = cur->_next, ++i)
                {
                    if (i == n / 2)
                    {
                        // Detach second half of list and return
                        node *ret = cur->_next;
                        cur->_next = nullptr;
                        return ret;
                    }
                }
            }

            return nullptr;
        }

        void append(node *&start, node *&end, node *l)
        {
            if (!start)
            {
                start = l;
            }
            else
            {
                end->_next = l;
            }

            end = l;
        }

        node *merge(node *l1, node *l2)
        {
            node *ret = nullptr, *end = nullptr;

            while (l1 && l2)
            {
                node *&next = l1->_val <= l2->_val ? l1 : l2;

                append(ret, end, next);
                next = next->_next;
            }

            append(ret, end, l1 ? l1 : l2);

            return ret;
        }

    } // namespace

    node *msort(node *l)
    {
        node *first = l, *second = split(first);

        if (!second)
        {
            // Base case
            return first;
        }

        msort(first);
        msort(second);

        return merge(first, second);
    }
} // namespace w