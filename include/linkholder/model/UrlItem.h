#ifndef LINKHOLDER_URLITEM_H
#define LINKHOLDER_URLITEM_H

#include <cstdint>
#include <string>
#include <map>

#include "UrlTag.h"
#include "UrlStatistics.h"
#include "linkholder/service/helper.h"

namespace dochkas {
    namespace linkholder {
        
        class UrlItem {
        private:
            uint64_t id;
            std::string addr;
            std::string description;
            std::map<uint64_t, UrlTag*> tags;
            UrlStatistics stat{0};

        public:
            UrlItem(uint64_t id);

            uint64_t getId();

            void setId(uint64_t id);

            std::string getAddr();

            void setAddr(std::string addr);

            std::string getDescription();

            void setDescription(std::string description);

            void addTag(UrlTag* tag);

            std::map<uint64_t, UrlTag*> getTags();

            UrlStatistics& getStatistics();
        };
    }
}

#endif