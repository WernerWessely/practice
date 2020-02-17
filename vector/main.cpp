
#include <iostream>
#include <vector>
#include "wv.hpp"

int main()
{
    W::wv v;

    std::vector<int> test;

    std::cout << "push:" << std::endl;

    std::cout << v.capacity() << std::endl;
    std::cout << test.capacity() << std::endl
              << std::endl;

    for (int i = 0; i < 50; ++i)
    {
        v.push(i);
        test.push_back(i);
        std::cout << "own: " << v.capacity() << std::endl;
        std::cout << "std: " << test.capacity() << std::endl
                  << std::endl;
    }

    std::cout << "pop:" << std::endl;

    for (int i = 0; i < 50; ++i)
    {
        v.pop();
        test.pop_back();
        std::cout << "own: " << v.capacity() << std::endl;
        std::cout << "std: " << test.capacity() << std::endl
                  << std::endl;
    }

    return 0;
}