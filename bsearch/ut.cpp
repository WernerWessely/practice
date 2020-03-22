#include "bsearch.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>

TEST_CASE("Test the binary search.")
{
    SECTION("Empty")
    {
        std::array<int, 0> arr{};

        REQUIRE(-1 == w::bsearch(arr.data(), 1, 0, -1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 1, 0, -1));
    }

    SECTION("1")
    {
        std::array<int, 1> arr{1};

        REQUIRE(-1 == w::bsearch(arr.data(), 0, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 0, 0, arr.size() - 1));

        REQUIRE(0 == w::bsearch(arr.data(), 1, 0, arr.size() - 1));
        REQUIRE(0 == w::bsearchr(arr.data(), 1, 0, arr.size() - 1));

        REQUIRE(-1 == w::bsearch(arr.data(), 2, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 2, 0, arr.size() - 1));
    }

    SECTION("2")
    {
        std::array<int, 2> arr{1, 2};

        REQUIRE(-1 == w::bsearch(arr.data(), 0, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 0, 0, arr.size() - 1));

        REQUIRE(0 == w::bsearch(arr.data(), 1, 0, arr.size() - 1));
        REQUIRE(0 == w::bsearchr(arr.data(), 1, 0, arr.size() - 1));

        REQUIRE(1 == w::bsearch(arr.data(), 2, 0, arr.size() - 1));
        REQUIRE(1 == w::bsearchr(arr.data(), 2, 0, arr.size() - 1));

        REQUIRE(-1 == w::bsearch(arr.data(), 3, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 3, 0, arr.size() - 1));
    }

    SECTION("2 same")
    {
        std::array<int, 2> arr{2, 2};

        REQUIRE(-1 == w::bsearch(arr.data(), 1, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 1, 0, arr.size() - 1));

        REQUIRE(0 == w::bsearch(arr.data(), 2, 0, arr.size() - 1));
        REQUIRE(0 == w::bsearchr(arr.data(), 2, 0, arr.size() - 1));

        REQUIRE(-1 == w::bsearch(arr.data(), 3, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 3, 0, arr.size() - 1));
    }

    SECTION("3")
    {
        std::array<int, 3> arr{1, 2, 3};

        REQUIRE(-1 == w::bsearch(arr.data(), 0, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 0, 0, arr.size() - 1));

        REQUIRE(0 == w::bsearch(arr.data(), 1, 0, arr.size() - 1));
        REQUIRE(0 == w::bsearchr(arr.data(), 1, 0, arr.size() - 1));

        REQUIRE(1 == w::bsearch(arr.data(), 2, 0, arr.size() - 1));
        REQUIRE(1 == w::bsearchr(arr.data(), 2, 0, arr.size() - 1));

        REQUIRE(2 == w::bsearch(arr.data(), 3, 0, arr.size() - 1));
        REQUIRE(2 == w::bsearchr(arr.data(), 3, 0, arr.size() - 1));

        REQUIRE(-1 == w::bsearch(arr.data(), 4, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 4, 0, arr.size() - 1));
    }

    SECTION("Same same")
    {
        std::array<int, 10> arr{1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

        REQUIRE(-1 == w::bsearch(arr.data(), 0, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 0, 0, arr.size() - 1));

        REQUIRE(0 == w::bsearch(arr.data(), 1, 0, arr.size() - 1));
        REQUIRE(0 == w::bsearchr(arr.data(), 1, 0, arr.size() - 1));

        REQUIRE(1 == w::bsearch(arr.data(), 2, 0, arr.size() - 1));
        REQUIRE(1 == w::bsearchr(arr.data(), 2, 0, arr.size() - 1));

        REQUIRE(3 == w::bsearch(arr.data(), 3, 0, arr.size() - 1));
        REQUIRE(3 == w::bsearchr(arr.data(), 3, 0, arr.size() - 1));

        REQUIRE(6 == w::bsearch(arr.data(), 4, 0, arr.size() - 1));
        REQUIRE(6 == w::bsearchr(arr.data(), 4, 0, arr.size() - 1));

        REQUIRE(-1 == w::bsearch(arr.data(), 5, 0, arr.size() - 1));
        REQUIRE(-1 == w::bsearchr(arr.data(), 5, 0, arr.size() - 1));
    }
}