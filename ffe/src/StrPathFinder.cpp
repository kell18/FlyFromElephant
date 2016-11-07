#include <iostream>
#include "StrPathFinder.h"

namespace ffe {

    StrPathFinder::StrPathFinder(const char* filePath) {
        std::ifstream file(filePath);
        std::string word;
        while (std::getline(file, word)) {
            dictionary.push_back(word);
        }
        adjMatrix = createAdjMatrixFromDictionary(dictionary);
    }

    StrPathFinder::StrPathFinder(const std::vector<std::string> &dictionary) :
            dictionary(dictionary) {
        adjMatrix = createAdjMatrixFromDictionary(dictionary);
    }

    std::vector<std::string> StrPathFinder::findPath(const std::string& fromWord, const std::string& toWord) const {
        if (fromWord.size() != toWord.size()) {
            throw std::invalid_argument("Lengths of words must match");
        }
        size_t fromInd = std::find(dictionary.begin(), dictionary.end(), fromWord) - dictionary.begin();
        size_t toInd = std::find(dictionary.begin(), dictionary.end(), toWord) - dictionary.begin();
        if (fromInd >= dictionary.size() || toInd >= dictionary.size()) {
            throw std::invalid_argument("Dictionary does not contain this words");
        }
        auto indPath = adjMatrix->findPath(fromInd, toInd);
        std::vector<std::string> strPath;
        strPath.reserve(indPath.size());
        auto& dict = dictionary;
        std::for_each(indPath.begin(), indPath.end(), [&dict, &strPath](size_t ind) {
            strPath.push_back(dict[ind]);
        });
        return strPath;
    }


    std::vector<std::string> StrPathFinder::findPath(const std::vector<char32_t>& wordV, const std::vector<char32_t>& toWordV,
                                                     const std::vector<std::string>& path) const {

        return {};
    }

    AdjacencyMatrix* StrPathFinder::createAdjMatrixFromDictionary(const std::vector<std::string> &dict) {
        size_t length = dict.size();
        std::vector<std::vector<bool> > matrix(length, std::vector<bool> (length, false));
        for (size_t outI = 0; outI < length; ++outI) {
            for (size_t innI = 0; innI < length; ++innI) if (dict[outI] != dict[innI]) {
                    matrix[outI][innI] = isDifferOnlyOneChar(dict[outI], dict[innI]);
                }
        }
        return new AdjacencyMatrix(matrix);
    }

    bool StrPathFinder::isDifferOnlyOneChar(std::string word1, std::string word2) {
        std::vector<unsigned short> word1U16;
        utf8::utf8to16(word1.begin(), word1.end(), back_inserter(word1U16));
        std::vector<unsigned short> word2U16;
        utf8::utf8to16(word2.begin(), word2.end(), back_inserter(word2U16));

        if (word1U16.size() != word2U16.size()) return false;
        bool hasOneDifferCh = false;
        for (size_t i = 0; i < word1U16.size(); ++i) {
            if (word1U16[i] != word2U16[i]) {
                if (hasOneDifferCh) return false;
                else hasOneDifferCh = true;
            }
        }
        return true;
    }

    StrPathFinder::~StrPathFinder() {
        delete adjMatrix;
    }
}