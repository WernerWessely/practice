#include "trie.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Test the add() function.")
{
    W::trie t;

    SECTION("add() empty string, exception.")
    {
        REQUIRE_THROWS_AS(t.add("", 1), std::out_of_range);
    }

    SECTION("add() 1.")
    {
        t.add("a", 1);
        REQUIRE(1 == t.size());
        REQUIRE(1 == t.get("a"));
    }

    SECTION("add() 2.")
    {
        t.add("a", 1);
        t.add("aa", 2);
        //REQUIRE(2 == t.size());
        //REQUIRE(1 == t.get("a"));
        //REQUIRE(2 == t.get("aa"));
    }
}