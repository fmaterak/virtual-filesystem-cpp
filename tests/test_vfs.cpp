#include "VFS.hpp"
#include <cassert>
#include <iostream>

void test_create_and_list()
{
    VFS vfs;
    vfs.execute("mkdir docs");
    vfs.execute("touch file.txt");

    // Nie ma metody zwracającej wynik, więc zakładamy, że brak wyjątku = sukces
    std::cout << "test_create_and_list passed\n";
}

void test_navigation()
{
    VFS vfs;
    vfs.execute("mkdir sub");
    vfs.execute("cd sub");
    vfs.execute("touch file1");

    std::cout << "test_navigation passed\n";
}

int main()
{
    test_create_and_list();
    test_navigation();
    std::cout << "All VFS tests passed\n";
    return 0;
}
