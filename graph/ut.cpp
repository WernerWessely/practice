#include "graph.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

typedef std::vector<size_t> serial;

TEST_CASE("Test the graph::bfs() function")
{
    SECTION("No edges")
    {
        W::graph g(4);

        REQUIRE(serial{0} == g.bfs(0));
        REQUIRE(serial{3} == g.bfs(3));
        REQUIRE_THROWS_AS(g.bfs(4), std::out_of_range);
    }
/*
    SECTION("1 edge")
    {
        W::graph g(4);

        g.add_edge(0, 1, 10);
        REQUIRE(serial{1, 10} == g.bfs(1));
        REQUIRE(serial{10, 1} == g.bfs(10));
    }
    */
}