#include "gtest/gtest.h"
#include "src/StrPathFinder.h"

using namespace ffe;

class StrPathFinderFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    StrPathFinderFixture() : Test() {
        pathFinder = new StrPathFinder();
    }

    virtual ~StrPathFinderFixture() {
        delete pathFinder;
    }

    StrPathFinder* pathFinder;
};

TEST_F(StrPathFinderFixture, invalidLengthException_check) {
    bool isThrown = false;
    try {
        pathFinder->findPath("a", "abc");
    }
    catch (std::runtime_error e) {
        isThrown = true;
    }
    EXPECT_EQ(true, isThrown);
}

TEST_F(StrPathFinderFixture, sameStrings_check) {
    auto path = pathFinder->findPath("abc", "abc");
    EXPECT_EQ(0, path.size());
}