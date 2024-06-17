#ifndef LINKHOLDER_HELPER_H
#define LINKHOLDER_HELPER_H

#include <cstdint>

namespace dochkas {
    namespace linkholder {
        
        static uint64_t URL_ITEM_SEQ_NUMBER = 0;
        static uint64_t URL_STATISTICS_SEQ_NUMBER = 0;


        uint64_t getUrlItemSeqNumber();

        uint64_t getUrlStatisticsSeqNumber();
    }
}

#endif