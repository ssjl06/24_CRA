#include "pch.h"
#include "../SimilarityCheckKATA/SimilarityCheck.cpp"

TEST(SimilarityCheckTest, lengthCheck) {
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.getLengthPoint("ASD", "DSA"));
}
