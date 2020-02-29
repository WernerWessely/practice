
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
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

    SECTION("size() down to 1.")
    {
        v.push(1);
        v.push(1);
        v.pop();
        REQUIRE(1 == v.size());
    }

    SECTION("size() down to 0.")
    {
        v.push(1);
        v.push(1);
        v.pop();
        v.pop();
        REQUIRE(0 == v.size());
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

TEST_CASE("Test the reverse() function.", "[base]")
{
    W::wv v;

    SECTION("reverse() on empty.")
    {
        v.reverse();
        REQUIRE(v.empty());
    }

    SECTION("reverse() on 1.")
    {
        v.push(1);
        v.reverse();
        REQUIRE(1 == v.size());
        REQUIRE(1 == v.at(0));
    }

    SECTION("reverse() on 2.")
    {
        v.push(1);
        v.push(2);
        v.reverse();
        REQUIRE(2 == v.size());
        REQUIRE(2 == v.at(0));
        REQUIRE(1 == v.at(1));
    }

    SECTION("reverse() on 3.")
    {
        v.push(1);
        v.push(2);
        v.push(3);
        v.reverse();
        REQUIRE(3 == v.size());
        REQUIRE(3 == v.at(0));
        REQUIRE(2 == v.at(1));
        REQUIRE(1 == v.at(2));
    }

    SECTION("reverse() on 4.")
    {
        v.push(1);
        v.push(2);
        v.push(3);
        v.push(4);
        v.reverse();
        REQUIRE(4 == v.size());
        REQUIRE(4 == v.at(0));
        REQUIRE(3 == v.at(1));
        REQUIRE(2 == v.at(2));
        REQUIRE(1 == v.at(3));
    }
}