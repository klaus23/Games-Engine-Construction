#pragma once
class Rectangle
{
public:

	int left{ 0 }, right{ 0 }, top{ 0 }, bottom{ 0 };
	bool CompletelyOut(const Rectangle& other)const;
	bool CompletelyInside(const Rectangle& other)const;
	void ClipTo(const Rectangle& other);
	int width() const { return right - left; }
	int height() const { return bottom - top; }
	void Translate(int dx, int dy);
};

