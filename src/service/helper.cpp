#include "service/helper.h"


namespace dochkas {
    namespace linkholder {
        uint64_t getUrlItemSeqNumber() {
            return URL_ITEM_SEQ_NUMBER++;
        }

        uint64_t getUrlStatisticsSeqNumber() {
            return URL_STATISTICS_SEQ_NUMBER++;
        }
    }
}