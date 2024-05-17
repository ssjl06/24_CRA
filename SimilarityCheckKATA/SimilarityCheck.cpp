#include <string>
#include <cmath>

class SimilarityChecker
{
public:
	int getLengthPoint(const std::string& str1, const std::string& str2) {
		auto length1 = static_cast<int>(str1.size());
		auto length2 = static_cast<int>(str2.size());
		auto gap = std::abs(length1 - length2);
		auto shorter_one = std::min(length1, length2);
		return (1 - (static_cast<double>(gap)/static_cast<double>(shorter_one))) * 60;
	}
};