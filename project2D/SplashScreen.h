// #include, using, etc
#pragma once
#include "State.h"
#include "Texture.h"
#include "Audio.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// SplashScreen object. Inheritance from State.
//--------------------------------------------------------------------------------------
class SplashScreen : public State
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	SplashScreen();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~SplashScreen();

	//--------------------------------------------------------------------------------------
	// onEnter: A virtual function from state that runs first when a state is loaded.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onEnter(StateMachine* pMachine);

	//--------------------------------------------------------------------------------------
	// onUpdate: A virtual function from state to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onUpdate(float deltaTime, StateMachine* pMachine);
	
	//--------------------------------------------------------------------------------------
	// onDraw: A virtual function from state to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void onDraw(Renderer2D* m_2dRenderer);
	
	//--------------------------------------------------------------------------------------
	// onExit: A virtual function from state that runs on state exit.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onExit(StateMachine* pMachine);

private:

	//--------------------------------------------------------------------------------------
	// A float m_timer for timing when to move to the next state.
	//--------------------------------------------------------------------------------------
	float m_timer;

	//--------------------------------------------------------------------------------------
	// A float m_alpha for dimming the background and logo
	//--------------------------------------------------------------------------------------
	float m_alpha;

	//--------------------------------------------------------------------------------------
	// A pointer to a Texture m_logo.
	//--------------------------------------------------------------------------------------
	Texture* m_logo;

	//--------------------------------------------------------------------------------------
	// A pointer to a Texture m_background.
	//--------------------------------------------------------------------------------------
	Texture* m_background;
};

