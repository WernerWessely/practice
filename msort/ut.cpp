#include "msort.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>

TEST_CASE("Test the msort() function.")
{
    SECTION("Empty")
    {
        std::array<int, 3> arr{23, -1, 45}, buffer{}, cmp = arr;

        W::msort(arr.data(), 0, 0, buffer.data());

        REQUIRE(cmp == arr);
    }

    SECTION("1")
    {
        std::array<int, 3> arr{23}, buffer{}, cmp = arr;

        W::msort(arr.data(), 0, 1, buffer.data());

        REQUIRE(cmp == arr);
    }

    SECTION("2")
    {
        std::array<int, 3> arr{23, -1}, buffer{}, cmp{-1, 23};

        W::msort(arr.data(), 0, 2, buffer.data());

        REQUIRE(cmp == arr);
    }

    SECTION("3")
    {
        std::array<int, 3> arr{23, -1, 45}, buffer{}, cmp{-1, 23, 45};

        W::msort(arr.data(), 0, 2, buffer.data());

        REQUIRE(cmp == arr);
    }
}