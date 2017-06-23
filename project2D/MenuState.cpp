// #include, using, etc
#include "MenuState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include "ShareManager.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
MenuState::MenuState()
{
	// Get a new instance of the resource manager.
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Load logo texture
	m_logo = pTextureManager->LoadResource("./textures/menutext3.png");

	// Load background texture
	m_background = pTextureManager->LoadResource("./textures/bg.png");

	// Load new Font
	_ASSERT(m_font);
	m_font = new Font("./font/PressStart.ttf", 28);

	// Initialize vars
	m_logoPos = 0;
	m_alpha = 0;
	m_selectorPos = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
MenuState::~MenuState()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MenuState::onEnter(StateMachine* pMachine)
{
	// set defaults on entering of state
	m_logoPos = 460;
	m_alpha = 1;
	m_selectorPos = 440;
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MenuState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	// upadte m_logoPos and m_alpha by deltatime
	m_logoPos += deltaTime * 150;
	m_alpha -= deltaTime * 0.94f;

	// Stop logopos from moving
	if (m_logoPos > 1000)
		m_logoPos = 1000;

	// Get instance of Input
	Input* input = Input::getInstance();

	// Get a new instance of the share manager
	ShareManager* shareManager = ShareManager::Instance();

	// pop back a state on pressing of the esc key
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		shareManager->PlayAudio("back");
		pMachine->PopState();
	}

	// Move the menu selector up when pressing W
	if (input->wasKeyPressed(INPUT_KEY_W) && m_selectorPos < 440 || input->wasKeyPressed(INPUT_KEY_UP) && m_selectorPos < 440)
	{
		shareManager->PlayAudio("select");
		m_selectorPos += 60;
	}

	// Move the menu selector down when pressing S
	if (input->wasKeyPressed(INPUT_KEY_S) && m_selectorPos > 380 || input->wasKeyPressed(INPUT_KEY_DOWN) && m_selectorPos > 380)
	{
		shareManager->PlayAudio("select");
		m_selectorPos -= 60;
	}

	// Push next state to loading screen if play is selected
	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 440 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 440)
	{
		shareManager->PlayAudio("enter");
		pMachine->PushState(3);
	}

	// Quit game if exit option is selected.
	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 380 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 380)
	{
		shareManager->StopAllAudio();
		shareManager->Quit(true);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void MenuState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw/Render the m_background
	m_2dRenderer->drawSprite(m_background, 640, 90);

	// Set the color and draw/ render the logo
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);
	m_2dRenderer->drawSprite(m_logo, 640, m_logoPos);

	// Set the color and draw/ render "START" and "EXIT" text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "START", 574, 425);
	m_2dRenderer->drawText(m_font, "EXIT", 588, 365);

	// Set the color and draw/ render the m_selectorPos.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawBox(530, m_selectorPos, 28, 28);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MenuState::onExit(StateMachine* pMachine)
{
}