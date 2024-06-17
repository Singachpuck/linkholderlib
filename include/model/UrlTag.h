#ifndef LINKHOLDER_URLTAG_H
#define LINKHOLDER_URLTAG_H

#include <cstdint>
#include <string>

namespace dochkas {
    namespace linkholder {

        class UrlTag {
        private:
            uint64_t id;
            std::string name;
        
        public:
            uint64_t getId();

            void setId(uint64_t id);

            std::string getName();

            void setName(std::string name);
        };
    }
}

#endif