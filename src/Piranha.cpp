#include "Piranha.hpp"

//ctor
Piranha::Piranha(double x, double y){
	this->setX(x);
	this->setY(y);
}

//dtor
Piranha::~Piranha(){

}

//fungsi memindahkan objek
void Piranha::move(){

}

//fungsi memakan Guppy
void Piranha::eat(){

}

//fungsi drop coin
void Piranha::dropCoin(){

}

//getter
double Piranha::getRadius() const {
	return this->radius;
}

bool Piranha::operator!=(const Piranha& piranha){
	//not impelented yet
	return true;
}

//getter static list
LinkedList<Coin>* & Piranha::getListCoin(){
	return getObjectListCoin();
}
LinkedList<Guppy>* & Piranha::getListGuppy(){
	return getObjectListGuppy();
}
LinkedList<Piranha>* & Piranha::getListPiranha(){
	return getObjectListPiranha();
}