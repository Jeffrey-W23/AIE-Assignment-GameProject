// #include, using, etc
#pragma once
#include "State.h"
#include "font.h"
#include "Audio.h"

//--------------------------------------------------------------------------------------
// LoadingState object. Inheritance from State.
//--------------------------------------------------------------------------------------
class LoadingState : public State
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	LoadingState();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~LoadingState();

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
	// A pointer to a Font m_font.
	//--------------------------------------------------------------------------------------
	Font* m_font;

	//--------------------------------------------------------------------------------------
	// A float m_loadingBar for the position of the loading bar
	//--------------------------------------------------------------------------------------
	float m_loadingBar;
};