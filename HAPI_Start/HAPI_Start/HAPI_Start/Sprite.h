#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;
#include <unordered_map>
#include "Rectangle.h"
#include <algorithm>
class Rectangle;
class Sprite
{
private:
	Rectangle sourcerect;
	int width = { 1024 };
	int height = { 768 };
	int SpriteX = 50;
	int SpriteY = 40;
	BYTE* texture;
	int texturewidth;
	int textureheight;
	std::unordered_map<std::string, Sprite*>m_SpriteMap;
public:
	bool Initialise(const std::string& filename);
	//void Render(BYTE* screen,const int &screenWidth, int posX, int posY);
	bool m_init = false;
	void ClipBlit(BYTE* screen, const Rectangle& destRect,  int posX, int posY);
	int GetTextureHeight() { return textureheight; }
	int GetTextureWidth() { return texturewidth; }
	int GetSpriteX() { return SpriteX; }
	int GetSpriteY() { return SpriteY; }

};

