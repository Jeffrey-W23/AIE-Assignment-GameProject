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
	void SetPos(float x, float y);
	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	bool m_bActive;
	float m_x;
	float m_y;
};