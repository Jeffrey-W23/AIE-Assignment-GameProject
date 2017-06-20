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
}

GameState::~GameState()
{
}

void GameState::onEnter(StateMachine* pMachine)
{}

void GameState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	// do this when I want the bullet to shoot.
	Dirt* pDirt = objectPool->Allocate();

	objectPool->Update(deltaTime);


	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->PushState(5);
		pMachine->SetBackgroundUpdate(true);
	}
}

void GameState::onDraw(Renderer2D* m_2dRenderer)
{
	objectPool->Draw(m_2dRenderer);
	m_2dRenderer->drawSprite(m_background, 640, 90);
}

void GameState::onExit(StateMachine* pMachine)
{

}