#pragma once
#include "Entity.h"
class Player :
	public Entity
{
private:
	ESide m_side{ ESide::eSidePlayer };
public:
	void Update()override final;
	Player(const std::string& name) :Entity(name) {};
};

