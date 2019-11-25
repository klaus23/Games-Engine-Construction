#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;
#include <vector>
class Visualisation;
class Entity;

class World
{
private:

	Vector2<int>position{ 0,0 };
	Vector2<int>direction{ 0,0 };
	std::shared_ptr<Visualisation>m_viz;
	std::vector<Entity*>entityVector;
public:
	bool Initialise(int width, int height);
	void Run();
	void Stars();
	void LoadLevel();
	void FireBullet(ESide side, Vector2<int>direction, Vector2<int>position);
	virtual void Update(World& world) = 0;
	~World();
};

