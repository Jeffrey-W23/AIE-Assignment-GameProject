#include "Pause.h"
#include "Input.h"
#include "font.h"
#include "ShareManager.h"
#include "StateMachine.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Pause::Pause()
{
	// Load new Font1
	m_font = new Font("./font/PressStart.ttf", 45);
	_ASSERT(m_font);

	// Load new Font2
	m_font2 = new Font("./font/PressStart.ttf", 32);
	_ASSERT(m_font2);

	// Initialize vars
	m_selectorPos = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Pause::~Pause()
{
	delete m_font;
	delete m_font2;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void Pause::onEnter(StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// set defaults on entering of state
	m_selectorPos = 444;
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void Pause::onUpdate(float deltaTime, StateMachine* pMachine)
{
	_ASSERT(pMachine);

	// Get instance of Input
	Input* input = Input::getInstance();

	// Get a new instance of the share manager
	ShareManager* shareManager = ShareManager::Instance();

	// Unpause the game and pop back to the game
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopState();
	}

	// Move the menu selector up when pressing W
	if (input->wasKeyPressed(INPUT_KEY_W) && m_selectorPos < 444 || input->wasKeyPressed(INPUT_KEY_UP) && m_selectorPos < 444)
	{
		shareManager->PlayAudio("select");
		m_selectorPos += 60;
	}

	// Move the menu selector down when pressing S
	if (input->wasKeyPressed(INPUT_KEY_S) && m_selectorPos > 384 || input->wasKeyPressed(INPUT_KEY_DOWN) && m_selectorPos > 384)
	{
		shareManager->PlayAudio("select");
		m_selectorPos -= 60;
	}

	// Unpause the game and pop back to the game
	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 444 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 444)
	{
		shareManager->PlayAudio("enter");
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopState();
	}

	// Return to the menu. Pop all states off the stack, push the start state.
	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 384 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 384)
	{
		shareManager->PlayAudio("enter");
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopAll();
		pMachine->PushState(1);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Pause::onDraw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_2dRenderer);

	// Set the color and draw/ render a black transparent square that takes up the whole pause screen
	m_2dRenderer->setRenderColour(0, 0, 0, 0.8);
	m_2dRenderer->drawSprite(nullptr, 0, 0, 1280, 720, 0, 0, 0);

	// Set the color and draw/ render the "PAUSED" text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "PAUSED!", 493, 525);

	// Set the color and draw/ render "RESUME" and "MENU" text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font2, "RESUME", 549, 425);
	m_2dRenderer->drawText(m_font2, "MENU", 575, 365);

	// Set the color and draw/ render the m_selectorPos.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawBox(490, m_selectorPos, 28, 28);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void Pause::onExit(StateMachine* pMachine)
{
	_ASSERT(pMachine);
}