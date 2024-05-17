class Game
{
public:
	Game() 
		: score(0)
		, pre_pin(0)
		, second_pre_pin(0)
		, throwing(0)
		, frame(0) 
	{
	}

	void Roll(int pin) {
		if (frame < 10) {
			score += pin;
		}
		if(pre_pin==10 || second_pre_pin==10){
			if (pre_pin == 10 && frame < 11) {
				score += pin;
			}
			if (second_pre_pin == 10 && frame < 12) {
				score += pin;
			}
		}
		else if (pre_pin + second_pre_pin == 10) {
			score += pin;
		}
		second_pre_pin = pre_pin;
		pre_pin = pin;
		updateFrame(pin);
	}

	int Score() const {
		return score;
	}

private:
	void updateFrame(int pin) {
		if (throwing % 2 == 0) {
			if (pin == 10) {
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
	int pre_pin;
	int second_pre_pin;
	int throwing;
	int frame;
};