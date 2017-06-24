//#include, using etc
#include "ObjectPool.h"
#include "Dirt.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;

	m_pPool = new Dirt*[nMaxSize];
	_ASSERT(m_pPool);

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Dirt();
		_ASSERT(m_pPool[i]);
	}
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}

	delete[] m_pPool;
}

//--------------------------------------------------------------------------------------
// Allocate: A function to Allocate objects to the object pool.
//
// Return:
//		Dirt: Returns a pointer to dirt.
//--------------------------------------------------------------------------------------
Dirt* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->GetActive())
		{
			m_pPool[i]->SetActive(true);
			return m_pPool[i];
		}
	}

	return nullptr;
}

//--------------------------------------------------------------------------------------
// Deallocate: A function to Deallocate objects from the object pool.
//
// Param:
//		Dirt: takes in a Dirt pointer for the object to deallocate.
//--------------------------------------------------------------------------------------
void ObjectPool::Deallocate(Dirt* object)
{
	_ASSERT(object);

	object->SetActive(false);
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects over time in the object pool.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void ObjectPool::Update(float deltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Update(deltaTime);
		}
	}
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen in the object pool.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void ObjectPool::Draw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_2dRenderer);

	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Draw(m_2dRenderer);
		}
	}
}