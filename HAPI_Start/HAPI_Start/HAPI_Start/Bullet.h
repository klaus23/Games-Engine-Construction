#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
private:
	int speed=5;
	Vector2<int>position{ 0,0 };
	Vector2<int>direction{ 0,0 };
	public:
		void Update();

};

