#include "SplashScreen.h"
#include "StateMachine.h"

SplashScreen::SplashScreen()
{
	m_logo = new Texture("./textures/teamlogo.png");
	m_background = new Texture("./textures/bg-logo.png");
	m_alpha = 0;
	m_timer = 0;
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::onEnter()
{

}

void SplashScreen::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_timer += deltaTime;
	m_alpha += deltaTime * 0.1f;
		
	if (m_timer > 8)
	{
		pMachine->PushState(1);
	}
}

void SplashScreen::onDraw(Renderer2D* m_2dRenderer)
{
	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);
	//m_2dRenderer->setRenderColour(1, 1, 1, 0.09f);
	m_2dRenderer->drawSprite(m_background, 640, 360);
	m_2dRenderer->drawSprite(m_logo, 640, 360);
}

void SplashScreen::onExit()
{

}