#pragma once
#include <vector>




class Shape {
public:
	struct Point
	{
		int m_x;
		int m_y;
		Point() :m_x(0), m_y(0) {}
		Point(int x, int y) :m_x(x), m_y(y) {}
	};
protected:
	std::vector<Point> m_vertexes;
public:
	void ShapeInfo() const;
public:
	virtual void ShInfoSpec() const = 0;
	virtual float calcP() const = 0;
	virtual float calcS() const = 0;
};

class Circle:public Shape{
	float Pi;
	size_t m_rad;
public:
	Circle(const Point& center, const size_t rad);
	virtual void ShInfoSpec() const override;
	virtual float calcP() const override;
	virtual float calcS()	const override;

};

class Triangle:public Shape
{
	public:	
	Triangle(const Point& p1, const Point& p2, const Point& p3);
	virtual void ShInfoSpec() const override;
	virtual float calcP() const override;
	virtual float calcS() const override;  //hw
};
