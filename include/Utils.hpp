#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace Utils
{
    std::vector<std::string> split(std::string_view str, char delim);
    std::string trim(std::string_view str);
}
