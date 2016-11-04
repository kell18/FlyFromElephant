#pragma once

#include <vector>
#include <string>
#include <stdexcept>

namespace ffe {
    class StrPathFinder {
    public:
        std::vector<std::string> findPath(const std::string from, const std::string to) const;
    };
}
