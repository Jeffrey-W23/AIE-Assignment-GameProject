#pragma once
#include "State.h"


class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	void onEnter();
	void onUpdate(float deltaTime);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit();
};

