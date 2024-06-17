#ifndef LINKHOLDER_CORE_H
#define LINKHOLDER_CORE_H

#include <cstdint>
#include <string>
#include <map>

#include "model/UrlItem.h"
#include "service/helper.h"

namespace dochkas {
    namespace linkholder {
        
        class UrlAppManager {
        private:
            std::string name;
            std::map<uint64_t, UrlTag> tags;
            std::map<uint64_t, UrlItem> urls;

        public:
            UrlAppManager(std::string name);

            std::string getName();

            void setName(std::string name);

            void addTag(UrlTag tag);

            void registerUrl(std::string addr, std::string desc);

            std::map<uint64_t, UrlItem>* getUrls();
        };
    }
}

#endif