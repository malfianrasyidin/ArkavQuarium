#include "Coin.hpp"

//ctor
Coin::Coin(double x, double y, int val) : value(val) {
	this->setX(x);
	this->setY(y);
	lastLoopTime = time_since_start();
}

//dtor
Coin::~Coin() {}

//fungsi memindahkan objek
void Coin::move() {
	if (this->getY() <= 600){
		this->setY(this->getY() + VELOCITY * (time_since_start() - lastLoopTime));
	}
	draw_image("coin.png" ,getX(), getY());
	lastLoopTime = time_since_start();
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
