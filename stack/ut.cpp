
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "stack.hpp"

TEST_CASE("Test the size() function")
{
    W::stack s;

    SECTION("size() 0 after construction")
    {
        REQUIRE(0 == s.size());
    }

    SECTION("size() on 1")
    {
        s.push(1);
        REQUIRE(1 == s.size());
    }

    SECTION("size() on 2")
    {
        s.push(1);
        REQUIRE(1 == s.size());
    }
}

TEST_CASE("Test the empty() function.")
{
    W::stack s;

    SECTION("true on empty.")
    {
        REQUIRE(s.empty());
    }

    SECTION("false on 1.")
    {
        s.push(1);
        REQUIRE(!s.empty());
    }
}

TEST_CASE("Test the push() function.")
{
    W::stack s;

    SECTION("push() 1.")
    {
        s.push(1);
        REQUIRE(1 == s.top());
        REQUIRE(1 == s.pop());
        REQUIRE(s.empty());
    }

    SECTION("push() 3.")
    {
        s.push(1);
        s.push(2);
        s.push(3);
        REQUIRE(3 == s.size());
        REQUIRE(3 == s.top());
        REQUIRE(3 == s.pop());
        REQUIRE(2 == s.size());
        REQUIRE(2 == s.top());
        REQUIRE(2 == s.pop());
        REQUIRE(1 == s.size());
        REQUIRE(1 == s.top());
        REQUIRE(1 == s.pop());
        REQUIRE(s.empty());
    }
}