#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h" 
#include "State.h"
using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void SetState(int nStateIndex);
	void AddState(int nStateIndex, State* pState);

private:
	DynamicArray<State*> m_StateList;
	int m_nCurrentState;
};