// made in : 김혜승

#pragma once

#include "Main.h"

class LevelUp {
public :
	static int level;

	void run(RenderWindow& window);
	void levelUp() { level++; }
	int getLevelUp() { return level; }
};