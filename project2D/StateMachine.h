#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "State.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void AddState(int nStateIndex, State* pState);
	void PopState();

private:
	DynamicArray<State*> m_StateList;
	Stack<State*> m_CurrentStack;
};