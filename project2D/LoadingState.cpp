#include "LoadingState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include <crtdbg.h>

LoadingState::LoadingState()
{
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	_ASSERT(m_font);
	m_font = new Font("./font/PressStart.ttf", 28);
	m_loadingBar = 0;
}

LoadingState::~LoadingState()
{
	delete m_font;
}

void LoadingState::onEnter(StateMachine* pMachine)
{
}

void LoadingState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	if (m_loadingBar < 384)
	{
		m_loadingBar += deltaTime * 100;
	}

	if (m_loadingBar > 384)
	{
		pMachine->PushState(4);
	}
}

void LoadingState::onDraw(Renderer2D* m_2dRenderer)
{
	//m_2dRenderer->setRenderColour(1, 1, 1, m_alpha); // Color wont change?
	//m_2dRenderer->drawSprite(m_logo, 640, m_logoPos);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "LOADING...", 437, 302);

	//Back
	m_2dRenderer->setRenderColour(0.927f, 0.384f, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 444, 385, m_loadingBar - 1, 55, 0, 0, 0);

	// Front
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 448, 380, m_loadingBar, 54, 0, 0, 0);
}

void LoadingState::onExit(StateMachine* pMachine)
{

}