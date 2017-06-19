#pragma once
#include "State.h"
#include "font.h"
#include "Audio.h"

class LoadingState : public State
{
public:
	LoadingState();
	~LoadingState();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);

private:
	Font* m_font;

	float m_loadingBar;
};