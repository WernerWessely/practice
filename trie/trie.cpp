#include "trie.hpp"

namespace W
{

void trie::add(const std::string &key, unsigned val)
{
}

void trie::_add(trienp &ch, const std::string &key, size_t index, unsigned val)
{
    const char cur = key[index];

    if (cur < 'a' || cur > 'z')
    {
        throw std::out_of_range("");
    }

    if (!key[index + 1])
    {
        // End of the word.
        ch->_val = val;
    }
    else
    {
    }
}

} // namespace W