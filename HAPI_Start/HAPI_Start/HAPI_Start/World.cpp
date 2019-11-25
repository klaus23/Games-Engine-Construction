#include "World.h"
#include "Visualisation.h"
#include "Entity.h"
#include "Player.h"
bool World::Initialise(int width, int height)
{

	m_viz = std::make_shared<Visualisation>();
	if (!m_viz->CreateSprite("Data\\playerSprite.tga", "Player"))
	{
		return false;
	}
	Player* player = new Player("Player");
	entityVector.push_back(player);
}

void World::Run()
{
	struct Player
	{
		int playerposX;
		int playerposY;
	};
	struct Background
	{
		int backgroundX;
		int backgroundY;
	};
	Player player;
	player.playerposX = 400;
	player.playerposY = 500;
	Background background;
	background.backgroundX = 0;
	background.backgroundY = 0;
	BYTE* screenpointer2 = HAPI.GetScreenPointer();
	while(HAPI.Update())
	{
		

		m_viz->ClearToColour(screenpointer2, 1024, 768, HAPI_TColour::BLACK);


		m_viz->DrawSprite("background", background.backgroundX, background.backgroundY);
		m_viz->DrawSprite("background", background.backgroundX, background.backgroundY - m_viz->GetHeight());
		m_viz->DrawSprite("background", background.backgroundX, background.backgroundY + m_viz->GetHeight());
		m_viz->DrawSprite("Player", player.playerposX, player.playerposY);
		background.backgroundY += 5;
		if (background.backgroundY >= m_viz->GetHeight())
		{

			background.backgroundY = 0;
		}
		if (background.backgroundY <= -m_viz->GetHeight())
		{
			background.backgroundY = 0;
		}
		const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
		const HAPI_TControllerData& data = HAPI.GetControllerData(0);
		if (keyData.scanCode[HK_DOWN] || data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -15000)
		{
			//if (SpriteY < height - textureheight)
			//{
			player.playerposY += 5;
			// background.backgroundY -= 10;
			/* if (background.backgroundY <= -visualisation.GetHeight())
			 {
				 background.backgroundY = 0;
			 }*/
			 //}

		};

		if (keyData.scanCode[HK_UP] || data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > 15000)
		{
			//if (SpriteY > 1)
			//{
			player.playerposY -= 5;
			//background.backgroundY += 10;
			/*if (background.backgroundY >= visualisation.GetHeight())
			{

				background.backgroundY=0;
			}*/
			//}

		};

		if (keyData.scanCode[HK_LEFT] || data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -15000)
		{
			//if (SpriteX > 1)
			//{
			player.playerposX -= 5;
			//}
		};

		if (keyData.scanCode[HK_RIGHT] || data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > 15000)
		{
			//if (SpriteX < width - texturewidth )
			//{
			player.playerposX += 5;
			//}
		}

	}
}

void World::Stars()
{
	/*const int num_Stars = 1000;
	struct StarPositions
	{
		int xpos;
		int ypos;
		int zpos;
	};

	StarPositions StarPosition[num_Stars];

	for (int stars{ 0 }; stars < num_Stars; stars++)
	{


		StarPosition[stars].xpos = rand() % screenWidth;
		StarPosition[stars].ypos = rand() % screenHeight;
		StarPosition[stars].zpos = rand() % 385;
	}
	int eyeDistance = 50;
	int Cx = screenWidth / 2;
	int Cy = screenHeight / 2;*/

	/*for (int stars{ 0 }; stars < num_Stars; stars++)
	{
		float Sx = ((eyeDistance * (StarPosition[stars].xpos - Cx)) / (StarPosition[stars].zpos + eyeDistance)) + Cx;

		float Sy = ((eyeDistance * (StarPosition[stars].ypos - Cy)) / (StarPosition[stars].zpos + eyeDistance)) + Cy;
		int offset = (Sx + Sy * screenWidth) * 4;
		memcpy(screen + offset, &random, 4);
		StarPosition[stars].zpos -= 0.25f;
		if (StarPosition[stars].zpos <= 0)
		{
			StarPosition[stars].xpos = rand() % screenWidth;
			StarPosition[stars].ypos = rand() % screenHeight;
			StarPosition[stars].zpos = 500;
		}
	}*/

}

void World::LoadLevel()
{

	HAPI.SetShowFPS(true);
	m_viz->CreateSprite("Data\\galaxy.jpg", "background");
}

void World::FireBullet(ESide side, Vector2<int> direction, Vector2<int> position)
{
	size_t firstBulletIndex;
	firstBulletIndex = entityVector.size();
	size_t numBullets = 200;
	for (int i=0;i<numBullets;i++ )
	{
		if ((entityVector[i] + firstBulletIndex)->isAlive)
		{
			//entityVector[i]->isAlive = true;
			//spawn this
		}
	}
}

World::~World()
{
	for (auto& entity : entityVector)
	{
		delete entity;
	}
}
