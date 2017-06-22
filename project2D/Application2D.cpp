//#include, using etc
#include "Application2D.h"
#include "Texture.h"
#include "MenuState.h"
#include "GameState.h"
#include "Pause.h"
#include "StartState.h"
#include "LoadingState.h"
#include "SplashScreen.h"
#include "ResourceManager.h"
#include "ShareManager.h"
#include <crtdbg.h>
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Application2D::Application2D() 
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Application2D::~Application2D() 
{
}

//--------------------------------------------------------------------------------------
// startup: Initialize the game.
//
// Returns:
//		bool: Returns a true or false for if the startup is sucessful.
//--------------------------------------------------------------------------------------
bool Application2D::startup() 
{
	// Create a new instance of the Renderer2D
	_ASSERT(m_2dRenderer);
	m_2dRenderer = new Renderer2D();

	// Create ResourceManagers for Audio and Texture
	ResourceManager<Texture>::Create();
	ResourceManager<Audio>::Create();
	ShareManager::create();

	// Create a new instance of the StateMachine
	_ASSERT(m_StateMachine);
	m_StateMachine = new StateMachine();

	// Create each of the games states.
	m_StateMachine->AddState(0, new SplashScreen());
	m_StateMachine->AddState(1, new StartState());
	m_StateMachine->AddState(2, new MenuState());
	m_StateMachine->AddState(3, new LoadingState());
	m_StateMachine->AddState(4, new GameState());
	m_StateMachine->AddState(5, new Pause());
	m_StateMachine->PushState(0);

	return true;
}

//--------------------------------------------------------------------------------------
// shutdown: Called on application shutdown and does all the cleaning up (eg. Deleteing pointers.)
//--------------------------------------------------------------------------------------
void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_StateMachine;
	ShareManager::destroy();
	ResourceManager<Texture>::Destroy();
	ResourceManager<Audio>::Destroy();
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	// Update states from the state machine
	m_StateMachine->Update(deltaTime);

	// A new instance of ShareManager. 
	ShareManager* shareManager = ShareManager::Instance();

	// Check if quit button has been pressed
	if (shareManager->QuitCheck() == true)
	{
		quit();
	}
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw states from the state machine
	m_StateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}