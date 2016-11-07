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
    StrPathFinder* defaultFinder;
    const char* defaultFilePath = "@PROJECT_SOURCE_DIR@/res/input_small.txt";

    StrPathFinderTests() : Test() {
        vector<string> defaultDictionary = { "кот", "тон", "тот", "коты", "рота", "рот", "ррр" };
        defaultFinder = new StrPathFinder(defaultDictionary);
    }

    virtual ~StrPathFinderTests() {
        delete defaultFinder;
    }
};

TEST_F(StrPathFinderTests, found_dictWithCircularDependencies) {
    vector<string> dictionary = { "123", "124", "125", "126", "127", "136", "137", "134", "144" };
    StrPathFinder finder(dictionary);
    string fromWord("123");
    string toWord("144");
    auto path = finder.findPath(fromWord, toWord);
    EXPECT_THAT(path.size(), AllOf(Ge(3), Le(7)));
    EXPECT_THAT(path, AllOf(Contains(Eq("123")), Contains(Eq("124")), Contains(Eq("144"))));
}

TEST_F(StrPathFinderTests, found_defaultDict_WithDuplicates) {
    vector<string> dictionary = { "кот", "тон", "тот", "коты", "коты", "рота", "рот", "рот", "рот", "ррр" };
    StrPathFinder finder(dictionary);
    string fromWord("кот");
    string toWord("тон");
    auto path = finder.findPath(fromWord, toWord);
    EXPECT_THAT(path.size(), AllOf(Ge(3), Le(7)));
    EXPECT_THAT(path, AllOf(Contains(Eq("кот")), Contains(Eq("тот")), Contains(Eq("тон"))));
}

TEST_F(StrPathFinderTests, found_defaultDict) {
    string fromWord("кот");
    string toWord("тон");
    auto path = defaultFinder->findPath(fromWord, toWord);
    EXPECT_THAT(path.size(), AllOf(Ge(3), Le(4)));
    EXPECT_THAT(path, AllOf(Contains(Eq("кот")), Contains(Eq("тот")), Contains(Eq("тон"))));
}

/*TEST_F(StrPathFinderTests, found_defaultDict_FromFile) {
    StrPathFinder finder(defaultFilePath);
    string fromWord("кот");
    string toWord("тон");
    auto path = finder.findPath(fromWord, toWord);
    EXPECT_THAT(path.size(), AllOf(Ge(3), Le(7)));
    EXPECT_THAT(path, AllOf(Contains(Eq("кот")), Contains(Eq("тот")), Contains(Eq("тон"))));
}*/

TEST_F(StrPathFinderTests, notFound_unreachableWord) {
    string fromWord("тон");
    string toWord("ррр");
    vector<string> expectedPath = {};
    auto path = defaultFinder->findPath(fromWord, toWord);
    EXPECT_EQ(expectedPath, path);
}

TEST_F(StrPathFinderTests, found_sameWords) {
    string word("тот");
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

