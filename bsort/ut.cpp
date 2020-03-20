#include "bsort.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Test the bsort() function.")
{
    SECTION("Empty")
    {
        std::array<int, 0> arr{}, cmp{};

        w::bsort(arr.data(), arr.size());

        REQUIRE(cmp == arr);
    }

    SECTION("1")
    {
        std::array<int, 1> arr{23}, cmp = arr;

        w::bsort(arr.data(), arr.size());

        REQUIRE(cmp == arr);
    }

    SECTION("2")
    {
        std::array<int, 2> arr{23, -1}, cmp{-1, 23};

        w::bsort(arr.data(), arr.size());

        REQUIRE(cmp == arr);
    }

    SECTION("3")
    {
        std::array<int, 3> arr{23, -1, 45}, cmp{-1, 23, 45};

        w::bsort(arr.data(), arr.size());

        REQUIRE(cmp == arr);
    }

    SECTION("7")
    {
        std::array<int, 7> arr{-3, 100000, 4, -12, 2345, 0, 100}, cmp{-12, -3, 0, 4, 100, 2345, 100000};

        w::bsort(arr.data(), arr.size());

        REQUIRE(cmp == arr);
    }
}