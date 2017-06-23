// #include, using, etc
#pragma once
#include "State.h"

//--------------------------------------------------------------------------------------
// Pause object. Inheritance from State.
//--------------------------------------------------------------------------------------
class Pause : public State
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Pause();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Pause();

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
	// A pointer to a Font m_font2.
	//--------------------------------------------------------------------------------------
	Font* m_font2;

	//--------------------------------------------------------------------------------------
	// A float m_selectorPos for the position of the menu selector
	//--------------------------------------------------------------------------------------
	float m_selectorPos;
};