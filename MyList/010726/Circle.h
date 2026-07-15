#pragma once
#include "Shape.h"
class Circle:public Shape {
private:
	int m_rad;
	Point m_center;
public:
	Circle() :m_rad(0), m_center(0, 0) {};
	Circle(int rad, Point cntPnt) :m_rad(rad), m_center(cntPnt) {};
	int GetRad() { return m_rad; };
	Point GetCenter() { return m_center; };
	void MoveShape(direction oth) override;
	void ChangeColor(color oth) override;
};