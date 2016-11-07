#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <cstring>
#include "AdjacencyMatrix.h"
#include "utf8.h"

namespace ffe {
    /**
     * @brief  Class for string path-finding.
     */
    class StrPathFinder {
    public:
        /**
         *  @brief  Construct path finder from dictionary file of words (possible with duplicates)
         *  with each word on new line in utf8 encoding.
         *  @param filePath full path and name of dictionary file with new line word separator.
         */
        StrPathFinder(const char* filePath);
        ~StrPathFinder();
        /**
         * @brief  Construct path finder from dictionary of words (possible with duplicates).
         */
        StrPathFinder(const std::vector<std::string> &dictionary);

        /**
         * @brief  Find path fromWord toWord by words differs only by one character and with same length.
         */
        std::vector<std::string>    findPath(const std::string& fromWord, const std::string& toWord) const;
    private:
        AdjacencyMatrix* adjMatrix;
        std::vector<std::string> dictionary;

        bool                        isDifferOnlyOneChar(std::string word1, std::string word2);
        AdjacencyMatrix*            createAdjMatrixFromDictionary(const std::vector<std::string> &dict);
    };
}
