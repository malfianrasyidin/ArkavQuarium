#include "Piranha.hpp"
#include <math.h>

//ctor
Piranha::Piranha(){
	hunger = MAX_HUNGER;
	targetFood = NULL;
	lastLoopTime = time_since_start();
	lastHungerTime = time_since_start();
	this->setX(rand() % 1280);
	this->setY(rand() % 720);
}

//dtor
Piranha::~Piranha() {}

//fungsi memindahkan objek
void Piranha::move(){

	//kurangi hunger
	if (time_since_start() - lastHungerTime >= 1) {
		hunger--;
		lastHungerTime = time_since_start();
	}

	Guppy* tempGuppy = NULL;

	//movement
	if (isHungry() && getListGuppy()->getCount() != 0) {
		LinkedList<Guppy>* listGuppy = getListGuppy();

		int idx = 0;
		double min = getDistance(listGuppy->get(0));

		for (int i = 1; i < listGuppy->getCount(); i++) {
			double temp = getDistance(listGuppy->get(i));
			if (min > temp){
				idx = i;
				min = temp;
			}
		}

		tempGuppy = &listGuppy->get(idx);
	}

	if (tempGuppy != NULL) {
		targetFood = tempGuppy;

		double angle = atan2(targetFood->getY() - this->getY(), targetFood->getX() - this->getX());

		this->setX(getX() + VELOCITY * cos(angle) * (time_since_start() - lastLoopTime));
		this->setY(getY() + VELOCITY * sin(angle) * (time_since_start() - lastLoopTime));

		if (isIntersect(*targetFood)) {
			eat();
		}
	} 

	draw_image("piranha.png", getX(), getY());

	lastLoopTime = time_since_start();
	targetFood = NULL;

	if (hunger <= 0) {
		getListPiranha()->remove(*this);
	}
}

//fungsi memakan Guppy
void Piranha::eat(){
	dropCoin();
	getListGuppy()->remove(*targetFood);
	targetFood = NULL;
	hunger = MAX_HUNGER;
}

//fungsi drop coin
void Piranha::dropCoin(){
	getListCoin()->add(new Coin(getX(), getY(), GUPPY_PRICE * (targetFood->getState() + 1)));
}

bool Piranha::isHungry() {
	return (hunger <= HUNGER_TIME);
}

//getter
double Piranha::getRadius() const {
	return this->radius;
}

bool Piranha::operator!=(const Piranha& piranha){
	return !((this->getX() == piranha.getX()) && (this->getY() == piranha.getY()));
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