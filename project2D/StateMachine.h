//#include, using etc
#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "State.h"
#include "Stack.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// ShareManager object.
//--------------------------------------------------------------------------------------
class StateMachine
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	StateMachine();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~StateMachine();

	//--------------------------------------------------------------------------------------
	// Update: A function to update states over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);
	
	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") states to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// PushState: A function to push a state onto the statemachine stack.
	//
	// Param:
	//		nStateIndex: An int index for the state you want to push
	//--------------------------------------------------------------------------------------
	void PushState(int nStateIndex);

	//--------------------------------------------------------------------------------------
	// AddState: A function to render (or "draw") states to the screen.
	//
	// Param:
	//		nStateIndex: An int index for the state.
	//		pState: A pointer to a state.
	//--------------------------------------------------------------------------------------
	void AddState(int nStateIndex, State* pState);

	//--------------------------------------------------------------------------------------
	// PopState: Take the current state off the stack.
	//--------------------------------------------------------------------------------------
	void PopState();

	//--------------------------------------------------------------------------------------
	// PopAll: Take all states off the stack.
	//--------------------------------------------------------------------------------------
	void PopAll();

	//--------------------------------------------------------------------------------------
	// SetBackgroundUpdate: A function to turn background updating on or off.
	//
	// Param:
	//		onoff: a bool for turning off and on.
	//--------------------------------------------------------------------------------------
	void SetBackgroundUpdate(bool onoff);

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of State pointers m_StateList
	//--------------------------------------------------------------------------------------
	DynamicArray<State*> m_StateList;

	//--------------------------------------------------------------------------------------
	// A Stack of State pointers m_CurrentStack
	//--------------------------------------------------------------------------------------
	Stack<State*> m_CurrentStack;

	//--------------------------------------------------------------------------------------
	// A bool backUpdate for if the background state should be updated or not
	//--------------------------------------------------------------------------------------
	bool backUpdate;
};