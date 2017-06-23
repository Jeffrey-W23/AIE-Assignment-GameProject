// #include, using, etc
#include "Dirt.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Dirt::Dirt()
{
	// start the active status as false 
	m_bActive = false;
	
	// set dirt postion.
	m_x = 300;
	m_y = 300;

	// start rotation at 0
	m_rot = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Dirt::~Dirt()
{
}

//--------------------------------------------------------------------------------------
// SetActive: A function to set the object to active for the object pool
//
// Param:
//		m_bActive: a bool for if you want the object to be active or not.
//--------------------------------------------------------------------------------------
void Dirt::SetActive(bool bActive)
{
	m_bActive = bActive;
}

//--------------------------------------------------------------------------------------
// GetActive: A function to check if an object is active or not for the object pool.
//--------------------------------------------------------------------------------------
bool Dirt::GetActive()
{
	return m_bActive;
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Dirt::Update(float deltaTime)
{
	// rotate dirt by delta time
	m_rot += deltaTime;

	// Set active to false once the timer is over 10
	if (m_rot > 10)
	{
		SetActive(false);
		m_rot = 0;
	}
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Dirt::Draw(Renderer2D* m_2dRenderer)
{
	// Set the color
	m_2dRenderer->setRenderColour(0.220, 0.137, 0, 1);
	
	// Draw/Render the dirt
	m_2dRenderer->drawSprite(nullptr, m_x, m_y, 124, 8, m_rot);
}