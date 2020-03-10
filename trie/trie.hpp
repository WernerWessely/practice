#ifndef _TRIE_H_
#define _TRIE_H_

#include <memory>
#include <string>
#include <array>

namespace W
{

class trie
{
public:
    void add(const std::string &key, unsigned val);

    void rem(const std::string &key);

    unsigned get(const std::string &key) const;

    size_t size() const;

private:
    struct trien;
    typedef std::shared_ptr<trien> trienp;
    typedef std::array<trienp, 'z' - 'a' + 1> trienpa;
    struct trien
    {
        unsigned _val = 0;
        bool _end = false;
        size_t _nchildren;
        trienpa _children;
    };

    void _add(trienp &ch, const std::string &key, size_t next, unsigned val);
    void _rem(trienp &ch, const std::string &key, size_t next);
    struct sizor
    {
        size_t _size = 0;
        void operator()(const trienp &p);
    };

    trienpa _roots;
};

} // namespace W

#endif