#ifndef _MSLIST_H_
#define _MSLIST_H_

#include <cstddef>
#include <memory>
#include <vector>
#include <initializer_list>

namespace W
{

class mslist
{
public:
    mslist() = default;
    mslist(std::initializer_list<int> vals);

    typedef std::vector<int> ser;
    ser sort();

private:
    struct mslistn;
    typedef std::shared_ptr<mslistn> mslistnp;
    struct mslistn
    {
        mslistn(int val) : _val(val), _next(nullptr) {}
        int _val;
        mslistnp _next;
    };

    void _merge(const mslistn *left, const mslistn *right);
    void _sort(size_t size);
    void _add(int val);

    mslistnp _root{};
};

} // namespace W

#endif