#pragma once
#include "State.h"
#include "font.h"
#include "Texture.h"
#include "Audio.h"
using namespace aie;

class StartState : public State
{
public:
	StartState();
	~StartState();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);

private:
	Font* m_font;
};