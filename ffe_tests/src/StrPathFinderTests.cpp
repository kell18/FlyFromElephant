#include <set>
#include <string>
#include <functional>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/StrPathFinder.h"

using namespace ffe;
using namespace std;

using ::testing::Contains;
using ::testing::AllOf;
using ::testing::Eq;
using ::testing::Ge;
using ::testing::Le;

class StrPathFinderTests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    StrPathFinderTests() : Test() {
        defaultFinder = new StrPathFinder(defaultDictionary, defaultAlphabet);
    }

    virtual ~StrPathFinderTests() {
        delete defaultFinder;
    }

    StrPathFinder* defaultFinder;
    set<string> defaultDictionary = { "kot", "ton", "tot", "koti", "rota", "rot", "rrr" };
    set<string> defaultAlphabet = { "a", "k", "o", "t", "n", "i", "r" };
};

TEST_F(StrPathFinderTests, found_defaultDict) {
    string fromWord("kot");
    string toWord("ton");
    auto path = defaultFinder->findPath(fromWord, toWord);
    ASSERT_THAT(path.size(), AllOf(Ge(3), Le(4)));
    EXPECT_THAT(path, AllOf(Contains(Eq("kot")), Contains(Eq("tot")), Contains(Eq("ton"))));
}

TEST_F(StrPathFinderTests, notFound_unreachableWord) {
    string fromWord("ton");
    string toWord("rrr");
    vector<string> expectedPath = {};
    auto path = defaultFinder->findPath(fromWord, toWord);
    EXPECT_EQ(expectedPath, path);
}

TEST_F(StrPathFinderTests, notFound_emptyAlphabet) {
    StrPathFinder pathFinder (defaultDictionary, {});
    string fromWord("ton");
    string toWord("rrr");
    vector<string> expectedPath = {};
    auto path = pathFinder.findPath(fromWord, toWord);
    EXPECT_EQ(expectedPath, path);
}

TEST_F(StrPathFinderTests, found_sameWords) {
    string word("tot");
    auto path = defaultFinder->findPath(word, word);
    EXPECT_EQ(1, path.size());
    EXPECT_EQ(word, path.at(0));
}

TEST_F(StrPathFinderTests, throw_wordsNotInDict) {
    EXPECT_THROW(defaultFinder->findPath("abc", "efg"), invalid_argument);
}

TEST_F(StrPathFinderTests, throw_invalidLength_check) {
    EXPECT_THROW(defaultFinder->findPath("a", "abc"), invalid_argument);
}

