#include <string>
#include <cmath>
#include <unordered_set>

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

	int getAlphaPoint(const std::string& str1, const std::string& str2) {
		std::unordered_set<char> total_set;
		std::unordered_set<char> diff_set;
		for (auto ch : str1) {
			total_set.insert(ch);
			diff_set.insert(ch);
		}
		for (auto ch : str2) {
			total_set.insert(ch);
			diff_set.erase(ch);
		}
		double same_cnt = total_set.size() - diff_set.size();
		return (same_cnt/static_cast<double>(total_set.size())) * 40;
	}
};