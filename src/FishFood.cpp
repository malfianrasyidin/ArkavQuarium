#include "FishFood.hpp"

//ctor
FishFood::FishFood(double x, double y){
	this->setX(x);
	this->setY(y);
	lastLoopTime = time_since_start();
}

//dtor
FishFood::~FishFood() {}

//fungsi memindahkan objek
void FishFood::move(){
	if (this->getY() <= 550){
		this->setY(this->getY() + VELOCITY * (time_since_start() - lastLoopTime));
	} else {
		getListFishFood()->remove(*this);
	}	
	draw_image("food.png", getX(), getY());
	lastLoopTime = time_since_start();
}

//getter
double FishFood::getRadius() const{
	return this->radius;
}

bool FishFood::operator!=(const FishFood& fishfood){
	return !(this->getX() == fishfood.getX() && this->getY() == fishfood.getY());
}

//getter static list
LinkedList<FishFood>* & FishFood::getListFishFood(){
	return getObjectListFishFood();
}