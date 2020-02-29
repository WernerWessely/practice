
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "htable.hpp"

TEST_CASE("Test the add() function.")
{
    W::htable t;

    SECTION("add() 1.")
    {
        t.add("one", 1);
        REQUIRE(1 == t.size());
        REQUIRE(1 == t.get("one"));
        t.add("one", 2);
        REQUIRE(1 == t.size());
        REQUIRE(2 == t.get("one"));
    }

    SECTION("add() 2.")
    {
        t.add("one", 1);
        t.add("two", 2);
        REQUIRE(2 == t.size());
        REQUIRE(1 == t.get("one"));
        REQUIRE(2 == t.get("two"));
        t.add("one", 2);
        t.add("two", 1);
        REQUIRE(2 == t.size());
        REQUIRE(2 == t.get("one"));
        REQUIRE(1 == t.get("two"));
    }

    SECTION("add() 3.")
    {
        t.add("one", 1);
        t.add("two", 2);
        t.add("three", 3);
        REQUIRE(3 == t.size());
        REQUIRE(1 == t.get("one"));
        REQUIRE(2 == t.get("two"));
        REQUIRE(3 == t.get("three"));
        t.add("one", 3);
        t.add("two", 2);
        t.add("three", 1);
        REQUIRE(3 == t.get("one"));
        REQUIRE(2 == t.get("two"));
        REQUIRE(1 == t.get("three"));
    }
}

TEST_CASE("Test the get() function.")
{
    W::htable t;

    SECTION("get() non-existing")
    {
        REQUIRE_THROWS_AS(t.get("one"), std::out_of_range);
    }
}