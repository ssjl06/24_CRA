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
		if(pre_pin == 10 || second_pre_pin == 10){
			score += getBonusForStrike(pin);
		}
		else if (pre_pin + second_pre_pin == 10) {
			score += getBonusForSpair(pin);
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

	int getBonusForStrike(int pin)
	{
		int bonus = 0;
		if (pre_pin == 10 && frame < 11) {
			bonus += pin;
		}
		if (second_pre_pin == 10 && frame < 12) {
			bonus += pin;
		}
		return bonus;
	}

	int getBonusForSpair(int pin)
	{
		return pin;
	}

	int score;
	int pre_pin;
	int second_pre_pin;
	int throwing;
	int frame;
};