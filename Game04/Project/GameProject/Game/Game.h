#pragma once
#include "../Base/Base.h"

class Game :public Base {
public:
	bool GameClear_flag = 0;
	bool GameOver_flag = 0;
	
	Game();
	~Game();
	void Update();
};