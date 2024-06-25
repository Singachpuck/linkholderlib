#include <sstream>
#include <boost/format.hpp>

#include "linkholder/core.h"

namespace dochkas {
    namespace linkholder {

        static std::map<Browser, BrowserConfig> COMMANDS = {
            {Edge, BrowserConfig{"", "start msedge %1%", "Microsoft Edge"}}
        };

        
        UrlAppManager::UrlAppManager(std::string name) : name(name) {
            this->browser = Edge;
        };

        void UrlAppManager::printInfo() {
            std::map<uint64_t, UrlItem>* urls = this->getUrls();

            for (auto& entry : *urls) {
                std::cout << "Added the following UrlItem: " << std::endl;
                std::cout << "Id: " << entry.second.getId() << std::endl;
                std::cout << "Address: " << entry.second.getAddr() << std::endl;
                std::cout << "Description: " << entry.second.getDescription() << std::endl;
                std::cout << "Tags: [" << urlTagsToString(entry.second.getTags()) << "]" << std::endl;
                std::cout << "Last updated: " << entry.second.getStatistics().getLastUpdated() << std::endl;
                std::cout << "Visited " << entry.second.getStatistics().getNVisits() << " times" << std::endl;
                std::cout << std::endl;
            }
        }

        void UrlAppManager::registerUrl(std::string addr, std::string desc, std::vector<uint64_t> tags) {
            const uint64_t currentId = getUrlItemSeqNumber();
            UrlItem item {currentId};
            item.setAddr(addr);
            item.setDescription(desc);
            for (auto& tagId : tags) {
                if (!this->tags.count(tagId)) {
                    std::ostringstream err;
                    err << "Tag with id " << tagId << " was not found!";
                    throw std::invalid_argument(err.str());
                }
                item.addTag(&this->tags[tagId]);
            }
            this->urls.insert({currentId, item});
        }

        void UrlAppManager::updateUrl(UrlItem& newUrl) {
            uint64_t currentId = newUrl.getId();
            if (!this->urls.count(currentId)) {
                std::ostringstream err;
                err << "Url with id " << currentId << " was not found!";
                throw std::invalid_argument(err.str());
            }
            UrlItem item {currentId};
            item.setAddr(newUrl.getAddr());
            item.setDescription(newUrl.getDescription());
            for (auto& tag : newUrl.getTags()) {
                if (this->tags.count(tag.first) == 0) {
                    std::ostringstream err;
                    err << "Tag with id " << tag.first << " was not found!";
                    throw std::invalid_argument(err.str());
                }
                item.addTag(&this->tags[tag.first]);
            }
            this->urls.insert_or_assign(currentId, item);
            this->urls.at(currentId).getStatistics().setLastUpdated(getNow());
        }

        std::map<uint64_t, UrlItem>* UrlAppManager::getUrls() {
            return &this->urls;
        }

        UrlItem UrlAppManager::getUrl(uint64_t id) {
            return this->urls.at(id);
        }

        std::string UrlAppManager::getName() {
            return name;
        }

        void UrlAppManager::setName(std::string name) {
            this->name = name;
        }

        void UrlAppManager::addTag(UrlTag tag) {
            this->tags[tag.getId()] = tag;
        }

        void UrlAppManager::openLink(uint64_t id) {
            if (this->urls.count(id) == 0) {
                std::ostringstream err;
                err << "Url with id " << id << " was not found!";
                throw std::invalid_argument(err.str());
            }

            UrlItem& current = this->urls.at(id);

            #ifdef _WIN32
            std::string command = (boost::format(COMMANDS.at(this->browser).getWindows()) % current.getAddr()).str();
            #else
            std::string command = (boost::format(COMMANDS.at(this->browser).getLinux()) % current.getAddr()).str();
            #endif

            int ret;
            if ((ret = system(command.c_str())) == -1) {
                throw std::runtime_error((boost::format("Error calling browser command: %1%") % ret).str());
            }

            current.getStatistics().incrementNVisits();
        }

        Browser UrlAppManager::getBrowser() {
            return this->browser;
        }

        void UrlAppManager::setBrowser(Browser browser) {
            this->browser = browser;
        }
    }
}