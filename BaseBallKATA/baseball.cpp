#include <string>
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& str) {
		if (str.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : str) {
			if (ch < '0' || '9' < ch) {
				throw std::invalid_argument("Must be a number");
			}
		}
	}
};