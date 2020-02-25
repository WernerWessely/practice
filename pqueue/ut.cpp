
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "pqueue.hpp"

TEST_CASE("Test the height() function.")
{
    W::pqueue q;

    SECTION("height() 0 after construction.")
    {
        REQUIRE(0 == q.height());
    }
}

TEST_CASE("Test the push() function.")
{
    W::pqueue q;

    SECTION("push() 1.")
    {
        q.push(1);
        REQUIRE(1 == q.size());
        REQUIRE(1 == q.height());
        REQUIRE(1 == q.pop());
        REQUIRE(0 == q.size());
        REQUIRE(0 == q.height());
    }

    SECTION("push() 2.")
    {
        q.push(1);
        q.push(2);

        REQUIRE(2 == q.size());
        REQUIRE(2 == q.height());

        REQUIRE(2 == q.pop());
        REQUIRE(1 == q.size());
        REQUIRE(1 == q.height());
        /*
        REQUIRE(1 == q.pop());
        REQUIRE(0 == q.size());
        REQUIRE(0 == q.height());
        */
    }
}