#include "GameState.h"
#include "Dirt.h"
#include "ObjectPool.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include "Audio.h"

GameState::GameState()
{
	objectPool = new ObjectPool(10);
	
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_background = pTextureManager->LoadResource("./textures/bg.png");
	m_map = pTextureManager->LoadResource("./textures/map.png");
	m_player = pTextureManager->LoadResource("./textures/player.png");

	m_cameraX = 0;
	m_cameraY = 7380;
}

GameState::~GameState()
{
}

void GameState::onEnter(StateMachine* pMachine)
{}

void GameState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	objectPool->Update(deltaTime);

	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		// do this when I want the bullet to shoot.
		Dirt* pDirt = objectPool->Allocate();
		pDirt->SetPos(m_cameraX + 250, m_cameraY + 250);
	}

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->PushState(5);
		pMachine->SetBackgroundUpdate(true);
	}
}

void GameState::onDraw(Renderer2D* m_2dRenderer)
{
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->drawSprite(m_background, 640, 90);
	//m_2dRenderer->drawSprite(m_map, 640, 90, 16384, 16384);

	objectPool->Draw(m_2dRenderer);

	//m_2dRenderer->setRenderColour(0.220, 0.137, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 608, 7335, 70, m_timer, 0 ,0 ,0 ,0);
}

void GameState::onExit(StateMachine* pMachine)
{

}