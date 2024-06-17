#include "core.h"

namespace dochkas {
    namespace linkholder {
        
        UrlAppManager::UrlAppManager(std::string name) : name(name) {};

        std::string UrlAppManager::getName() {
            return name;
        }

        void UrlAppManager::setName(std::string name) {
            this->name = name;
        }

        void UrlAppManager::addTag(UrlTag tag) {
            this->tags[tag.getId()] = tag;
        }

        // Move to core.cpp
        void UrlAppManager::registerUrl(std::string addr, std::string desc) {
            uint64_t currentId = getUrlItemSeqNumber();
            UrlItem item {currentId};
            item.setAddr(addr);
            item.setDescription(desc);
            this->urls.insert({currentId, item});
        }

        std::map<uint64_t, UrlItem>* UrlAppManager::getUrls() {
            return &this->urls;
        }
    }
}