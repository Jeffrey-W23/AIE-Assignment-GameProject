#pragma once
#include "State.h"
#include "Texture.h"

class ObjectPool;

class GameState : public State
{
public:
	GameState();
	~GameState();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);

private:
	ObjectPool* objectPool;
	Texture* m_background;
	Texture* m_map;
	Texture* m_player;
};

