#include "Serializer.hpp"
#include "Directory.hpp"
#include "File.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

void test_save_and_load() {
    auto root = std::make_shared<Directory>("root");
    auto f = std::make_shared<File>("hello.txt");
    f->content = "Hello!";
    root->addChild(f);

    Serializer::saveToFile(root, "vfs_test.json");

    auto loaded = Serializer::loadFromFile("vfs_test.json");
    assert(loaded->hasChild("hello.txt"));
    auto reloadedFile = loaded->getFile("hello.txt");
    assert(reloadedFile);
    assert(reloadedFile->content == "Hello!");
    std::cout << "test_save_and_load passed\n";
}

int main() {
    test_save_and_load();
    std::cout << "All Serialization tests passed\n";
    return 0;
}
