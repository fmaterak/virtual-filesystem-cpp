#include "Path.hpp"
#include <cassert>
#include <iostream>

void test_split()
{
    auto parts = Path::split("/a/b/c");
    assert(parts.size() == 3);
    assert(parts[0] == "a");
    assert(parts[1] == "b");
    assert(parts[2] == "c");
    std::cout << "test_split passed\n";
}

void test_normalize()
{
    assert(Path::normalize("/a/b/../c/") == "/a/c");
    assert(Path::normalize("/a//b") == "/a/b");
    assert(Path::normalize("/a/./b/") == "/a/b");
    std::cout << "test_normalize passed\n";
}

int main()
{
    test_split();
    test_normalize();
    std::cout << "All Path tests passed\n";
    return 0;
}
