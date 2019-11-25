#include "Sprite.h"

bool Sprite::Initialise(const std::string& filename)
{
	m_init = true;
	if (!HAPI.LoadTexture(filename, &texture, texturewidth, textureheight))
	{
		m_init = false;
	   return false;
	}
	sourcerect.right = texturewidth;
	sourcerect.bottom = textureheight;
	sourcerect.left = 0;
	sourcerect.top = 0;
	return true;
}

//void Sprite::Render(BYTE* screen,const int &screenWidth,  int posX, int posY)
//{
//
//
//}



void Sprite::ClipBlit(BYTE* screen, const Rectangle& destRect,  int posX, int posY)
{

	Rectangle clipped(sourcerect);
	if (clipped.CompletelyOut(destRect))
	{
		return;
	}
	clipped.Translate(posX, posY);
	clipped.ClipTo(destRect);
	clipped.Translate(-posX, -posY);
	posX = std::max(0, posX);
	posY = std::max(0, posY);
	int endOfLineScreenIncrement = (destRect.width() - clipped.width()) * 4; //setting the offset

	BYTE* screenPnter = screen + (posX + posY * (size_t)destRect.width()) * 4; //screenpointer
	BYTE* texturePnter = texture+((size_t)clipped.left+(size_t)clipped.top*sourcerect.width()) * 4;
	for (int y = 0; y < clipped.height(); y++)
	{
		for (int x = 0; x < clipped.width(); x++)
		{
			BYTE alpha = texturePnter[3];

			BYTE red = texturePnter[0];
			BYTE green = texturePnter[1];
			BYTE blue = texturePnter[2];
			if (alpha == 255)
			{
				screenPnter[0] = red;
				screenPnter[1] = green;
				screenPnter[2] = blue;
			}
			else if (alpha > 0)
			{
				screenPnter[0] = screenPnter[0] + ((alpha * (red - screenPnter[0])) >> 8);
				screenPnter[1] = screenPnter[1] + ((alpha * (green - screenPnter[1])) >> 8);
				screenPnter[2] = screenPnter[2] + ((alpha * (blue - screenPnter[2])) >> 8);
			}

			texturePnter += 4;
			screenPnter += 4;
		}
		screenPnter += endOfLineScreenIncrement;
		texturePnter += (texturewidth - (size_t)clipped.width()) * 4;


	}
}







