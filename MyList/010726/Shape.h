#pragma once

struct Point {
	int m_x;
	int m_y;
	Point() :m_x(0), m_y(0){};
	Point(int x, int y) :m_x(x), m_y(y) {};
};

enum class direction {
	left,
	right,
	top,
	down
};

enum class color {
	RED, GREEN, BLUE 
};


class Shape
{
private:
	size_t m_color[3];

	Point m_pnt;
	
public:
	//virtual void DrawShape()=0;
	virtual void ChangeColor(color oth)=0;
	virtual void MoveShape(direction oth)=0;
	//virtual float CalcSquare()=0;
	//virtual float CalcPerim()=0;

};



