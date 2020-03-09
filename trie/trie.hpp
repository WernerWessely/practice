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
    typedef std::shared_ptr<trie> triep;

    void _add(triep &cur, const std::string &key, size_t next, unsigned val);

    bool _end = false;
    unsigned _val = 0;
    size_t _nchildren = 0;
    std::array<triep, 'z' - 'a' + 1> _children;
};

} // namespace W

#endif