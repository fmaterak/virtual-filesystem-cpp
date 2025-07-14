#pragma once
#include <string>
#include <vector>

namespace Path
{
    std::vector<std::string> split(const std::string &path);
    std::string normalize(const std::string &path);
}