#ifndef _MSORT_H_
#define _MSORT_H_

namespace w
{

// On a list:
struct node
{
    node(int val, node *next = nullptr) : _val(val), _next(next) {}
    int _val;
    node *_next;
};

node *msort(node *l);

// On an array:
void msort(int arr[], int from, int to, int buffer[]);

} // namespace w

#endif