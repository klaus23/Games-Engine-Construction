#pragma once
#include <HAPI_lib.h>
#include "Sprite.h"
using namespace HAPISPACE;
#include <unordered_map>

class Visualisation
{
private:
	Sprite sprite;
	Rectangle destrect;
	int screenheight = 768;
	int screenwidth = 1024;
	int posX = 40;
	int posY = 50;
	BYTE* screenpointer = {};
	std::unordered_map<std::string, Sprite*>m_SpriteMap;
public:
	Visualisation();
	bool CreateSprite(const std::string& filename, const std::string& name);
	void DrawSprite(const std::string& name, int Sx, int Sy);
	void ClearToColour(BYTE* screen, int screenWidth, int screenHeight, HAPI_TColour colour);
	//void SetScreenPointer(BYTE* screen) { screenpointer = screen; }
	int GetHeight() { return screenheight; }
	int GetWidth() { return screenwidth; }
	/*void ScrollingBackground();*/

};

