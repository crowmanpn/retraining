#include <iostream>
#include "oop_exp.h"

int main() {

	Shape* myPntShape = new Circle(Shape::Point(3,1),5);
	myPntShape->ShapeInfo();
	
	Shape* myPntShape1 = new Triangle(Shape::Point(3, 4), Shape::Point(1, 4), Shape::Point(1, 4));

	myPntShape1->ShapeInfo();
	std::cout << "CalcP " << myPntShape1->calcP() << std::endl;
	
	std::cout << "CalcS " << myPntShape1->calcS()<< std::endl;;
	//stop
	


	return 0;
}
