#include "qsort.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>

TEST_CASE("Test the qsort() function.")
{
    SECTION("Empty")
    {
        std::array<int, 3> arr{23, -1, 45}, cmp = arr;

        w::qsort(arr.data(), 0, 0);

        REQUIRE(cmp == arr);
    }

    SECTION("1")
    {
        std::array<int, 1> arr{23}, cmp = arr;

        w::qsort(arr.data(), 0, 0);

        REQUIRE(cmp == arr);
    }

    SECTION("2")
    {
        std::array<int, 2> arr{23, -1}, cmp{-1, 23};

        w::qsort(arr.data(), 0, 1);

        REQUIRE(cmp == arr);
    }

    SECTION("3")
    {
        std::array<int, 3> arr{23, -1, 45}, cmp{-1, 23, 45};

        w::qsort(arr.data(), 0, 2);

        REQUIRE(cmp == arr);
    }
}