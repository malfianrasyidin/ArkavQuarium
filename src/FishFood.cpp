/// Implementasi Kelas FishFood
#include "FishFood.hpp"

FishFood::FishFood(double x, double y){
	this->setX(x);
	this->setY(y);
	lastLoopTime = time_since_start();
}

FishFood::~FishFood() {}

void FishFood::move(){
	if (this->getY() <= 600){
		this->setY(this->getY() + VELOCITY * (time_since_start() - lastLoopTime));
	} else {
		getListFishFood()->remove(*this);
	}	
	draw_image("food.png", getX(), getY());
	lastLoopTime = time_since_start();
}

double FishFood::getRadius() const{
	return this->radius;
}

bool FishFood::operator!=(const FishFood& fishfood){
	return !(this->getX() == fishfood.getX() && this->getY() == fishfood.getY());
}

LinkedList<FishFood>* & FishFood::getListFishFood(){
	return getObjectListFishFood();
}