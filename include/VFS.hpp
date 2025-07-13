#pragma once
#include "Directory.hpp"

class VFS
{
    std::shared_ptr<Directory> root;
    Directory *current;

public:
    VFS();
    void execute(const std::string &commandLine);
    void mkdir(const std::string &name);
    void touch(const std::string &name);
    void ls() const;
    void cd(const std::string &name);
    void cat(const std::string &name) const;
    std::string pwd() const;
    void printHelp() const;
};