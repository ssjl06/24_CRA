#include <string>
#include <stdexcept>
#include <unordered_map>

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const std::string& question)
		: question(question) 
	{
		assertIllegalArgument(question);
		for (int i = 0; i < question.size(); ++i) {
			idx_map[question[i]] = i;
		}
	}

	GuessResult guess(const std::string& guessNumber) {
		assertIllegalArgument(guessNumber);
		return { getStrikes(guessNumber) == 3, getStrikes(guessNumber), getBalls(guessNumber) };
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
	int getStrikes(const std::string& guessNumber) {
		int strikes = 0;
		for (int i = 0; i < guessNumber.size(); ++i) {
			if (idx_map.count(guessNumber[i]) != 0 && idx_map[guessNumber[i]] == i) {
				++strikes;
			}
		}
		return strikes;
	}
	int getBalls(const std::string& guessNumber) {
		int balls = 0;
		for (int i = 0; i < guessNumber.size(); ++i) {
			if (idx_map.count(guessNumber[i]) != 0 && idx_map[guessNumber[i]] != i) {
				++balls;
			}
		}
		return balls;
	}

	std::string question;
	std::unordered_map<char, int> idx_map;
};