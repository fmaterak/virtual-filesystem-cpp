#include "Path.hpp"
#include <sstream>
#include <vector>

std::vector<std::string> Path::split(const std::string &path)
{
    std::vector<std::string> parts;
    std::istringstream ss(path);
    std::string part;
    while (std::getline(ss, part, '/'))
    {
        if (!part.empty() && part != ".")
            parts.push_back(part);
    }
    return parts;
}

std::string Path::normalize(const std::string &path)
{
    auto parts = split(path);
    std::vector<std::string> stack;
    for (const auto &part : parts)
    {
        if (part == "..")
        {
            if (!stack.empty())
                stack.pop_back();
        }
        else
        {
            stack.push_back(part);
        }
    }
    std::string result = "/";
    for (const auto &s : stack)
    {
        result += s + "/";
    }
    if (result.size() > 1 && result.back() == '/')
        result.pop_back();
    return result;
}
