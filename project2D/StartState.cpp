#include "StartState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include <crtdbg.h>

StartState::StartState()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	_ASSERT(m_font);
	m_font = new Font("./font/consolas.ttf", 32);
}

StartState::~StartState()
{
	delete m_font;
}

void StartState::onEnter(StateMachine* pMachine)
{
}

void StartState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	// input example
	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ENTER))
		pMachine->PushState(2);
}

void StartState::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "PUSH START BUTTON", 0, 720 - 64);
}

void StartState::onExit(StateMachine* pMachine)
{

}