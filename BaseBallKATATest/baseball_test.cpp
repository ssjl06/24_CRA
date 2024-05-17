#include "pch.h"
#include "../BaseBallKATA/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched){
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), std::length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar){
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12s")), std::invalid_argument);
}
