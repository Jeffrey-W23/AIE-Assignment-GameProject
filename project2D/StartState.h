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
	float m_timer;
	float m_flashText;
	float m_logoPos;
	float m_alpha;

	Font* m_font;
	Texture* m_logo;
	Texture* m_background;
};