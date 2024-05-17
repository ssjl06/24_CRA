class Game
{
public:
	Game() : score(0) {}
	void Roll(int n) {
		score+=n;
	}
	int Score() {
		return score;
	}
private:
	int score;
};