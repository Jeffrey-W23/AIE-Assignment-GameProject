#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState();
	~GameState();

	virtual void onEnter();
	virtual void onUpdate();
	virtual void onDraw();
	virtual void onExit();
};

