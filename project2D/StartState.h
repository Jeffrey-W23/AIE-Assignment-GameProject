#pragma once
#include "State.h"
#include "font.h"
using namespace aie;

class StartState : public State
{
public:
	StartState();
	~StartState();

	void onEnter();
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit();

private:
	Font* m_font;
};