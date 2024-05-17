#include "pch.h"
#include "../SimilarityCheckKATA/SimilarityCheck.cpp"

TEST(SimilarityCheckTest, lengthCheck) {
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}

TEST(SimilarityCheckTest, lengthCheck2) {
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.getLengthPoint("A", "BB"));
}
