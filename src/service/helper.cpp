#include "service/helper.h"

#include <boost/algorithm/string.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/transformed.hpp>

namespace dochkas {
    namespace linkholder {
        uint64_t getUrlItemSeqNumber() {
            return URL_ITEM_SEQ_NUMBER++;
        }

        uint64_t getUrlStatisticsSeqNumber() {
            return URL_STATISTICS_SEQ_NUMBER++;
        }

        std::string urlTagsToString(std::map<uint64_t, UrlTag*> map) {
            return boost::algorithm::join(map | boost::adaptors::transformed([] (auto& e) { return e.second->getName(); }), ", ");
        }

        boost::posix_time::ptime getNow() {
            return boost::posix_time::microsec_clock::local_time();
        }
    }
}