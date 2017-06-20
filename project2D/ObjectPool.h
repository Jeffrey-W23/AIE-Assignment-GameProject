#pragma once
#include "Renderer2D.h"
using namespace aie;

class Dirt;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	Dirt* Allocate();
	void Deallocate(Dirt* object);
	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Dirt** m_pPool;
	int m_nMaxSize;
};