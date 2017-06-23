//#include, using etc
#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
StateMachine::StateMachine()
{
	backUpdate = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
StateMachine::~StateMachine()
{
	while (m_CurrentStack.Size() > 0)
		PopState();

	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

//--------------------------------------------------------------------------------------
// Update: A function to update states over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void StateMachine::Update(float deltaTime)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	//Update in background not needed.
	/*if (backUpdate)
		m_CurrentStack.SecondLast()->onUpdate(deltaTime, this);*/

	m_CurrentStack.Top()->onUpdate(deltaTime, this);
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") states to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	if (backUpdate)
		m_CurrentStack.SecondLast()->onDraw(m_2dRenderer);

	m_CurrentStack.Top()->onDraw(m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// PushState: A function to push a state onto the statemachine stack.
//
// Param:
//		nStateIndex: An int index for the state you want to push
//--------------------------------------------------------------------------------------
void StateMachine::PushState(int nStateIndex)
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	m_CurrentStack.Push(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->onEnter(this);
}

//--------------------------------------------------------------------------------------
// PopState: Take the current state off the stack.
//--------------------------------------------------------------------------------------
void StateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	m_CurrentStack.Pop();

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onEnter(this);
}

//--------------------------------------------------------------------------------------
// PopAll: Take all states off the stack.
//--------------------------------------------------------------------------------------
void StateMachine::PopAll()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	while (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Pop();
	}
}

//--------------------------------------------------------------------------------------
// AddState: A function to render (or "draw") states to the screen.
//
// Param:
//		nStateIndex: An int index for the state.
//		pState: A pointer to a state.
//--------------------------------------------------------------------------------------
void StateMachine::AddState(int nStateIndex, State* pState)
{
	_ASSERT(pState);
	m_StateList.Insert(nStateIndex, pState);
}

//--------------------------------------------------------------------------------------
// SetBackgroundUpdate: A function to turn background updating on or off.
//
// Param:
//		onoff: a bool for turning off and on.
//--------------------------------------------------------------------------------------
void StateMachine::SetBackgroundUpdate(bool onoff)
{
	backUpdate = onoff;
}