#include "model/UrlStatistics.h"

namespace dochkas {
    namespace linkholder {
        UrlStatistics::UrlStatistics(uint64_t id) : id(id) {};

        uint64_t UrlStatistics::getId() {
            return id;
        }

        void UrlStatistics::setId(uint64_t id) {
            this->id = id;
        }

        uint32_t UrlStatistics::getNVisits() {
            return this->nVisits;
        }

        void UrlStatistics::setNVisits(uint32_t nVisits) {
            this->nVisits = nVisits;
        }

        void UrlStatistics::incrementNVisits() {
            this->nVisits++;
        }

        boost::posix_time::ptime UrlStatistics::getLastUpdated() {
            return lastUpdated;
        }

        void UrlStatistics::setLastUpdated(boost::posix_time::ptime lastUpdated) {
            this->lastUpdated = lastUpdated;
        }
    }
}