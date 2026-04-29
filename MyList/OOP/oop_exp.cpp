#include "oop_exp.h"
#include <iostream>

void Shape::ShapeInfo() const
{
	std::cout << "general info: " << std::endl;
	for (size_t i = 0; i < m_vertexes.size(); i++)
	{
		std::cout << m_vertexes[i].m_x << " " << m_vertexes[i].m_y << std::endl;
	}

	ShInfoSpec();
 
}

Circle::Circle(const Point& center, const size_t rad)
{
	Pi = 3, 14;
	m_rad = rad;
	m_vertexes.emplace_back(center);

}

void Circle::ShInfoSpec() const
{
	std::cout << "spec info: " << std::endl;
	std::cout << m_rad << std::endl;
}

int Circle::calcP() const
{
	return 2*Pi*m_rad;
}

int Circle::calcS() const
{

	return Pi * (m_rad*m_rad);
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
{
	m_vertexes.emplace_back(p1);
	m_vertexes.emplace_back(p2);
	m_vertexes.emplace_back(p3);
}
