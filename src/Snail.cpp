#include "Snail.hpp"

//ctor
Snail::Snail(double x, double y){
	this->setX(x);
	this->setY(y);
}

//dtor
Snail::~Snail(){

}

//fungsi memindahkan objek
void Snail::move(){
	int move, idx;
	double min, temp;
	Coin *coin;
	// int move = rand()%2;
	LinkedList<Coin>* listcoin = getListCoin();

	move = 0;
	
	if (listcoin->getCount() == 0){
		move = 0;
	} else {
		min = this->getDistance(listcoin->get(0));
		idx = 0;
		for (int i=1; i<listcoin->getCount(); i++){
			// printf("%d : %f %f, %f %f\n", i, getX(), getY(), listcoin->get(i).getX(), listcoin->get(i).getY());
			temp = this->getDistance(listcoin->get(i));
			if (min > temp){
				idx = i;
				min = temp;
			}
		}
		move = 1;
		coin = &listcoin->get(idx);
		// printf("%f %f, %f %f\n", getX(), getY(), coin->getX(), coin->getY());
	}

	if (move == 0){
		this->setX(this->getX() + (rand() % 2 - 1));
	} else {
		if (coin->getX() < this->getX()){
			this->setX(this->getX() - 0.5);
		} else {
			this->setX(this->getX() + 0.5);
		}
		if (this->isIntersect(*coin)){
			this->grabCoin(*coin);
		}
	}
	draw_image("coin_edit.png" ,getX(), getY());
}

//fungsi mengambil koin
void Snail::grabCoin(Coin& coin){
	getListCoin()->remove(coin);
}

//getter
double Snail::getRadius() const{
	return this->radius;
}

//getter static list
LinkedList<Coin>* & Snail::getListCoin(){
	return getObjectListCoin();
}