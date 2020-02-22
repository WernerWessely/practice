#ifndef _HTABLE_H_
#define _HTABLE_H_

#include <cstddef>
#include <string>
#include <memory>

namespace W
{
class htable
{
public:
    htable() = default;
    ~htable() = default;

    htable(const htable &other) = delete;
    htable &operator=(const htable &other) = delete;

    // Get number of elements.
    size_t size() const;

    // Add element to table.
    void add(const std::string &key, int val);

    // Remove from table.
    void remove(const std::string &key);

    // Get with key.
    int get(const std::string &key) const;

private:
    struct hentry;
    typedef std::shared_ptr<hentry> helem;
    typedef std::unique_ptr<helem[]> htab;

    struct hentry
    {
        hentry(const std::string &key, int val, hentry *next) : _key(key),
                                                                _val(val),
                                                                _next(next) {}
        std::string _key;
        int _val;
        helem _next;
    };

    htab _tab = nullptr;
    size_t _cap = 0;
    size_t _size = 0;
    size_t _bucks = 0;

    size_t _index(const std::string &key) const;
    void _insert(htab &tab, const std::string &key, int val);
};

} // namespace W

#endif