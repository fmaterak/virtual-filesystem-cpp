#include "Serializer.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Serializer
{

    json nodeToJson(const std::shared_ptr<Node> &node)
    {
        json j;
        j["name"] = node->name;
        if (node->type() == NodeType::File)
        {
            auto f = std::static_pointer_cast<File>(node);
            j["type"] = "file";
            j["content"] = f->content;
        }
        else
        {
            auto d = std::static_pointer_cast<Directory>(node);
            j["type"] = "dir";
            for (const auto &[name, child] : d->children)
            {
                j["children"].push_back(nodeToJson(child));
            }
        }
        return j;
    }

    std::shared_ptr<Node> jsonToNode(const json &j)
    {
        std::string type = j["type"];
        std::string name = j["name"];
        if (type == "file")
        {
            auto f = std::make_shared<File>(name);
            f->content = j.value("content", "");
            return f;
        }
        else
        {
            auto d = std::make_shared<Directory>(name);
            for (const auto &child : j["children"])
            {
                auto node = jsonToNode(child);
                d->addChild(node);
            }
            return d;
        }
    }

    void saveToFile(const std::shared_ptr<Directory> &root, const std::string &filename)
    {
        std::ofstream ofs(filename);
        ofs << nodeToJson(root).dump(2);
    }

    std::shared_ptr<Directory> loadFromFile(const std::string &filename)
    {
        std::ifstream ifs(filename);
        json j;
        ifs >> j;
        return std::static_pointer_cast<Directory>(jsonToNode(j));
    }

} // namespace Serializer
