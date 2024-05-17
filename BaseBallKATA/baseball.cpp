#include <string>
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& str) {
		if (str.length() != 3) {
			throw std::length_error("Must be three letters");
		}
	}
};