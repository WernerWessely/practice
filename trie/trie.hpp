#ifndef _TRIE_H_
#define _TRIE_H_

#include <memory>
#include <string>

namespace W
{

class trie
{
public:
    void add(const std::string &key, unsigned val);

    void rem(const std::string &key);

    unsigned get(const std::string &key);

    unsigned size() const;

private:
    struct trien;
    typedef std::shared_ptr<trien> trienp;
    struct trien
    {
        unsigned _val;
        trienp _children['z' - 'a' + 1];
    };

    void _add(trienp &ch, const std::string &key, size_t index, unsigned val);

    trien _root;
};

} // namespace W

#endif