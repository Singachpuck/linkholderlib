#ifndef LINKHOLDER_URLSTATISTICS_H
#define LINKHOLDER_URLSTATISTICS_H

#include <cstdint>
#include <string>
#include <map>
#include <boost/date_time/posix_time/posix_time.hpp>


namespace dochkas {
    namespace linkholder {
        
        class UrlStatistics {
        private:
            uint64_t id;
            uint32_t nVisits = 0;
            boost::posix_time::ptime lastUpdated;

        public:
            UrlStatistics(uint64_t id);

            uint64_t getId();

            void setId(uint64_t id);

            uint32_t getNVisits();

            void setNVisits(uint32_t nVisits);

            void incrementNVisits();

            boost::posix_time::ptime getLastUpdated();

            void setLastUpdated(boost::posix_time::ptime lastUpdated);
        };
    }
}

#endif