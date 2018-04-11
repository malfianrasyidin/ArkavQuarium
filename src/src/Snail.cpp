/// Implementasi Kelas Snail
#include "Snail.hpp"

Snail::Snail(double x, double y){
	this->setX(x);
	this->setY(y);
	lastLoopTime = time_since_start();
}

Snail::~Snail() {}

void Snail::move(){
	int move, idx;
	double min, temp;
	Coin *coin;
	LinkedList<Coin>* listcoin = getListCoin();

	move = 0;
	
	if (listcoin->getCount() == 0){
		move = 0;
	} else {
		min = this->getDistance(listcoin->get(0));
		idx = 0;
		for (int i = 1; i < listcoin->getCount(); i++){
			temp = this->getDistance(listcoin->get(i));
			if (min > temp){
				idx = i;
				min = temp;
			}
		}
		move = 1;
		coin = &listcoin->get(idx);
	}

	if (move == 1){
		if (coin->getX() < this->getX()){
			this->setX(this->getX() - VELOCITY * (time_since_start() - lastLoopTime));
			draw_image("snaill.png" ,getX(), getY());
		} else {
			this->setX(this->getX() + VELOCITY * (time_since_start() - lastLoopTime));
			draw_image("snailr.png" ,getX(), getY());
		}
		if (this->isIntersect(*coin)){
			this->grabCoin(*coin);
		}
		lastLoopTime = time_since_start();
		return;
	}
	draw_image("snaill.png" ,getX(), getY());
	lastLoopTime = time_since_start();
}

void Snail::grabCoin(Coin& coin){
	*money += coin.getValue();
	getListCoin()->remove(coin);
}

double Snail::getRadius() const{
	return this->radius;
}

LinkedList<Coin>* & Snail::getListCoin(){
	return getObjectListCoin();
}

void Snail::setMoney(int* money) {
	this->money = money;
}

void Snail::setLoopTime(double lastLoopTime) {
	this->lastLoopTime = lastLoopTime;
}