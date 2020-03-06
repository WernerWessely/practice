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

    SECTION("1 edge")
    {
        W::graph g(4);

        g.add_edge(0, 1, 10);
        REQUIRE(serial{0, 1} == g.bfs(0));
        REQUIRE(serial{1, 0} == g.bfs(1));
    }

    SECTION("6 edges")
    {
        W::graph g(10);

        g.add_edge(4, 6, 1);
        g.add_edge(4, 2, 1);
        g.add_edge(2, 3, 1);
        g.add_edge(2, 1, 1);
        g.add_edge(6, 7, 1);
        g.add_edge(6, 5, 1);

        REQUIRE(serial{4, 2, 6, 1, 3, 5, 7} == g.bfs(4));
    }
}

TEST_CASE("Test the graph::dfs() function")
{
    SECTION("No edges")
    {
        W::graph g(4);

        REQUIRE(serial{0} == g.dfs(0));
        REQUIRE(serial{3} == g.dfs(3));
        REQUIRE_THROWS_AS(g.bfs(4), std::out_of_range);
    }

    SECTION("1 edge")
    {
        W::graph g(4);

        g.add_edge(0, 1, 10);
        REQUIRE(serial{0, 1} == g.dfs(0));
        REQUIRE(serial{1, 0} == g.dfs(1));
    }

    SECTION("6 edges")
    {
        W::graph g(10);

        g.add_edge(4, 6, 1);
        g.add_edge(4, 2, 1);
        g.add_edge(2, 3, 1);
        g.add_edge(2, 1, 1);
        g.add_edge(6, 7, 1);
        g.add_edge(6, 5, 1);

        REQUIRE(serial{4, 2, 1, 3, 6, 5, 7} == g.dfs(4));
    }
}