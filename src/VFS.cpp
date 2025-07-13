#include "VFS.hpp"
#include <sstream>
#include <iostream>

VFS::VFS()
{
    root = std::make_shared<Directory>("/");
    current = root.get();
}

void VFS::execute(const std::string &commandLine)
{
    std::istringstream iss(commandLine);
    std::string cmd, arg1, arg2;
    iss >> cmd >> arg1;
    std::getline(iss, arg2);
    if (cmd == "mkdir")
        mkdir(arg1);
    else if (cmd == "touch")
        touch(arg1);
    else if (cmd == "ls")
        ls();
    else if (cmd == "cd")
        cd(arg1);
    else if (cmd == "cat")
        cat(arg1);
    else if (cmd == "pwd")
        std::cout << pwd() << '\n';
    else if (cmd == "help")
        printHelp();
    else
        std::cout << "Unknown command\n";
}

void VFS::mkdir(const std::string &name)
{
    if (current->hasChild(name))
    {
        std::cout << "Directory already exists\n";
        return;
    }
    auto dir = std::make_shared<Directory>(name);
    current->addChild(dir);
}

void VFS::touch(const std::string &name)
{
    if (current->hasChild(name))
    {
        std::cout << "File already exists\n";
        return;
    }
    auto file = std::make_shared<File>(name);
    current->addChild(file);
}

void VFS::ls() const
{
    current->list();
}

void VFS::cd(const std::string &name)
{
    if (name == ".." && current->parent)
    {
        current = current->parent;
    }
    else if (auto dir = current->getDirectory(name))
    {
        current = dir.get();
    }
    else
    {
        std::cout << "Directory not found\n";
    }
}

void VFS::cat(const std::string &name) const
{
    auto file = current->getFile(name);
    if (file)
        std::cout << file->content << '\n';
    else
        std::cout << "File not found\n";
}

std::string VFS::pwd() const
{
    return current->getPath();
}

void VFS::printHelp() const
{
    std::cout << "Available commands:\n"
              << "mkdir <dir>\n"
              << "touch <file>\n"
              << "ls\n"
              << "cd <dir>\n"
              << "cd ..\n"
              << "cat <file>\n"
              << "pwd\n"
              << "exit\n";
}
