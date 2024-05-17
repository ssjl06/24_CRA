class Game
{
public:
	Game() : score(0), pre(0), second_pre(0), throwing(0), frame(0) {}
	void Roll(int n) {
		updateFrame(n);
		if (frame < 10) {
			score += n;
		}
		if(pre==10 || second_pre==10){
			if (pre == 10) {
				score += n;
			}
			if (second_pre == 10) {
				score += n;
			}
		}
		else if (pre + second_pre == 10) {
			score += n;
		}
		second_pre = pre;
		pre = n;
	}
	int Score() {
		return score;
	}

private:
	void updateFrame(int n) {
		if (throwing % 2 == 0) {
			if (n == 10) {
				throwing += 2;
				++frame;
			}
			else {
				throwing++;
			}
		}
		else {
			if (n == 10) {
				++throwing;
				++frame;
			}
		}
	}
	int score;
	int pre;
	int second_pre;
	int throwing;
	int frame;
};