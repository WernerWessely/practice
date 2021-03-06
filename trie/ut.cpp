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
        t.add("aaa", 3);
        REQUIRE(3 == t.size());
        REQUIRE(1 == t.get("a"));
        REQUIRE(2 == t.get("aa"));
        REQUIRE(3 == t.get("aaa"));
    }

    SECTION("add() 5.")
    {
        t.add("hello", 0);
        t.add("how", 2);
        t.add("are", 1);
        t.add("you", 5);
        t.add("today", 4);

        REQUIRE(5 == t.size());

        REQUIRE(0 == t.get("hello"));
        REQUIRE(2 == t.get("how"));
        REQUIRE(1 == t.get("are"));
        REQUIRE(5 == t.get("you"));
        REQUIRE(4 == t.get("today"));
    }
}

TEST_CASE("Test the rem() function.")
{
    W::trie t;

    SECTION("Exc on rem() invalid")
    {
        REQUIRE_THROWS_AS(t.rem("4"), std::out_of_range);
    }

    SECTION("Exc on rem() invalid empty")
    {
        REQUIRE_THROWS_AS(t.rem("a"), std::out_of_range);
    }

    SECTION("Exc on rem() substr")
    {
        t.add("hello", 1);
        REQUIRE_THROWS_AS(t.rem("hell"), std::out_of_range);
    }

    SECTION("rem() 1")
    {
        t.add("hello", 1);
        t.rem("hello");
        REQUIRE(0 == t.size());
    }

    SECTION("rem() substr")
    {
        t.add("hellothere", 1);
        t.add("hello", 2);

        t.rem("hello");

        REQUIRE(1 == t.size());
        REQUIRE(1 == t.get("hellothere"));

        t.add("hello", 2);
        t.rem("hellothere");

        REQUIRE(1 == t.size());
        REQUIRE(2 == t.get("hello"));

        t.rem("hello");
        REQUIRE(0 == t.size());
    }
}