#include "pch.h"
#include "../BallingGameTAKA/Game.cpp"

TEST(GameTest, ¸ðµÎ0Á¡È¹µæ) {
	Game game;
	for (int i = 0; i < 20; ++i) {
		game.Roll(0);
	}
	EXPECT_EQ(0, game.Score());
}

TEST(GameTest, DISABLED_°¢1Á¡¾¿È¹µæ) {
	Game game;
	for (int i = 0; i < 20; ++i) {
		game.Roll(1);
	}
	EXPECT_EQ(20, game.Score());
}

TEST(GameTest, DISABLED_½ºÆä¾î) {
	Game game;
	game.Roll(5);
	game.Roll(5); // spare
	game.Roll(3);
	for (int i = 3; i < 20; ++i) {
		game.Roll(0);
	}

	EXPECT_EQ(16, game.Score());
}

TEST(GameTest, DISABLED_½ºÆ®¶óÀÌÅ©) {
	Game game;
	game.Roll(10); // strike
	game.Roll(3);
	game.Roll(4);
	for (int i = 4; i < 20; ++i) {
		game.Roll(0);
	}

	EXPECT_EQ(24, game.Score());
}

TEST(GameTest, DISABLED_ÆÛÆåÆ®°ÔÀÓ) {
	Game game;
	for (int i = 0; i < 12; ++i) {
		game.Roll(10);
	}

	EXPECT_EQ(300, game.Score());
}

TEST(GameTest, DISABLED_»ùÇÃ°ÔÀÓ) {
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
