
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "slist.hpp"

TEST_CASE("Test the len() function.", "[base]")
{
    W::slist l;

    SECTION("len() is 0 after construction")
    {
        REQUIRE(0 == l.len());
    }
}

TEST_CASE("Test the empty() function.", "[base]")
{
    W::slist l;

    SECTION("empty() is true after construction")
    {
        REQUIRE(l.empty());
    }
}

TEST_CASE("Test the at() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for get() on empty.")
    {
        REQUIRE_THROWS_AS(l.at(0), std::out_of_range);
        REQUIRE_THROWS_AS(l.at(1), std::out_of_range);
    }
}

TEST_CASE("Test the insert() function.", "[base]")
{
    W::slist l;

    SECTION("insert() at index 0 with empty.")
    {
        l.insert(0, 1);
        REQUIRE(1 == l.at(0));
    }

    SECTION("Exc for insert() at index 1 with empty.")
    {
        REQUIRE_THROWS_AS(l.insert(1, 1), std::out_of_range);
    }

    SECTION("insert() at index 1 with 1.")
    {
        l.insert(0, 1);
        l.insert(1, 2);
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
    }

    SECTION("insert() at index 0 with 2.")
    {
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(0, 3);
        REQUIRE(3 == l.at(0));
        REQUIRE(1 == l.at(1));
        REQUIRE(2 == l.at(2));
    }

    SECTION("Exc for insert() at index 4 with 3.")
    {
        l.insert(0, 1);
        l.insert(0, 1);
        l.insert(0, 1);
        REQUIRE_THROWS_AS(l.insert(4, 1), std::out_of_range);
    }
}

TEST_CASE("Test the append() function.", "[base]")
{
    W::slist l;

    SECTION("append() on empty.")
    {
        l.append(1);
        REQUIRE(1 == l.at(0));
    }

    SECTION("append() 3 values.")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
        REQUIRE(3 == l.at(2));
    }
}

TEST_CASE("Test the front() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for front() on empty.")
    {
        REQUIRE_THROWS_AS(l.front(), std::out_of_range);
    }

    SECTION("front() for 1.")
    {
        l.append(1);
        REQUIRE(1 == l.front());
    }

    SECTION("front() for 2.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(2 == l.front());
    }
}

TEST_CASE("Test the back() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for back() on empty.")
    {
        REQUIRE_THROWS_AS(l.back(), std::out_of_range);
    }

    SECTION("back() for 1.")
    {
        l.append(1);
        REQUIRE(1 == l.back());
    }

    SECTION("back() for 2.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(1 == l.back());
    }
}

TEST_CASE("Test the pop_front() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for pop_front() on empty.")
    {
        REQUIRE_THROWS_AS(l.pop_front(), std::out_of_range);
    }

    SECTION("pop_front() on 1.")
    {
        l.append(1);
        REQUIRE(1 == l.pop_front());
        REQUIRE(0 == l.len());
    }

    SECTION("pop_front() on 1.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(2 == l.pop_front());
        REQUIRE(1 == l.pop_front());
        REQUIRE(0 == l.len());
    }
}

TEST_CASE("Test the pop_back() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for pop_back() on empty.")
    {
        REQUIRE_THROWS_AS(l.pop_back(), std::out_of_range);
    }

    SECTION("pop_back() on 1.")
    {
        l.append(1);
        REQUIRE(1 == l.pop_back());
        REQUIRE(0 == l.len());
    }

    SECTION("pop_back() on 2.")
    {
        l.append(2);
        l.append(1);
        REQUIRE(1 == l.pop_back());
        REQUIRE(2 == l.pop_back());
        REQUIRE(0 == l.len());
    }
}

TEST_CASE("Test the remove() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for remove() 0 on empty")
    {
        REQUIRE_THROWS_AS(l.remove(0), std::out_of_range);
    }

    SECTION("Exc for remove() 1 on empty")
    {
        REQUIRE_THROWS_AS(l.remove(0), std::out_of_range);
    }

    SECTION("Exc for remove() 1 on 1")
    {
        l.append(1);
        REQUIRE_THROWS_AS(l.remove(1), std::out_of_range);
    }

    SECTION("Exc for remove() 2 on 2 empty")
    {
        l.append(1);
        l.append(2);
        REQUIRE_THROWS_AS(l.remove(2), std::out_of_range);
    }

    SECTION("remove() 0 on 1")
    {
        l.append(1);
        l.remove(0);
        REQUIRE(0 == l.len());
    }

    SECTION("remove() 0 on 3")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.remove(0);
        REQUIRE(2 == l.at(0));
        REQUIRE(3 == l.at(1));
        REQUIRE(2 == l.len());
    }

    SECTION("remove() 1 on 3")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.remove(1);
        REQUIRE(1 == l.at(0));
        REQUIRE(3 == l.at(1));
        REQUIRE(2 == l.len());
    }

    SECTION("remove() 2 on 3")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.remove(2);
        REQUIRE(1 == l.at(0));
        REQUIRE(2 == l.at(1));
        REQUIRE(2 == l.len());
    }
}

TEST_CASE("Test the backn() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for backn() on empty")
    {
        REQUIRE_THROWS_AS(l.backn(0), std::out_of_range);
        REQUIRE_THROWS_AS(l.backn(1), std::out_of_range);
    }

    SECTION("Exc for backn() for 1 on 1")
    {
        l.append(1);
        REQUIRE_THROWS_AS(l.backn(1), std::out_of_range);
    }

    SECTION("Exc for backn() for 2 on 2")
    {
        l.append(1);
        l.append(2);
        REQUIRE_THROWS_AS(l.backn(2), std::out_of_range);
    }

    SECTION("backn() on 1")
    {
        l.append(1);
        REQUIRE(1 == l.backn(0));
    }

    SECTION("backn() on 3")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        REQUIRE(3 == l.backn(0));
        REQUIRE(2 == l.backn(1));
        REQUIRE(1 == l.backn(2));
    }
}

TEST_CASE("Test the backnr() function.", "[base]")
{
    W::slist l;

    SECTION("Exc for backnr() on empty")
    {
        REQUIRE_THROWS_AS(l.backnr(0), std::out_of_range);
        REQUIRE_THROWS_AS(l.backnr(1), std::out_of_range);
    }

    SECTION("Exc for backnr() for 1 on 1")
    {
        l.append(1);
        REQUIRE_THROWS_AS(l.backnr(1), std::out_of_range);
    }

    SECTION("Exc for backnr() for 2 on 2")
    {
        l.append(1);
        l.append(2);
        REQUIRE_THROWS_AS(l.backnr(2), std::out_of_range);
    }

    SECTION("backnr() on 1")
    {
        l.append(1);
        REQUIRE(1 == l.backnr(0));
    }

    SECTION("backnr() on 2")
    {
        l.append(1);
        l.append(2);
        REQUIRE(2 == l.backnr(0));
        REQUIRE(1 == l.backnr(1));
    }

    SECTION("backnr() on 3")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        REQUIRE(3 == l.backnr(0));
        REQUIRE(2 == l.backnr(1));
        REQUIRE(1 == l.backnr(2));
    }

    SECTION("backnr() on 4")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.append(4);
        REQUIRE(4 == l.backnr(0));
        REQUIRE(3 == l.backnr(1));
        REQUIRE(2 == l.backnr(2));
        REQUIRE(1 == l.backnr(3));
    }
}

TEST_CASE("Test the reverse() function.", "[base]")
{
    W::slist l;

    SECTION("reverse() on empty.")
    {
        l.reverse();
        REQUIRE(l.empty());
    }

    SECTION("reverse() on 1.")
    {
        l.append(1);
        l.reverse();
        REQUIRE(1 == l.len());
        REQUIRE(1 == l.at(0));
    }

    SECTION("reverse() on 2.")
    {
        l.append(1);
        l.append(2);
        l.reverse();
        REQUIRE(2 == l.len());
        REQUIRE(2 == l.at(0));
        REQUIRE(1 == l.at(1));
    }

    SECTION("reverse() on 3.")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.reverse();
        REQUIRE(3 == l.len());
        REQUIRE(3 == l.at(0));
        REQUIRE(2 == l.at(1));
        REQUIRE(1 == l.at(2));
    }

    SECTION("reverse() on 4.")
    {
        l.append(1);
        l.append(2);
        l.append(3);
        l.append(4);
        l.reverse();
        REQUIRE(4 == l.len());
        REQUIRE(4 == l.at(0));
        REQUIRE(3 == l.at(1));
        REQUIRE(2 == l.at(2));
        REQUIRE(1 == l.at(3));
    }
}