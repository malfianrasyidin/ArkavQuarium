// Implementation of AquariumObject.hpp

#include "AquariumObject.hpp"

bool AquariumObject::isIntersect(const AquariumObject& ao){
	double rad = this->getRadius()+ao.getRadius();
    return this->getDistance(ao) <= rad*rad;
}

bool AquariumObject::isIntersect(double x, double y, double r){
	double x1 = this->getX() - x;
    double y1 = this->getY() - y;
	double rad = this->getRadius()+r;
    return x1*x1+y1*y1 <= rad*rad;
}

double AquariumObject::getDistance(const AquariumObject& ao){
	double x = this->getX() - ao.getX();
    double y = this->getY() - ao.getY();
    return x*x+y*y;
}

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