
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "slist.hpp"

TEST_CASE("Test the len() function.", "[base]")
{
    W::slist l;

    SECTION("len() is 0 after construction")
    {
        REQUIRE(0 == l.len());
    }
}

TEST_CASE("Test the empty() function.", "[base]")
{
    W::slist l;

    SECTION("empty() is true after construction")
    {
        REQUIRE(l.empty());
    }
}

TEST_CASE("Test the insert() function.", "[base]")
{
    W::slist l;

    SECTION("insert() at index 0 with empty.")
    {
        l.insert(0, 1);
        REQUIRE(1 == l.at(0));
    }

    SECTION("insert() at index 1 with 1.")
    {
        l.insert(0, 1);
        l.insert(1, 2);
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
    }
}