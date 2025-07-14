#include "Utils.hpp"
#include <sstream>
#include <algorithm>

std::vector<std::string> Utils::split(std::string_view str, char delim)
{
    std::vector<std::string> result;
    std::string token;
    std::istringstream stream{std::string{str}};
    while (std::getline(stream, token, delim))
    {
        if (!token.empty())
            result.push_back(token);
    }
    return result;
}

std::string Utils::trim(std::string_view str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string_view::npos)
        return "";
    return std::string(str.substr(start, end - start + 1));
}
