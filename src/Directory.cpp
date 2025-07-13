#include "Directory.hpp"
#include <iostream>

Directory::Directory(std::string name) : Node(std::move(name)) {}

void Directory::addChild(std::shared_ptr<Node> node)
{
    node->parent = this;
    children[node->name] = std::move(node);
}

bool Directory::hasChild(const std::string &name) const
{
    return children.contains(name);
}

std::shared_ptr<File> Directory::getFile(const std::string &name) const
{
    if (!hasChild(name))
        return nullptr;
    auto ptr = children.at(name);
    return (ptr->type() == NodeType::File) ? std::static_pointer_cast<File>(ptr) : nullptr;
}

std::shared_ptr<Directory> Directory::getDirectory(const std::string &name) const
{
    if (!hasChild(name))
        return nullptr;
    auto ptr = children.at(name);
    return (ptr->type() == NodeType::Directory) ? std::static_pointer_cast<Directory>(ptr) : nullptr;
}

void Directory::list() const
{
    for (const auto &[name, node] : children)
    {
        std::cout << (node->type() == NodeType::Directory ? "[DIR]  " : "[FILE] ") << name << '\n';
    }
}

std::string Directory::getPath() const
{
    if (!parent)
        return "/";
    return parent->getPath() + name + "/";
}

NodeType Directory::type() const { return NodeType::Directory; }

// ------------------- src/File.cpp -------------------
#include "File.hpp"
File::File(std::string name) : Node(std::move(name)) {}
NodeType File::type() const { return NodeType::File; }

// ------------------- include/Node.hpp -------------------
#pragma once
#include <string>

enum class NodeType
{
    File,
    Directory
};

struct Directory; // forward

struct Node
{
    std::string name;
    Directory *parent = nullptr;
    explicit Node(std::string name);
    virtual NodeType type() const = 0;
    virtual ~Node() = default;
};