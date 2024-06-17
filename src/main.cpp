#include <fstream>
#include <iostream>
#include <vector>

#include "core.h"

using namespace dochkas::linkholder;

int main(int argc, char const *argv[])
{
    UrlTag tag1;
    tag1.setId(1);
    tag1.setName("Media");

    UrlTag tag2;
    tag1.setId(2);
    tag1.setName("Ansys");

    UrlAppManager manager("Url Manager");
    manager.addTag(tag1);
    manager.addTag(tag2);

    manager.registerUrl("https://www.google.com/", "First Link.");

    std::map<uint64_t, UrlItem>* urls = manager.getUrls();

    std::cout << "Added the following UrlItem: " << std::endl;
    std::cout << "Id: " << urls->at(0).getId() << std::endl;
    std::cout << "Address: " << urls->at(0).getAddr() << std::endl;
    std::cout << "Description: " << urls->at(0).getDescription() << std::endl;
    
    return 0;
}
