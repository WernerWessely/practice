
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "slist.hpp"

TEST_CASE("Test append()")
{
    w::slist l;

    SECTION("append() 1")
    {
        REQUIRE(0 == l.len());
        REQUIRE(l.empty());

        l.append(1);

        REQUIRE(1 == l.at(0));
        REQUIRE(1 == l.len());
        REQUIRE(!l.empty());
    }

    SECTION("append() 2")
    {
        REQUIRE(0 == l.len());
        REQUIRE(l.empty());

        l.append(1);
        l.append(2);

        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
        REQUIRE(2 == l.len());
        REQUIRE(!l.empty());
    }
}

TEST_CASE("Test prepend()")
{
    w::slist l;

    SECTION("prepend() 1")
    {
        REQUIRE(0 == l.len());
        REQUIRE(l.empty());

        l.prepend(1);

        REQUIRE(1 == l.at(0));
        REQUIRE(1 == l.len());
        REQUIRE(!l.empty());
    }

    SECTION("prepend() 2")
    {
        REQUIRE(0 == l.len());
        REQUIRE(l.empty());

        l.prepend(1);
        l.prepend(2);

        REQUIRE(2 == l.at(0));
        REQUIRE(1 == l.at(1));
        REQUIRE(2 == l.len());
        REQUIRE(!l.empty());
    }
}