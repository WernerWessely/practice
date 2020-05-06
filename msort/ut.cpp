#include "msort.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <initializer_list>
#include <vector>

namespace w
{
    typedef std::vector<int> ser;

    // A sorted list for convenience
    class slist
    {
    public:
        explicit slist(std::initializer_list<int> init) : _root(nullptr)
        {
            for (auto v : init)
            {
                (_root ? _root->_next : _root) = new w::node(v);
            }

            w::msort(_root);
        }

        ~slist()
        {
            while (_root)
            {
                w::node *del = _root;
                _root = _root->_next;
                delete del;
            }
        }

        slist &operator=(const slist &other) = delete;
        slist(const slist &other) = delete;

        ser serial() const
        {
            std::vector<int> ret;

            for (w::node *cur = _root; cur; cur = cur->_next)
            {
                ret.push_back(cur->_val);
            }

            return ret;
        }

    private:
        w::node *_root;
    };
} // namespace w

TEST_CASE("test msort() with list.")
{
    SECTION("empty")
    {
        w::slist l{};

        REQUIRE(l.serial() == w::ser{});
    }

    SECTION("1")
    {
        w::slist l{1};

        REQUIRE(l.serial() == w::ser{1});
    }

    SECTION("2")
    {
        w::slist l{2, 1};

        REQUIRE(l.serial() == w::ser{1, 2});
    }
}
