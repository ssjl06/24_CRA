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
	}
};