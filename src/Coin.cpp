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
	this->setY(this->getY() + 0.05);
	draw_image("coin_edit.png" ,getX(), getY());
	if (this->getY() >= 350){
		getListCoin()->remove(*this);
	}
}

int Coin::getValue() const {
	return this->value;
}

bool Coin::operator!=(const Coin& coin) {
	return true;
}

LinkedList<Coin>* & Coin::getListCoin(){  
	return getObjectListCoin();  
}
