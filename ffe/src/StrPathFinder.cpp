#include "StrPathFinder.h"

namespace ffe {

    StrPathFinder::StrPathFinder(const std::set<std::string>& dictionary, const std::set<std::string>& alphabet) :
            dictionary(dictionary), alphabet(alphabet) {
    }

    std::vector<std::string> StrPathFinder::findPath(const std::string& fromWord, const std::string& toWord) const {
        if (fromWord.size() != toWord.size()) {
            throw std::invalid_argument("Lengths of words must match");
        }
        bool hasWords = dictionary.find(fromWord) != dictionary.end() && dictionary.find(toWord) != dictionary.end();
        if (!hasWords) {
            throw std::invalid_argument("Dictionary does not contain this words");
        }
        if (fromWord == toWord) {
            return { fromWord };
        }
        return findPath(fromWord, toWord, { fromWord });
    }

    std::vector<std::string> StrPathFinder::findPath(const std::string& word, const std::string& toWord,
                                                     const std::vector<std::string>& path) const {
        for (size_t chInd = 0, lenCh = word.size(); chInd < lenCh; ++chInd) {
            for (auto alIt = alphabet.begin(), alEnd = alphabet.end(); alIt != alEnd; ++alIt) {
                if (word.substr(chInd, 1) == (*alIt)) {
                    continue; // skip iteration over the same letter of word
                }
                std::string newWord(word);
                newWord.replace(chInd, 1, *alIt);
                bool pathHasNoWord = std::find(path.begin(), path.end(), newWord) == path.end();
                // Go deeper if word does't used in path and contains in dictionary
                if (pathHasNoWord && isDictContainsWord(newWord)) {
                    std::vector<std::string> newPath(path.size() + 1);
                    std::copy(path.begin(), path.end(), newPath.begin());
                    newPath[path.size()] = newWord;
                    return newWord == toWord ? newPath : findPath(newWord, toWord, newPath);
                }
            }
        }
        return {};
    }

    bool StrPathFinder::isDictContainsWord(const std::string &word) const {
        return dictionary.find(word) != dictionary.end();
    }

}