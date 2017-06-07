#pragma once
#include "Renderer2D.h"
using namespace aie;

class Entity;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	Entity* Allocate();
	void Deallocate(Entity* object);
	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Entity** m_pPool;
	int m_nMaxSize;
};