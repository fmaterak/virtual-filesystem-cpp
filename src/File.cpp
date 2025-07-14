#include "File.hpp"
File::File(std::string name) : Node(std::move(name)) {}
NodeType File::type() const { return NodeType::File; }