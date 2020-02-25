
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

        REQUIRE(1 == q.pop());
        REQUIRE(0 == q.size());
        REQUIRE(0 == q.height());
    }

    SECTION("push() 3.")
    {
        q.push(3);
        q.push(1);
        q.push(2);

        REQUIRE(3 == q.size());
        REQUIRE(2 == q.height());

        REQUIRE(3 == q.pop());
        REQUIRE(2 == q.size());
        REQUIRE(2 == q.height());

        REQUIRE(2 == q.pop());
        REQUIRE(1 == q.size());
        REQUIRE(1 == q.height());

        REQUIRE(1 == q.pop());
        REQUIRE(0 == q.size());
        REQUIRE(0 == q.height());
    }

    SECTION("push() some.")
    {
        q.push(3);
        q.push(23);
        q.push(100);
        q.push(1);
        q.push(0);
        q.push(56);
        q.push(12);

        REQUIRE(7 == q.size());
        REQUIRE(3 == q.height());

        REQUIRE(100 == q.pop());
        REQUIRE(56 == q.pop());
        REQUIRE(23 == q.pop());
        REQUIRE(12 == q.pop());
        REQUIRE(3 == q.pop());
        REQUIRE(1 == q.pop());
        REQUIRE(0 == q.pop());
        REQUIRE_THROWS_AS(q.pop(), std::out_of_range);
    }
}