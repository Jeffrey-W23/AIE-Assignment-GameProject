//#include, using etc
#pragma once
#include "Renderer2D.h"
using namespace aie;

class Dirt;

//--------------------------------------------------------------------------------------
// ObjectPool object.
//--------------------------------------------------------------------------------------
class ObjectPool
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	ObjectPool(int nMaxSize);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~ObjectPool();

	//--------------------------------------------------------------------------------------
	// Allocate: A function to Allocate objects to the object pool.
	//
	// Return:
	//		Dirt: Returns a pointer to dirt.
	//--------------------------------------------------------------------------------------
	Dirt* Allocate();

	//--------------------------------------------------------------------------------------
	// Deallocate: A function to Deallocate objects from the object pool.
	//
	// Param:
	//		Dirt: takes in a Dirt pointer for the object to deallocate.
	//--------------------------------------------------------------------------------------
	void Deallocate(Dirt* object);

	//--------------------------------------------------------------------------------------
	// Update: A function to update objects over times.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:

	//--------------------------------------------------------------------------------------
	// A double pointer to Dirt m_pPool.
	//--------------------------------------------------------------------------------------
	Dirt** m_pPool;

	//--------------------------------------------------------------------------------------
	// A float m_nMaxSize for setting the max size of the object pool
	//--------------------------------------------------------------------------------------
	int m_nMaxSize;
};