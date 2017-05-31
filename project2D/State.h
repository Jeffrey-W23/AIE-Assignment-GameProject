#pragma once
#include "Renderer2D.h"
using namespace aie;

class State
{
public:
	State();
	~State();

	virtual void onEnter() = 0;
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw(Renderer2D* m_2dRenderer) = 0;
	virtual void onExit() = 0;
};