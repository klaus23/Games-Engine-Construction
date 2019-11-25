#include "Bullet.h"

void Bullet::Update()
{
	position += direction * speed;
	//check if offscreen
}
