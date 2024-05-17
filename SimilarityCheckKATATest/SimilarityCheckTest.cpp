#include "pch.h"
#include "../SimilarityCheckKATA/SimilarityCheck.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckFixture, lengthCheck) {
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckFixture, lengthCheck2) {
	EXPECT_EQ(0, checker.getLengthPoint("A", "BB"));
}

TEST_F(SimilarityCheckFixture, lengthCheck3) {
	EXPECT_EQ(20, checker.getLengthPoint("AAABB", "BAA"));
}

