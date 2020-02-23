#include "bst.hpp"

namespace W
{

void bst::_depth(const bstnp &n, size_t depth, size_t &mdepth) const
{
    if (n)
    {
        if (++depth > mdepth)
        {
            mdepth = depth;
        }

        _depth(n->_l, depth, mdepth);
        _depth(n->_r, depth, mdepth);
    }
}

size_t bst::depth() const
{
    size_t ret;

    _depth(_root, 0, ret);

    return ret;
}

void bst::_lnr(const bstnp &n, serial &ser) const
{
    if (n)
    {
        _lnr(n->_l, ser);

        ser.push_back(std::tuple<int, std::string>(n->_key, n->_val));

        _lnr(n->_r, ser);
    }
}

void bst::lnr(serial &ser) const
{
    _lnr(_root, ser);
}

void bst::add(int key, const std::string &val)
{
    bstnp cur = _root;

    while (cur)
    {
        if (key < cur->_key)
        {
            if (cur->_l)
            {
                cur = cur->_l;
            }
            else
            {
                cur->_l.reset(new bstn(key, val));
                ++_size;
                break;
            }
        }
        else if (key > cur->_key)
        {
            if (cur->_r)
            {
                cur = cur->_r;
            }
            else
            {
                cur->_r.reset(new bstn(key, val));
                ++_size;
                break;
            }
        }
        else
        {
            // Replace.
            cur->_val = val;
            break;
        }
    }

    if (!cur)
    {
        // Empty.
        _root.reset(new bstn(key, val));
        ++_size;
    }
}
} // namespace W