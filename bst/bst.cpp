#include "bst.hpp"

namespace W
{

void bst::_info(const bstnp &n, size_t d, size_t &dm, size_t &s) const
{
    if (n)
    {
        ++s;

        if (++d > dm)
        {
            dm = d;
        }

        _info(n->_l, d, dm, s);
        _info(n->_r, d, dm, s);
    }
}

size_t bst::depth() const
{
    size_t d = 0, s = 0;

    _info(_root, 0, d, s);

    return d;
}

size_t bst::size() const
{
    size_t d = 0, s = 0;

    _info(_root, 0, d, s);

    return s;
}

void bst::add(int key)
{
    if (key % 2)
    {
        _add(key);
    }
    else
    {
        _radd(_root, key);
    }
}

void bst::_radd(bstnp &n, int key)
{
    if (!n)
    {
        n.reset(new bstn(key));
    }
    else if (key == n->_key)
    {
        throw std::out_of_range("");
    }
    else
    {
        _radd(key < n->_key ? n->_l : n->_r, key);
    }
}

void bst::_add(int key)
{
    bstnp *dst = &_root;

    while (*dst)
    {
        if ((*dst)->_key == key)
        {
            throw std::out_of_range("");
        }

        dst = key < (*dst)->_key ? &(*dst)->_l : &(*dst)->_r;
    }

    dst->reset(new bstn(key));

    if (!_root)
    {
        _root = *dst;
    }
}

void bst::nlr(serial &ser) const
{
    _nlr(_root, ser);
}

void bst::_nlr(const bstnp &n, serial &ser) const
{
    if (n)
    {
        ser.push_back(n->_key);

        _nlr(n->_l, ser);

        _nlr(n->_r, ser);
    }
}

void bst::lnr(serial &ser) const
{
    _lnr(_root, ser);
}

void bst::_lnr(const bstnp &n, serial &ser) const
{
    if (n)
    {
        _lnr(n->_l, ser);

        ser.push_back(n->_key);

        _lnr(n->_r, ser);
    }
}

void bst::rnl(serial &ser) const
{
    _rnl(_root, ser);
}

void bst::_rnl(const bstnp &n, serial &ser) const
{
    if (n)
    {
        _rnl(n->_r, ser);

        ser.push_back(n->_key);

        _rnl(n->_l, ser);
    }
}

void bst::lrn(serial &ser) const
{
    _lrn(_root, ser);
}

void bst::_lrn(const bstnp &n, serial &ser) const
{
    if (n)
    {
        _lrn(n->_l, ser);

        _lrn(n->_r, ser);

        ser.push_back(n->_key);
    }
}

void bst::rem(int key)
{
    bstnp parent(nullptr);

    _rem(_root, parent, key);
}

bst::bstn *bst::_max(const bstnp &n, bstnp &par) const
{
    bstnp ret = n;

    for (; ret->_r; par = ret, ret = ret->_r)
        ;

    return ret.get();
}

void bst::_repl(bstnp &par, const bstnp &child, const bstnp &nchild)
{
    if (par)
    {
        if (par->_l == child)
        {
            par->_l = nchild;
        }
        else
        {
            par->_r = nchild;
        }
    }
    else
    {
        _root = nchild;
    }
}

void bst::_rem(bstnp &n, bstnp &p, int key)
{
    if (!n)
    {
        throw std::out_of_range("");
    }

    if (key < n->_key)
    {
        _rem(n->_l, n, key);
    }
    else if (key > n->_key)
    {
        _rem(n->_r, n, key);
    }
    else
    {
        if (n->_l && n->_r)
        {
            bstnp par(nullptr);
            bstnp pred(max(n->_l, par));
            n->_key = pred->_key;
            _rem(pred, par, key);
        }
        else
        {
            _repl(p, n, n->_l ? n->_l : n->_r);
        }
    }
}

void bst::bfs(serial &ser) const
{
    size_t level = 0;
    bool cont = false;

    do
    {
        cont = false;
        _bfs(_root, level++, cont, ser);
    } while (cont);
}

void bst::_bfs(const bstnp &cur, size_t level, bool &cont, serial &ser) const
{
    if (cur)
    {
        if (!level)
        {
            ser.push_back(cur->_key);

            cont |= (cur->_l || cur->_r);
        }
        else
        {

            _bfs(cur->_l, level - 1, cont, ser);
            _bfs(cur->_r, level - 1, cont, ser);
        }
    }
}

} // namespace W