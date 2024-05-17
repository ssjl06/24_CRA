class Game
{
public:
	Game() 
		: score(0)
		, pre_score(0)
		, second_pre_score(0)
		, throwing(0)
		, frame(0) 
	{
	}

	void Roll(int n) {
		if (frame < 10) {
			score += n;
		}
		if(pre_score==10 || second_pre_score==10){
			if (pre_score == 10 && frame < 11) {
				score += n;
			}
			if (second_pre_score == 10 && frame < 12) {
				score += n;
			}
		}
		else if (pre_score + second_pre_score == 10) {
			score += n;
		}
		second_pre_score = pre_score;
		pre_score = n;
		updateFrame(n);
	}

	int Score() const {
		return score;
	}

private:
	void updateFrame(int n) {
		if (throwing % 2 == 0) {
			if (n == 10) {
				throwing += 2;
				++frame;
				return;
			}
			throwing++;
			return;
		}
		++throwing;
		++frame;
	}

	int score;
	int pre_score;
	int second_pre_score;
	int throwing;
	int frame;
};