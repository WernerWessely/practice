
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dlist.hpp"

TEST_CASE("Test the len() function.", "[base]")
{
    W::dlist l;

    SECTION("len() is 0 after construction")
    {
        REQUIRE(0 == l.len());
    }
}

TEST_CASE("Test the empty() function.", "[base]")
{
    W::dlist l;

    SECTION("empty() is true after construction")
    {
        REQUIRE(l.empty());
    }
}

TEST_CASE("Test the insert() function.", "[base]")
{
    W::dlist l;

    SECTION("insert() at index 0 with empty.")
    {
        l.insert(0, 1);
        REQUIRE(1 == l.at(0));
    }

    SECTION("Exc for insert() at index 1 with empty.")
    {
        REQUIRE_THROWS_AS(l.insert(1, 1), std::out_of_range);
    }

    SECTION("insert() at index 1 with 1.")
    {
        l.insert(0, 1);
        l.insert(1, 2);
        REQUIRE(2 == l.len());
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
    }

    SECTION("insert() at index 0 with 2.")
    {
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(0, 3);
        REQUIRE(3 == l.len());
        REQUIRE(3 == l.at(0));
        REQUIRE(1 == l.at(1));
        REQUIRE(2 == l.at(2));
    }

    SECTION("Exc for insert() at index 4 with 3.")
    {
        l.insert(0, 1);
        l.insert(0, 1);
        l.insert(0, 1);
        REQUIRE(3 == l.len());
        REQUIRE_THROWS_AS(l.insert(4, 1), std::out_of_range);
    }
}

TEST_CASE("Test the append() function.", "[base]")
{
    W::dlist l;

    SECTION("append() on empty.")
    {
        l.append(1);
        REQUIRE(1 == l.at(0));
    }

    SECTION("append() 3 values.")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
        REQUIRE(3 == l.at(2));
    }
}

TEST_CASE("Test the front() function.", "[base]")
{
    W::dlist l;

    SECTION("Exc for front() on empty.")
    {
        REQUIRE_THROWS_AS(l.front(), std::out_of_range);
    }

    SECTION("front() for 1.")
    {
        l.append(1);
        REQUIRE(1 == l.front());
    }

    SECTION("front() for 2.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(2 == l.front());
    }
}

TEST_CASE("Test the back() function.", "[base]")
{
    W::dlist l;

    SECTION("Exc for back() on empty.")
    {
        REQUIRE_THROWS_AS(l.back(), std::out_of_range);
    }

    SECTION("back() for 1.")
    {
        l.append(1);
        REQUIRE(1 == l.back());
    }

    SECTION("back() for 2.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(1 == l.back());
    }
}
