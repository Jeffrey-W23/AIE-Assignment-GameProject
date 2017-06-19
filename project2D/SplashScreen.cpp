#include "SplashScreen.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Input.h"
using namespace aie;

SplashScreen::SplashScreen()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_logo = pTextureManager->LoadResource("./textures/teamlogo.png");
	m_background = pTextureManager->LoadResource("./textures/bg-logo.png");
	m_audio = pAudioManager->LoadResource("./audio/teamchime.ogg");
	m_alpha = 0;
	m_timer = 0;
}

SplashScreen::~SplashScreen()
{
	delete m_audio;
	delete m_background;
	delete m_logo;
}

void SplashScreen::onEnter(StateMachine* pMachine)
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

	// input example
	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ENTER) || input->isKeyDown(INPUT_KEY_ESCAPE) || input->isKeyDown(INPUT_KEY_SPACE))
		pMachine->PushState(1);
}

void SplashScreen::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);
	m_2dRenderer->drawSprite(m_background, 640, 360);
	m_2dRenderer->drawSprite(m_logo, 640, 360);
}

void SplashScreen::onExit(StateMachine* pMachine)
{
	m_timer = 0;
}