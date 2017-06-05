#pragma once
#include "State.h"
#include "Texture.h"
using namespace aie;

class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void onEnter();
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit();

private:
	float m_timer;
	float m_alpha;

	Texture* m_logo;
	Texture* m_background;
};

