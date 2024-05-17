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

TEST_F(SimilarityCheckFixture, alphaCheck) {
	EXPECT_EQ(40, checker.getAlphaPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckFixture, alphaCheck2) {
	EXPECT_EQ(0, checker.getAlphaPoint("A", "BB"));
}

TEST_F(SimilarityCheckFixture, alphaCheck3) {
	EXPECT_EQ(40, checker.getAlphaPoint("AAABB", "BA"));
}

TEST_F(SimilarityCheckFixture, alphaCheck4) {
	EXPECT_EQ(20, checker.getAlphaPoint("AA", "AAE"));
}
