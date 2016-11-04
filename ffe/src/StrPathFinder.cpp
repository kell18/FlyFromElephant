#include "StrPathFinder.h"

namespace ffe {
    std::vector<std::string> StrPathFinder::findPath(const std::string from, const std::string to) const {
        if (from.size() != to.size()) {
            throw std::runtime_error("Lengths of strings must match");
        }
        return {"Hi", "There", "!"};
    }
}