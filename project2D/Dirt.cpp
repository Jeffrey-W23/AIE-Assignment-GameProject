#include "Dirt.h"

Dirt::Dirt()
{
	m_bActive = false;
	m_x = 0;
	m_y = 0;
}

Dirt::~Dirt()
{
}

void Dirt::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool Dirt::GetActive()
{
	return m_bActive;
}

void Dirt::SetPos(float x, float y)
{
		m_x = x;
		m_y = y;
}

void Dirt::Update(float deltaTime)
{
	//timer for setting active back to false
}

void Dirt::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0.220, 0.137, 0, 1);
	m_2dRenderer->drawSprite(nullptr, m_x, m_y, 70, 70, 0, 0, 0, 0);
}