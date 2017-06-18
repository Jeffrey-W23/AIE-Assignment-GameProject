#include "StartState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include <crtdbg.h>

StartState::StartState()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_logo = pTextureManager->LoadResource("./textures/menutext.png");
	m_background = pTextureManager->LoadResource("./textures/bg.png");

	_ASSERT(m_font);
	m_font = new Font("./font/PressStart.ttf", 28);

	m_timer = 0;
	m_flashText = 0;
	m_logoPos = 460;
	m_alpha = 0;
}

StartState::~StartState()
{
	delete m_font;
	delete m_logo;
	delete m_background;
}

void StartState::onEnter(StateMachine* pMachine)
{
	m_timer = 0;
	m_flashText = 1;
	m_alpha = 0;
}

void StartState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_logoPos -= deltaTime * 150;
	m_alpha += deltaTime * 0.5f;

	// input example
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
		pMachine->PushState(2);

	m_timer += deltaTime;
	
	if (m_logoPos < 460)
		m_logoPos = 460;

	if (m_timer > 4)
		m_flashText = 0;
	
	if (m_timer > 4.5)
	{
		m_flashText = 1;
		m_timer -= m_timer;
	}
}

void StartState::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_background, 640, 90);

	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha); // Color wont change?
	m_2dRenderer->drawSprite(m_logo, 640, m_logoPos);

	m_2dRenderer->setRenderColour(1, 1, 0, m_flashText); // Color wont change?
	m_2dRenderer->drawText(m_font, "PUSH START BUTTON", 404, 245);

	m_2dRenderer->setRenderColour(160, 47, 0, 1); // Color wont change?
	m_2dRenderer->drawText(m_font, "© 2015 PIQUANT INTERACTIVE", 280, 185);
}

void StartState::onExit(StateMachine* pMachine)
{
	m_logoPos = 600;
}