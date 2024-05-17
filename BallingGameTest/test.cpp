#include "pch.h"
#include "../BallingGameTAKA/Game.cpp"

TEST(GameTest, ���0��ȹ��) {
	Game game;
	for (int i = 0; i < 20; ++i) {
		game.Roll(0);
	}
	EXPECT_EQ(0, game.Score());
}

TEST(GameTest, DISABLED_��1����ȹ��) {
	Game game;
	for (int i = 0; i < 20; ++i) {
		game.Roll(1);
	}
	EXPECT_EQ(20, game.Score());
}

TEST(GameTest, DISABLED_�����) {
	Game game;
	game.Roll(5);
	game.Roll(5); // spare
	game.Roll(3);
	for (int i = 3; i < 20; ++i) {
		game.Roll(0);
	}

	EXPECT_EQ(16, game.Score());
}

TEST(GameTest, DISABLED_��Ʈ����ũ) {
	Game game;
	game.Roll(10); // strike
	game.Roll(3);
	game.Roll(4);
	for (int i = 4; i < 20; ++i) {
		game.Roll(0);
	}

	EXPECT_EQ(24, game.Score());
}

TEST(GameTest, DISABLED_����Ʈ����) {
	Game game;
	for (int i = 0; i < 12; ++i) {
		game.Roll(10);
	}

	EXPECT_EQ(300, game.Score());
}

TEST(GameTest, DISABLED_���ð���) {
	Game game; 
	game.Roll(1); 
	game.Roll(4); 
	game.Roll(4); 
	game.Roll(5); 
	game.Roll(6); 
	game.Roll(4); 
	game.Roll(5); 
	game.Roll(5); 
	game.Roll(10); 
	game.Roll(0); 
	game.Roll(1); 
	game.Roll(7); 
	game.Roll(3); 
	game.Roll(6); 
	game.Roll(4); 
	game.Roll(10); 
	game.Roll(2); 
	game.Roll(8); 
	game.Roll(6); 
	EXPECT_EQ(133, game.Score()); 
}
