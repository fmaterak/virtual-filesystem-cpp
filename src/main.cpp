#include "VFS.hpp"
#include <iostream>
#include <string>

int main()
{
    VFS vfs;
    std::string cmd;
    std::cout << "Virtual File System\nType 'help' for a list of commands.\n";
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, cmd);
        if (cmd == "exit")
            break;
        vfs.execute(cmd);
    }
    return 0;
}
