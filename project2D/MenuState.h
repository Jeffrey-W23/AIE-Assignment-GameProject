#pragma once
#include "State.h"
#include "font.h"
#include "Texture.h"
#include "Audio.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	void onEnter(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit(StateMachine* pMachine);

private:
	float m_logoPos;
	float m_alpha;
	float m_selectorPos;

	Font* m_font;
	Texture* m_logo;
	Texture* m_background;
};

