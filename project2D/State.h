#pragma once
#include "Renderer2D.h"
using namespace aie;

class State
{
public:
	State();
	~State();

	virtual void onEnter() = 0;
	virtual void onUpdate() = 0;
	virtual void onDraw() = 0;
	virtual void onExit() = 0;
};