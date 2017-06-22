#include "Dirt.h"

Dirt::Dirt()
{
	m_bActive = false;
	m_x = 300;
	m_y = 300;
	m_rot = 0;
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

void Dirt::Update(float deltaTime)
{
	//timer for setting active back to false
	m_rot += deltaTime;

	if (m_rot > 10)
	{
		SetActive(false);
		m_rot = 0;
	}
}

void Dirt::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0.220, 0.137, 0, 1);
	m_2dRenderer->drawSprite(nullptr, m_x, m_y, 124, 8, m_rot);
}