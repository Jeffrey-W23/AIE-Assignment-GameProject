#include "ObjectPool.h"
#include "Dirt.h"
#include <crtdbg.h>

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;

	_ASSERT(m_pPool);
	m_pPool = new Dirt*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Dirt();
	}
}

ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete[] m_pPool[i];
	}

	delete[] m_pPool;
}

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

void ObjectPool::Deallocate(Dirt* object)
{
	object->SetActive(false);
}

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

void ObjectPool::Draw(Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Draw(m_2dRenderer);
		}
	}
}