#include "pch.h"
#include "../BaseBallKATA/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{"123"};
	void assertIllegalArgument(const std::string& guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception& e) {

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCases){
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Check2Strike0Balls) {
	GuessResult result = game.guess("124");
	
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Check1Strike2Balls) {
	GuessResult result = game.guess("132");
	
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
