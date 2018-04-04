// Implementation of AquariumObject.hpp

#include "AquariumObject.hpp"

// setter and getter
double AquariumObject::getX() const {
	return this->x;
}

double AquariumObject::getY() const {
	return this->y;
}

//setter
void AquariumObject::setX(double x) {
	this->x = x;
}

void AquariumObject::setY(double y) {
	this->y = y;
}

Aquarium& AquariumObject::getAquarium() {
	return this->aquarium;
}