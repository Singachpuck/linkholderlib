#ifndef LINKHOLDER_CORE_H
#define LINKHOLDER_CORE_H

#include <cstdint>
#include <string>
#include <map>

#include "model/UrlItem.h"
#include "service/helper.h"

namespace dochkas {
    namespace linkholder {

        enum Browser {
            Edge, Chrome
        };

        class BrowserConfig {
        private:
            std::string linux;
            std::string windows;
            std::string description;

        public:
            BrowserConfig(const std::string& linuxValue, const std::string& windowsValue, const std::string& descValue)
                                                : linux(linuxValue), windows(windowsValue), description(descValue) {}

            std::string getLinux() {
                return linux;
            }

            std::string getWindows() {
                return windows;
            }

            std::string getDescription() {
                return description;
            }
        };
        
        class UrlAppManager {
        private:
            std::string name;
            std::map<uint64_t, UrlTag> tags;
            std::map<uint64_t, UrlItem> urls;
            Browser browser;

        public:
            UrlAppManager(std::string name);

            std::string getName();

            void setName(std::string name);

            void addTag(UrlTag tag);

            void registerUrl(std::string addr, std::string desc, std::vector<uint64_t> tags);
            void updateUrl(UrlItem& newUrl);

            void printInfo();

            std::map<uint64_t, UrlItem>* getUrls();

            UrlItem getUrl(uint64_t id);

            void openLink(uint64_t id);

            Browser getBrowser();

            void setBrowser(Browser browser);
        };
    }
}

#endif