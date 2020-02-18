
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "wv.hpp"

TEST_CASE("Test the size() function.", "[base]")
{
    W::wv v;

    SECTION("size() is 0 after construction.")
    {
        REQUIRE(0 == v.size());
    }

    SECTION("size() is 1.")
    {
        v.push(1);
        REQUIRE(1 == v.size());
    }

    SECTION("size() is 2.")
    {
        v.push(1);
        v.push(1);
        REQUIRE(2 == v.size());
    }
}

TEST_CASE("Test the empty() function.", "[base]")
{
    W::wv v;

    SECTION("empty() is true after construction.")
    {
        REQUIRE(v.empty());
    }

    SECTION("empty() is false after push")
    {
        v.push(1);
        REQUIRE(!v.empty());
    }

    SECTION("empty() is true after pop")
    {
        v.push(1);
        v.pop();
        REQUIRE(v.empty());
    }
}