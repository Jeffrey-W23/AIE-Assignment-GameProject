#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);
};

