#include "Coin.hpp"

//ctor
Coin::Coin(double x, double y, int val) : value(val) {
	this->setX(x);
	this->setY(y);
}

//dtor
Coin::~Coin() {}

//fungsi memindahkan objek
void Coin::move() {
	if (this->getY() <= 450){
		this->setY(this->getY() + 0.05);
	}
	draw_image("coin_edit.png" ,getX(), getY());
}


//getter
int Coin::getValue() const {
	return this->value;
}
double Coin::getRadius() const {
	return this->radius;
}

bool Coin::operator!=(const Coin& coin) {
	return !(coin.getValue() == this->getValue() && coin.getX() == this->getX() && coin.getY() == this->getY());
}

//getter static list
LinkedList<Coin>* & Coin::getListCoin(){  
	return getObjectListCoin();  
}
