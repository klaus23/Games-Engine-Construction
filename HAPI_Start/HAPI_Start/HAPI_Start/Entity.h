#pragma once
#include "World.h"
#include "Vector2.h"
enum class ESide {
	eSidePlayer,
	eSideEnemy,
	eSideNeutral
};
class Entity :
	public World
{
protected:
	Vector2<int>position{ 0,0 };
	ESide m_side{ ESide::eSideNeutral };
	int health=0;
	int damage=0;
	std::string(gfx_Name);
	bool isAlive{ false };
public:
	virtual ~Entity() = default;
	 Entity(const std::string&name):gfx_Name(name){}
	 virtual void Update() = 0;
	 bool isAlive() { return false; }
};

