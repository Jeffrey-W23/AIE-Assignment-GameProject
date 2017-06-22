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
}

GameState::~GameState()
{
	delete m_background;
	delete m_map;
	delete m_player;
	delete objectPool;
}

void GameState::onEnter(StateMachine* pMachine)
{}

void GameState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	objectPool->Update(deltaTime);

	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		// do this when I want the bullet to shoot.
		Dirt* pDirt = objectPool->Allocate();
	}

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->PushState(5);
		pMachine->SetBackgroundUpdate(true);
	}
}

void GameState::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_background, 640, 90);

	objectPool->Draw(m_2dRenderer);
}

void GameState::onExit(StateMachine* pMachine)
{

}