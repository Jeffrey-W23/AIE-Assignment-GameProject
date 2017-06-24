// #include, using, etc
#include "GameState.h"
#include "Dirt.h"
#include "ObjectPool.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include "Audio.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
GameState::GameState()
{
	// load object pool with a limit of 10
	objectPool = new ObjectPool(10);
	_ASSERT(objectPool);
	
	// Get a new instance of the resource manager.
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Load m_background texture
	m_background = pTextureManager->LoadResource("./textures/bg.png");
	
	// Load m_map texture
	m_map = pTextureManager->LoadResource("./textures/map.png");
	
	// Load m_player texture
	m_player = pTextureManager->LoadResource("./textures/player.png");
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
GameState::~GameState()
{
	delete objectPool;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void GameState::onEnter(StateMachine* pMachine)
{
	_ASSERT(pMachine);
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void GameState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// update the object pool
	objectPool->Update(deltaTime);

	// Get instance of Input
	Input* input = Input::getInstance();

	// Allocate a piece of dirt to the object pool
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		Dirt* pDirt = objectPool->Allocate();
	}

	// Pause the game
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->PushState(5);
		pMachine->SetBackgroundUpdate(true);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void GameState::onDraw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_2dRenderer);

	// Draw/render the background
	m_2dRenderer->drawSprite(m_background, 640, 90);

	// draw the object pool
	objectPool->Draw(m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void GameState::onExit(StateMachine* pMachine)
{
	_ASSERT(pMachine);
}