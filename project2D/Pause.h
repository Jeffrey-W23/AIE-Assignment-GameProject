#pragma once
#include "State.h"

class Pause : public State
{
public:
	Pause();
	~Pause();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);

private:
	Font* m_font;
	Font* m_font2;
	float m_selectorPos;
};