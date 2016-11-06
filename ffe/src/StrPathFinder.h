#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <cstring>

namespace ffe {
    class StrPathFinder {
    public:
                                    StrPathFinder(const std::set<std::string>& dictionary,
                                                  const std::set<std::string>& alphabet);

        std::vector<std::string>    findPath(const std::string& fromWord, const std::string& toWord) const;
    private:
        const std::set<std::string> dictionary;
        const std::set<std::string> alphabet;

        std::vector<std::string>    findPath(const std::string& word, const std::string& to,
                                             const std::vector<std::string>& path) const;
        bool                        isDictContainsWord(const std::string &word) const;
    };
}
