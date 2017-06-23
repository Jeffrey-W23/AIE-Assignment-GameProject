// #include, using, etc
#include "LoadingState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
LoadingState::LoadingState()
{
	// Get a new instance of the resource manager.
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	// Load new Font
	_ASSERT(m_font);
	m_font = new Font("./font/PressStart.ttf", 28);
	
	// Initialize vars
	m_loadingBar = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
LoadingState::~LoadingState()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void LoadingState::onEnter(StateMachine* pMachine)
{
	// set defaults on entering of state
	m_loadingBar = 0;
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void LoadingState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	// update m_loadingBar by delta time while loading bar isnt finished 
	if (m_loadingBar < 384)
	{
		m_loadingBar += deltaTime * 100;
	}

	// Push to next state once loading bar is finished
	if (m_loadingBar > 384)
	{
		pMachine->PushState(4);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void LoadingState::onDraw(Renderer2D* m_2dRenderer)
{
	// Set the color and draw/ render the "LOADING..." text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "LOADING...", 437, 302);

	// Set the color and draw/ render the loading bar
	m_2dRenderer->setRenderColour(0.927f, 0.384f, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 444, 385, m_loadingBar - 1, 55, 0, 0, 0);

	// Set the color and draw/ render the upper loading bar
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 448, 380, m_loadingBar, 54, 0, 0, 0);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void LoadingState::onExit(StateMachine* pMachine)
{
}