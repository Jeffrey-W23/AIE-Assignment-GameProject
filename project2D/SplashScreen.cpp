#include "SplashScreen.h"
#include "StateMachine.h"

SplashScreen::SplashScreen()
{
	m_logo = new Texture("./textures/teamlogo.png");
	m_background = new Texture("./textures/bg-logo.png");
	m_audio = new Audio("./audio/teamchime.ogg");
	m_alpha = 0;
	m_timer = 0;
}

SplashScreen::~SplashScreen()
{
	delete m_audio;
	delete m_background;
	delete m_logo;
}

void SplashScreen::onEnter()
{
	m_audio->play();
	m_alpha = 0;
	m_timer = 0;
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
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);
	m_2dRenderer->drawSprite(m_background, 640, 360);
	m_2dRenderer->drawSprite(m_logo, 640, 360);
}

void SplashScreen::onExit()
{

}