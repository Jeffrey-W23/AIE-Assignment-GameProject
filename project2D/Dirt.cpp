#include "Dirt.h"

Dirt::Dirt()
{
	m_bActive = false;
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
}

void Dirt::Draw(Renderer2D* m_2dRenderer)
{

}