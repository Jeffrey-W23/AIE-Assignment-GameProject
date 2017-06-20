#pragma once
#include "Renderer2D.h"
using namespace aie;

class Dirt
{
public:
	Dirt();
	~Dirt();

	void SetActive(bool m_bActive);
	bool GetActive();
	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	bool m_bActive;
};

