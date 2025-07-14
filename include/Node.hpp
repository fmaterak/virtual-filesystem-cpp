#pragma once
#include <string>

enum class NodeType
{
    File,
    Directory
};

struct Directory; // forward declaration

struct Node
{
    std::string name;
    Directory *parent = nullptr;
    explicit Node(std::string name);
    virtual NodeType type() const = 0;
    virtual ~Node() = default;
};