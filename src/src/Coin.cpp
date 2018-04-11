/// Implementasi Kelas Coin
#include "Coin.hpp"

Coin::Coin(double x, double y, int val) : value(val) {
	this->setX(x);
	this->setY(y);
	lastLoopTime = time_since_start();
}

Coin::~Coin() {}

void Coin::move() {
	if (this->getY() <= 600){
		this->setY(this->getY() + VELOCITY * (time_since_start() - lastLoopTime));
	}
	if (getValue() < 20) {
		draw_image("coin.png" ,getX(), getY());
	} else {
		draw_image("diamond.png", getX(), getY());
	}
	lastLoopTime = time_since_start();
}

int Coin::getValue() const {
	return this->value;
}

double Coin::getRadius() const {
	return this->radius;
}

bool Coin::operator!=(const Coin& coin) {
	return !(coin.getValue() == this->getValue() && coin.getX() == this->getX() && coin.getY() == this->getY());
}

LinkedList<Coin>* & Coin::getListCoin(){  
	return getObjectListCoin();  
}

void Coin::setLoopTime(double lastLoopTime) {
	this->lastLoopTime = lastLoopTime;
}
