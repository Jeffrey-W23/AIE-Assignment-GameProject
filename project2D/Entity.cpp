#include "Entity.h"

Entity::Entity()
{
	m_bActive = false;
}

Entity::~Entity()
{
}

void Entity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool Entity::GetActive()
{
	return m_bActive;
}

void Entity::Update(float deltaTime)
{

}

void Entity::Draw(Renderer2D* m_2dRenderer)
{

}