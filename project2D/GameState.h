#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void onEnter();
	void onUpdate(float deltaTime);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit();
};

