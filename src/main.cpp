#include <fstream>
#include <iostream>
#include <vector>

#include "core.h"

using namespace dochkas::linkholder;

int main(int argc, char const *argv[])
{
    UrlTag tag1;
    tag1.setId(1);
    tag1.setName("Google");

    UrlTag tag2;
    tag2.setId(2);
    tag2.setName("IT");

    UrlTag tag3;
    tag3.setId(3);
    tag3.setName("Important");

    UrlAppManager manager("Url Manager");
    manager.addTag(tag1);
    manager.addTag(tag2);
    manager.addTag(tag3);

    manager.registerUrl("https://www.google.com/", "Google.", {1});
    manager.registerUrl("https://github.com/", "GitHub.", {1, 2});

    // manager.printInfo();

    std::cout << "------------------------" << std::endl;

    UrlItem item1{0};
    item1.setAddr("https://en.cppreference.com/");
    item1.setDescription("C++ reference.");
    item1.addTag(&tag2);
    item1.addTag(&tag3);
    manager.updateUrl(item1);

    UrlItem item2 = manager.getUrl(1);
    item2.addTag(&tag1);
    item2.addTag(&tag3);
    manager.updateUrl(item2);
    
    manager.printInfo();

    manager.openLink(0);
    manager.openLink(1);

    manager.printInfo();

    return 0;
}
