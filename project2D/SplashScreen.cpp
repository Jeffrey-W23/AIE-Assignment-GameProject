// #include, using, etc
#include "SplashScreen.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Input.h"
#include "ShareManager.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
SplashScreen::SplashScreen()
{
	// Get a new instance of the resource manager.
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Load logo texture
	m_logo = pTextureManager->LoadResource("./textures/teamlogo.png");
	
	// Load background texture
	m_background = pTextureManager->LoadResource("./textures/bg-logo.png");

	// Initialize vars
	m_alpha = 0;
	m_timer = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
SplashScreen::~SplashScreen()
{
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void SplashScreen::onEnter(StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// set defaults on entering of state
	m_alpha = 0;
	m_timer = 0;

	// Get a new instance of the share manager
	ShareManager* shareManager = ShareManager::Instance();

	// play opening chime
	shareManager->PlayAudio("chime");
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void SplashScreen::onUpdate(float deltaTime, StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// upadte timer and alpha by deltatime
	m_timer += deltaTime;
	m_alpha += deltaTime * 0.1f;
		
	// Once timer is over 8 push to next state.
	if (m_timer > 8)
	{
		pMachine->PushState(1);
	}

	// Get instance of Input
	Input* input = Input::getInstance();

	// Push to next state if you push one of the following keys.
	if (input->isKeyDown(INPUT_KEY_ENTER) || input->isKeyDown(INPUT_KEY_ESCAPE) || input->isKeyDown(INPUT_KEY_SPACE))
		pMachine->PushState(1);
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void SplashScreen::onDraw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_2dRenderer);

	// Set the color
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);

	// Draw/Render the m_background
	m_2dRenderer->drawSprite(m_background, 640, 360);

	// Draw/Render the m_logo
	m_2dRenderer->drawSprite(m_logo, 640, 360);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void SplashScreen::onExit(StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// set timer to 0
	m_timer = 0;
}