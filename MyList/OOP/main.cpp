#include <iostream>
#include "oop_exp.h"

int main() {

	Shape* myPntShape = new Circle(Shape::Point(3,1),5);
	myPntShape->ShapeInfo();
	
	



	return 0;
}
