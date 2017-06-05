#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"
using namespace aie;

StateMachine::StateMachine()
{
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
	if (m_CurrentStack.Size() <= 0)
		return;

	m_CurrentStack.Top()->onUpdate(deltaTime, this);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	m_CurrentStack.Top()->onDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	// Example of Assert
	/*_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;*/

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit();

	m_CurrentStack.Push(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->onEnter();
}

void StateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onExit();

	m_CurrentStack.Pop();

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->onEnter();
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}