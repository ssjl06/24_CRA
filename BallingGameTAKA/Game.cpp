class Game
{
public:
	Game() : score(0), pre(0), second_pre(0) {}
	void Roll(int n) {
		score+=n;
		if (pre + second_pre == 10) {
			score += n;
		}
		second_pre = pre;
		pre = n;
	}
	int Score() {
		return score;
	}
private:
	int score;
	int pre;
	int second_pre;
};