#include <string>
#include <stdexcept>

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const std::string& question)
		: question(question) {

	}

	GuessResult guess(const std::string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		return { true, 3, 0 };
	}
private:
	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if ('0' <= ch && ch <= '9') continue; 
			throw std::invalid_argument("Must be a number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("Must not have the same number.");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber) {
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]
			) {
			return true;
		}
		return false;
	}
private:
	std::string question;
};