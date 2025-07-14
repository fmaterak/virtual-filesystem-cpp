#pragma once
#include <string>
#include <memory>
#include "Directory.hpp"

namespace Serializer
{
    void saveToFile(const std::shared_ptr<Directory> &root, const std::string &filename);
    std::shared_ptr<Directory> loadFromFile(const std::string &filename);
}
