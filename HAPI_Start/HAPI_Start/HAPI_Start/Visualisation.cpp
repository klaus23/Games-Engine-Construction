#include "Visualisation.h"
#include "Sprite.h"



Visualisation::Visualisation()
{
	int screenheight = 768;
	int screenwidth = 1024;
	HAPI.Initialise(screenwidth, screenheight, "GEC, Teodor-Klaus Mosnegutu, V8015944", eDefaults);
	screenpointer=HAPI.GetScreenPointer();
	destrect.right = screenwidth;
	destrect.bottom = screenheight;
	
}

bool Visualisation::CreateSprite(const std::string& filename, const std::string& name)
{
	Sprite* newSprite = new Sprite;
	if (!newSprite->Initialise(filename))
	{
		HAPI.UserMessage("Cannot load", "Error");
		return false;
		
	}
	else {
		m_SpriteMap[name] = newSprite;
		return true;
	}
	
}

void Visualisation::DrawSprite(const std::string& name, int Sx, int Sy)
{
	if (m_SpriteMap.find(name) == m_SpriteMap.end())
	{
		std::cerr << "not in map" << std::endl;
	}

	/**************************************************** DEBUG */
	//if (!m_SpriteMap[name]->m_init)
	//{
	//	m_SpriteMap[name]->Initialise("We dont use this yet");
	//}
	/**************************************************** DEBUG */

	m_SpriteMap[name]->ClipBlit(screenpointer, destrect, Sx, Sy);
	//m_SpriteMap[name]->MoveSprite();
	
}

void Visualisation::ClearToColour(BYTE* screen, int screenWidth, int screenHeight, HAPI_TColour colour)
{
	for (int y = 0; y < screenHeight; y++)
			{
				for (int x = 0; x < screenWidth; x++)
				{
					unsigned int offset = (x + y * screenWidth) * 4;
					BYTE* pnter = screen + offset;
					memcpy(screen + offset, &colour, 4);
				}
			}
}

//void Visualisation::ScrollingBackground()
//{
//
//}







