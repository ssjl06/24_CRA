#include <string>
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch < '0' || '9' < ch) {
				throw std::invalid_argument("Must be a number");
			}
		}
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]
			) {
			throw std::invalid_argument("Must not have the same number.");
		}
	}
};