#include <set>
#include <string>
#include "gtest/gtest.h"

#include "gmock/gmock.h"
#include "src/AdjacencyMatrix.h"

using namespace ffe;
using namespace std;

using ::testing::Contains;
using ::testing::AllOf;
using ::testing::Eq;
using ::testing::Ge;
using ::testing::Le;

class AdjacencyMatrixTests : public ::testing::Test {

public:
    virtual ~AdjacencyMatrixTests() {
    }
};


TEST_F(AdjacencyMatrixTests, found_trivial) {
    AdjacencyMatrix mtx ({
                                 { 0, 1, 0, 0 },
                                 { 0, 0, 1, 0 },
                                 { 0, 0, 0, 1 }
                         });
    auto path = mtx.findPath(0, 2);
    vector<size_t> expected = {0, 1, 2};
    EXPECT_EQ(expected, path);
}

TEST_F(AdjacencyMatrixTests, notFound_unreachable) {
    AdjacencyMatrix mtx ({
                                 { 0, 1, 0, 0 },
                                 { 0, 0, 0, 0 },
                                 { 0, 0, 0, 1 }
                         });
    auto path = mtx.findPath(0, 2);
    vector<size_t> expected = {};
    EXPECT_EQ(expected, path);
}

