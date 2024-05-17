#include "pch.h"
#include "../BaseBallKATA/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(const std::string& guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception& e) {

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInputLengthIsUnmatched){
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

