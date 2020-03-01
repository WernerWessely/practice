
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "bst.hpp"

TEST_CASE("Test the depth() and size() functions")
{
    W::bst t;

    SECTION("Empty.")
    {
        REQUIRE(0 == t.size());
        REQUIRE(0 == t.depth());
    }

    SECTION("1.")
    {
        t.add(1);
        REQUIRE(1 == t.size());
        REQUIRE(1 == t.depth());
    }

    SECTION("2.")
    {
        t.add(1);
        t.add(0);
        t.add(2);
        REQUIRE(3 == t.size());
        REQUIRE(2 == t.depth());
    }

    SECTION("5 list.")
    {
        t.add(1);
        t.add(2);
        t.add(3);
        t.add(4);
        t.add(5);
        REQUIRE(5 == t.size());
        REQUIRE(5 == t.depth());
    }

    SECTION("5 tree.")
    {
        t.add(3);
        t.add(2);
        t.add(5);
        t.add(1);
        t.add(4);
        REQUIRE(5 == t.size());
        REQUIRE(3 == t.depth());
    }
}

TEST_CASE("Test the DFS functions.")
{
    W::bst t;
    W::bst::serial nlr;
    W::bst::serial lnr;
    W::bst::serial rnl;
    W::bst::serial lrn;

    SECTION("Empty.")
    {
        t.nlr(nlr);
        t.lnr(lnr);
        t.rnl(rnl);
        t.lrn(lrn);

        REQUIRE(nlr == W::bst::serial({}));
        REQUIRE(lnr == W::bst::serial({}));
        REQUIRE(rnl == W::bst::serial({}));
        REQUIRE(lrn == W::bst::serial({}));
    }

    SECTION("1.")
    {
        t.add(1);

        t.nlr(nlr);
        t.lnr(lnr);
        t.rnl(rnl);
        t.lrn(lrn);

        REQUIRE(nlr == W::bst::serial({1}));
        REQUIRE(lnr == W::bst::serial({1}));
        REQUIRE(rnl == W::bst::serial({1}));
        REQUIRE(lrn == W::bst::serial({1}));
    }

    SECTION("3.")
    {
        t.add(2);
        t.add(1);
        t.add(3);

        t.nlr(nlr);
        t.lnr(lnr);
        t.rnl(rnl);
        t.lrn(lrn);

        REQUIRE(nlr == W::bst::serial({{2, 1, 3}}));
        REQUIRE(lnr == W::bst::serial({{1, 2, 3}}));
        REQUIRE(rnl == W::bst::serial({{3, 2, 1}}));
        REQUIRE(lrn == W::bst::serial({{1, 3, 2}}));
    }

    SECTION("5 list.")
    {
        t.add(1);
        t.add(2);
        t.add(3);
        t.add(4);
        t.add(5);

        t.nlr(nlr);
        t.lnr(lnr);
        t.rnl(rnl);
        t.lrn(lrn);

        REQUIRE(nlr == W::bst::serial({{1, 2, 3, 4, 5}}));
        REQUIRE(lnr == W::bst::serial({{1, 2, 3, 4, 5}}));
        REQUIRE(rnl == W::bst::serial({{5, 4, 3, 2, 1}}));
        REQUIRE(lrn == W::bst::serial({{5, 4, 3, 2, 1}}));
    }

    SECTION("5 tree.")
    {
        t.add(3);
        t.add(2);
        t.add(5);
        t.add(1);
        t.add(4);

        t.nlr(nlr);
        t.lnr(lnr);
        t.rnl(rnl);
        t.lrn(lrn);

        REQUIRE(nlr == W::bst::serial({{3, 2, 1, 5, 4}}));
        REQUIRE(lnr == W::bst::serial({{1, 2, 3, 4, 5}}));
        REQUIRE(rnl == W::bst::serial({{5, 4, 3, 2, 1}}));
        REQUIRE(lrn == W::bst::serial({{1, 2, 4, 5, 3}}));
    }
}

TEST_CASE("Test the rem() function.")
{
    W::bst t;
    W::bst::serial order;

    SECTION("Exc on empty.")
    {
        REQUIRE_THROWS_AS(t.rem(0), std::out_of_range);
    }

    SECTION("rem() on 1.")
    {
        t.add(1);

        REQUIRE_THROWS_AS(t.rem(0), std::out_of_range);
        t.rem(1);
        REQUIRE(0 == t.depth());
        REQUIRE(0 == t.size());
    }

    SECTION("rem() on 2.")
    {
        t.add(1);
        t.add(2);

        REQUIRE_THROWS_AS(t.rem(0), std::out_of_range);
        t.rem(1);
        REQUIRE(1 == t.depth());
        REQUIRE(1 == t.size());
        t.rem(2);
        REQUIRE(0 == t.depth());
        REQUIRE(0 == t.size());
    }

    SECTION("rem() on 3.")
    {
        t.add(2);
        t.add(3);
        t.add(1);

        REQUIRE_THROWS_AS(t.rem(0), std::out_of_range);

        t.rem(1);
        REQUIRE(2 == t.depth());
        REQUIRE(2 == t.size());
        t.lnr(order);
        REQUIRE(order == W::bst::serial({2, 3}));

        t.rem(2);
        REQUIRE(1 == t.depth());
        REQUIRE(1 == t.size());
        order.clear();
        t.lnr(order);
        REQUIRE(order == W::bst::serial({3}));

        t.rem(3);
        REQUIRE(0 == t.depth());
        REQUIRE(0 == t.size());
    }
}

TEST_CASE("Test the bfs() function.")
{
    W::bst t;
    W::bst::serial order;

    SECTION("Empty.")
    {
        t.bfs(order);
        REQUIRE(order == W::bst::serial({}));
    }

    SECTION("bfs() on 1.")
    {
        t.add(1);
        t.bfs(order);
        REQUIRE(order == W::bst::serial({1}));
    }

    SECTION("bfs() on 2.")
    {
        t.add(2);
        t.add(1);
        t.bfs(order);
        REQUIRE(order == W::bst::serial({2, 1}));
    }

    SECTION("bfs() on 3.")
    {
        t.add(2);
        t.add(1);
        t.add(3);
        t.bfs(order);
        REQUIRE(order == W::bst::serial({2, 1, 3}));
    }

    SECTION("bfs() on 3.")
    {
        t.add(1);
        t.add(2);
        t.add(3);
        t.add(4);
        t.bfs(order);
        REQUIRE(order == W::bst::serial({1, 2, 3, 4}));
    }

    SECTION("bfs() on 7.")
    {
        t.add(4);
        t.add(2);
        t.add(6);
        t.add(1);
        t.add(3);
        t.add(5);
        t.add(7);
        t.bfs(order);
        REQUIRE(order == W::bst::serial({4, 2, 6, 1, 3, 5, 7}));
    }
}

TEST_CASE("Test the bfsq() function.")
{
    W::bst t;
    W::bst::serial order;

    SECTION("Empty.")
    {
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({}));
    }

    SECTION("bfsq() on 1.")
    {
        t.add(1);
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({1}));
    }

    SECTION("bfsq() on 2.")
    {
        t.add(2);
        t.add(1);
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({2, 1}));
    }

    SECTION("bfsq() on 3.")
    {
        t.add(2);
        t.add(1);
        t.add(3);
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({2, 1, 3}));
    }

    SECTION("bfsq() on 3.")
    {
        t.add(1);
        t.add(2);
        t.add(3);
        t.add(4);
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({1, 2, 3, 4}));
    }

    SECTION("bfsq() on 7.")
    {
        t.add(4);
        t.add(2);
        t.add(6);
        t.add(1);
        t.add(3);
        t.add(5);
        t.add(7);
        t.bfsq(order);
        REQUIRE(order == W::bst::serial({4, 2, 6, 1, 3, 5, 7}));
    }
}
