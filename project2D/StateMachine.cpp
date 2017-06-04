#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"
using namespace aie;

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_CurrentStack.Size(); ++i)
	{
		//delete m_CurrentStack[i]; // ASL TEACHER ABOUT DELETING
	}
}

void StateMachine::Update(float deltaTime)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	m_CurrentStack.Top->onUpdate(deltaTime);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	m_CurrentStack.Top->onDraw(m_2dRenderer);
}

void StateMachine::SetState(int nStateIndex)
{
	// Example of Assert
	/*_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;*/

	if (m_CurrentStack.Size() >= 0)
		m_CurrentStack.Top->onExit();

	m_CurrentStack.Push(nStateIndex);
	m_CurrentStack.Top->onEnter();
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_CurrentStack.Push(nStateIndex, pState);
}