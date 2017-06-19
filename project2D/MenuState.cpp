#include "MenuState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include "ShareManager.h"
#include <crtdbg.h>

MenuState::MenuState()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_logo = pTextureManager->LoadResource("./textures/menutext3.png");
	m_background = pTextureManager->LoadResource("./textures/bg.png");

	_ASSERT(m_font);
	m_font = new Font("./font/PressStart.ttf", 28);

	m_logoPos = 0;
	m_alpha = 0;
	m_selectorPos = 0;
}

MenuState::~MenuState()
{
	delete m_font;
	delete m_logo;
	delete m_background;
}

void MenuState::onEnter(StateMachine* pMachine)
{
	m_logoPos = 460;
	m_alpha = 1;
	m_selectorPos = 440;
}

void MenuState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_logoPos += deltaTime * 150;
	m_alpha -= deltaTime * 0.94f;

	if (m_logoPos > 1000)
		m_logoPos = 1000;

	Input* input = Input::getInstance();
	ShareManager* shareManager = ShareManager::Instance();

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
		pMachine->PopState();

	if (input->wasKeyPressed(INPUT_KEY_W) && m_selectorPos < 440 || input->wasKeyPressed(INPUT_KEY_UP) && m_selectorPos < 440)
		m_selectorPos += 60;

	if (input->wasKeyPressed(INPUT_KEY_S) && m_selectorPos > 380 || input->wasKeyPressed(INPUT_KEY_DOWN) && m_selectorPos > 380)
		m_selectorPos -= 60;

	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 440 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 440)
		pMachine->PushState(3);

	// Hopw do I get this working
	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 380 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 380)
		shareManager->Quit(true);
}

void MenuState::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_background, 640, 90);

	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha); // Color wont change?
	m_2dRenderer->drawSprite(m_logo, 640, m_logoPos);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "START", 574, 425);
	m_2dRenderer->drawText(m_font, "EXIT", 588, 365);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawBox(530, m_selectorPos, 28, 28);
}

void MenuState::onExit(StateMachine* pMachine)
{

}