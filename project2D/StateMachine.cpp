#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"
using namespace aie;

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}

}

void StateMachine::Update(float deltaTime)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->onUpdate(deltaTime);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->onDraw(m_2dRenderer);
}

void StateMachine::SetState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_nCurrentState >= 0)
		m_StateList[m_nCurrentState]->onExit();

	m_nCurrentState = nStateIndex;
	m_StateList[m_nCurrentState]->onEnter();
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}