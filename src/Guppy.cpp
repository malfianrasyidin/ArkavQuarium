// file : Guppy.cpp

#include "Guppy.hpp"

//ctor
Guppy::Guppy(){

}

//dtor
Guppy::~Guppy(){

}

//fungsi memindahkan objek
void Guppy::move(){

}

//fungsi memakan FishFood
void Guppy::eat(){

}

//fungsi drop coin
void Guppy::dropCoin(){

}

//fungsi pengecekan hunger
bool Guppy::isHungry(){
	//not implemented yet
	return true;
}

//getter
double Guppy::getRadius() const{
	return this->radius;
}

bool Guppy::operator!=(const Guppy& guppy){
	//not impelented yet
	return true;
}

//getter static list
LinkedList<Coin>* & Guppy::getListCoin(){
	return getObjectListCoin();
}
LinkedList<FishFood>* & Guppy::getListFishFood(){
	return getObjectListFishFood();
}
LinkedList<Guppy>* & Guppy::getListGuppy(){
	return getObjectListGuppy();
}