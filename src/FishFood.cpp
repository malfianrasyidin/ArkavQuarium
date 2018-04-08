#include "FishFood.hpp"

//ctor
FishFood::FishFood(double x, double y){
	this->setX(x);
	this->setY(y);
}

//dtor
FishFood::~FishFood(){

}

//fungsi memindahkan objek
void FishFood::move(){
	if (this->getY() >= 460){
		
	}
}

//getter
double FishFood::getRadius() const{
	return this->radius;
}

bool FishFood::operator!=(const FishFood& fishfood){
	return (this->getX() == fishfood.getX() && this->getY() == fishfood.getY());
}

//getter static list
LinkedList<FishFood>* & FishFood::getListFishFood(){
	return getObjectListFishFood();
}