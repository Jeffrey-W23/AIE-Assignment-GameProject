#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"
using namespace aie;

StateMachine::StateMachine()
{
	backUpdate = false;
}

StateMachine::~StateMachine()
{
	while (m_CurrentStack.Size() > 0)
		PopState();

	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float deltaTime)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	//Update in background
	/*if (backUpdate)
		m_CurrentStack.SecondLast()->onUpdate(deltaTime, this);*/

	m_CurrentStack.Top()->onUpdate(deltaTime, this);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	if (backUpdate)
		m_CurrentStack.SecondLast()->onDraw(m_2dRenderer);

	m_CurrentStack.Top()->onDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	m_CurrentStack.Push(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->onEnter(this);
}

void StateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	m_CurrentStack.Pop();

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onEnter(this);
}

void StateMachine::PopAll()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit(this);

	while (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Pop();
	}
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::SetBackgroundUpdate(bool onoff)
{
	backUpdate = onoff;
}