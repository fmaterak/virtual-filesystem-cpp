#pragma once
#include "Node.hpp"
#include "File.hpp"
#include <unordered_map>
#include <memory>

struct Directory : Node
{
    std::unordered_map<std::string, std::shared_ptr<Node>> children;

    explicit Directory(std::string name);
    void addChild(std::shared_ptr<Node> node);
    bool hasChild(const std::string &name) const;
    std::shared_ptr<File> getFile(const std::string &name) const;
    std::shared_ptr<Directory> getDirectory(const std::string &name) const;
    void list() const;
    std::string getPath() const;
    NodeType type() const override;
};