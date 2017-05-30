#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	void SetActive(bool m_bActive);
	bool GetActive();

private:
	bool m_bActive;
};