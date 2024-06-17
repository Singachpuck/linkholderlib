#include "model/UrlItem.h"

namespace dochkas {
    namespace linkholder {
        UrlItem::UrlItem(uint64_t id) : id(id) {
            this->stat.setId(getUrlStatisticsSeqNumber());
            this->stat.setLastUpdated(getNow());
        }

        uint64_t UrlItem::getId() {
            return id;
        }

        void UrlItem::setId(uint64_t id) {
            this->id = id;
        }

        std::string UrlItem::getAddr() {
            return addr;
        }

        void UrlItem::setAddr(std::string addr) {
            this->addr = addr;
        }

        std::string UrlItem::getDescription() {
            return description;
        }

        void UrlItem::setDescription(std::string description) {
            this->description = description;
        }

        void UrlItem::addTag(UrlTag* tag) {
            this->tags[tag->getId()] = tag;
        }

        std::map<uint64_t, UrlTag*> UrlItem::getTags() {
            return this->tags;
        }

        UrlStatistics& UrlItem::getStatistics() {
            return this->stat;
        }
    }
}