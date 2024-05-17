#include <string>
#include <cmath>
#include <unordered_set>

class SimilarityChecker
{
public:
	int getPoint(const std::string& str1, const std::string& str2) {
		return getLengthPoint(str1, str2) + getAlphaPoint(str1, str2);
	}

	int getLengthPoint(const std::string& str1, const std::string& str2) {
		auto length1 = static_cast<int>(str1.size());
		auto length2 = static_cast<int>(str2.size());
		auto gap = std::abs(length1 - length2);
		auto shorter_length = std::min(length1, length2);
		return (1 - (static_cast<double>(gap)/static_cast<double>(shorter_length))) * 60;
	}

	int getAlphaPoint(const std::string& str1, const std::string& str2) {
		std::unordered_set<char> total_set;
		std::unordered_set<char> str1_set;
		std::unordered_set<char> str2_set;

		for (auto ch : str1) {
			total_set.insert(ch);
			str1_set.insert(ch);
		}
		for (auto ch : str2) {
			total_set.insert(ch);
			str2_set.insert(ch);
		}
		int same_cnt = 0;
		int total_cnt = total_set.size();
		for (auto ch : total_set) {
			if (str1_set.count(ch) && str2_set.count(ch)) {
				++same_cnt;
			}
		}
		return (static_cast<double>(same_cnt)/total_cnt) * 40;
	}
};