#ifndef LINKHOLDER_HELPER_H
#define LINKHOLDER_HELPER_H

#include <cstdint>
#include <map>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "linkholder/model/UrlTag.h"

namespace dochkas {
    namespace linkholder {
        
        static uint64_t URL_ITEM_SEQ_NUMBER = 0;
        static uint64_t URL_STATISTICS_SEQ_NUMBER = 0;


        uint64_t getUrlItemSeqNumber();

        uint64_t getUrlStatisticsSeqNumber();

        std::string urlTagsToString(std::map<uint64_t, UrlTag*> map);

        boost::posix_time::ptime getNow();
    }   
}

#endif