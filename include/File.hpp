#pragma once
#include "Node.hpp"

struct File : Node
{
    std::string content;
    explicit File(std::string name);
    NodeType type() const override;
};
