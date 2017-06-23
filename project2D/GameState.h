// #include, using, etc
#pragma once
#include "State.h"
#include "Texture.h"

class ObjectPool;

//--------------------------------------------------------------------------------------
// GameState object. Inheritance from State.
//--------------------------------------------------------------------------------------
class GameState : public State
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	GameState();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~GameState();

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
	// A pointer to a ObjectPool for dirt.
	//--------------------------------------------------------------------------------------
	ObjectPool* objectPool;

	//--------------------------------------------------------------------------------------
	// A pointer to a Texture m_background.
	//--------------------------------------------------------------------------------------
	Texture* m_background;

	//--------------------------------------------------------------------------------------
	// A pointer to a Texture m_map.
	//--------------------------------------------------------------------------------------
	Texture* m_map;

	//--------------------------------------------------------------------------------------
	// A pointer to a Texture m_player.
	//--------------------------------------------------------------------------------------
	Texture* m_player;
};

