// #include, using, etc
#include "StartState.h"
#include "StateMachine.h"
#include "Input.h"
#include "ResourceManager.h"
#include "ShareManager.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
StartState::StartState()
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
	m_timer = 0;
	m_flashText = 0;
	m_logoPos = 460;
	m_alpha = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
StartState::~StartState()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void StartState::onEnter(StateMachine* pMachine)
{
	// set defaults on entering of state
	m_timer = 3;
	m_flashText = 1;
	m_alpha = 0;

	// Get a new instance of the share manager
	ShareManager* shareManager = ShareManager::Instance();

	// Play muisic, set to loop and stop the last played song.
	shareManager->PlayAudio("menu");
	shareManager->SetAudioLoop("menu", true);
	shareManager->StopAudio("chime");
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void StartState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	// upadte m_logoPos, m_timer and m_alpha by deltatime
	m_logoPos -= deltaTime * 150;
	m_alpha += deltaTime * 0.5f;
	m_timer += deltaTime;

	// Get instance of Input
	Input* input = Input::getInstance();

	// Get a new instance of the share manager
	ShareManager* shareManager = ShareManager::Instance();

	// Push to the next state on enter or space press
	if (input->wasKeyPressed(INPUT_KEY_ENTER) || input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		shareManager->PlayAudio("enter");
		pMachine->PushState(2);
	}
	
	// Stop logopos from moving
	if (m_logoPos < 460)
		m_logoPos = 460;

	// flash text every 4 seconds
	if (m_timer > 4)
		m_flashText = 0;
	
	// reset flash text
	if (m_timer > 4.5)
	{
		m_flashText = 1;
		m_timer -= m_timer;
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void StartState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw/Render the m_background
	m_2dRenderer->drawSprite(m_background, 640, 90);

	// Set the color and draw / render logo
	m_2dRenderer->setRenderColour(1, 1, 1, m_alpha);
	m_2dRenderer->drawSprite(m_logo, 640, m_logoPos);

	// Set the color and draw/ render "PUSH START BUTTON" text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, m_flashText);
	m_2dRenderer->drawText(m_font, "PUSH START BUTTON", 404, 245);

	// Set the color and draw/render piquant text.
	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "(C) 2017 PIQUANT INTERACTIVE", 244, 185);
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void StartState::onExit(StateMachine* pMachine)
{
	m_logoPos = 600;
}