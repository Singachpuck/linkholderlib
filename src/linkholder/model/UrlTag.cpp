#include "linkholder/model/UrlTag.h"

namespace dochkas {
    namespace linkholder {
        uint64_t UrlTag::getId() {
            return id;
        }

        void UrlTag::setId(uint64_t id) {
            this->id = id;
        }

        std::string UrlTag::getName() {
            return name;
        }

        void UrlTag::setName(std::string name) {
            this->name = name;
        }
    }
}