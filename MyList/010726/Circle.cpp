#include "Circle.h"

void Circle::MoveShape(direction oth)
{
	switch (oth)
	{
	case direction::left:
		m_center.m_x-=5;
		if (m_center.m_x < 0)	m_center.m_x = 800;
		break;
	case direction::right:
		m_center.m_x += 5;
		if (m_center.m_x > 800) m_center.m_x = 0;
		break;
	case direction::top:
		m_center.m_y += 5;
		if (m_center.m_y > 600) m_center.m_y = 0;
		break;
	case direction::down:
		m_center.m_y -= 5;
		if (m_center.m_y < 0) m_center.m_y = 600;
		break;
	default:
		break;
	}
}
