#include "mslist.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Test the sort() function")
{
    SECTION("Empty")
    {
        REQUIRE(W::mslist::ser{} == W::mslist{}.sort());
    }

    SECTION("1")
    {
        REQUIRE(W::mslist::ser{2} == W::mslist{2}.sort());
    }

    SECTION("2")
    {
        REQUIRE(W::mslist::ser{1, 2} == W::mslist{1, 2}.sort());
        REQUIRE(W::mslist::ser{1, 2} == W::mslist{2, 1}.sort());
    }

    SECTION("3")
    {
        REQUIRE(W::mslist::ser{1, 2, 3} == W::mslist{1, 2, 3}.sort());
        REQUIRE(W::mslist::ser{1, 2, 3} == W::mslist{3, 1, 2}.sort());
    }

    SECTION("7")
    {
        REQUIRE(W::mslist::ser{-12, -3, 0, 4, 100, 2345, 100000} == W::mslist{-12, -3, 0, 4, 100, 2345, 100000}.sort());
        REQUIRE(W::mslist::ser{-12, -3, 0, 4, 100, 2345, 100000} == W::mslist{-3, 100000, 4, -12, 2345, 0, 100}.sort());
    }
}