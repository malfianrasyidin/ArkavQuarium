// file : Guppy.cpp

#include "Guppy.hpp"
#include <math.h>
#include <stdlib.h>
#include <sstream>

//ctor
Guppy::Guppy(){
	state = 1;
	timesEaten = 0;
	hunger = MAX_HUNGER;
	targetFood = NULL;
	lastDropTime = time_since_start();
	lastHungerTime = time_since_start();
  	lastLoopTime = time_since_start();
	lastMoveTime = time_since_start();
	targetX = rand() % 1080;
	targetY = (rand() % 550) + 120;
	this->setX(rand() % 1080);
	this->setY((rand() % 550) + 120);
}

//dtor
Guppy::~Guppy() {}

//fungsi memindahkan objek
void Guppy::move(){

	stringstream fname;
	fname << "guppy";

	//kurangi hunger
	if (time_since_start() - lastHungerTime >= 1) {
		hunger--;
		lastHungerTime = time_since_start();
	}

	//drop coin
	if (time_since_start() - lastDropTime >= DROP_TIME) {
		dropCoin();
	}

	FishFood* tempFood = NULL;
	//movement
	if ((isHungry()) && (getListFishFood()->getCount() != 0)) {
		LinkedList<FishFood>* listFishFood = getListFishFood();

		int idx = 0;
		double min = getDistance(listFishFood->get(0));

		for (int i = 1; i < listFishFood->getCount(); i++) {
			double temp = getDistance(listFishFood->get(i));
			if (min > temp){
				idx = i;
				min = temp;
			}
		}

		tempFood = &listFishFood->get(idx);
	}

	if (tempFood != NULL) {
		targetFood = tempFood;

		double angle = atan2(targetFood->getY() - this->getY(), targetFood->getX() - this->getX());

		this->setX(getX() + VELOCITY*(1.5) * cos(angle) * (time_since_start() - lastLoopTime));
		this->setY(getY() + VELOCITY*(1.5) * sin(angle) * (time_since_start() - lastLoopTime));

		if (cos(angle) >= 0){
			fname << "r" << state << ".png";
			draw_image(fname.str(), getX(), getY());
		} else {
			fname << "l" << state << ".png";
			draw_image(fname.str(), getX(), getY());
		}

		if (isIntersect(*targetFood)) {
			eat();
		}
	} else {
		//random move
		if (time_since_start() - lastMoveTime >= 3){
			targetX = rand() % 1080;
			while (fabs(targetX-this->getX()) < 10){
				targetX = rand() % 1080;
			}
			targetY = (rand() % 500) + 120;
			while (fabs(targetY-this->getY()) < 10){
				targetY = (rand() % 500) + 120;
			}
			lastMoveTime = time_since_start();
		}
		double angle = atan2(targetY - this->getY(), targetX - this->getX());

		this->setX(getX() + VELOCITY * cos(angle) * (time_since_start() - lastLoopTime));
		this->setY(getY() + VELOCITY * sin(angle) * (time_since_start() - lastLoopTime));

		if (cos(angle) > 0){
			fname << "r" << state << ".png";
			draw_image(fname.str(), getX(), getY());
		} else {
			fname << "l" << state << ".png";
			draw_image(fname.str(), getX(), getY());
		}
	} 

	lastLoopTime = time_since_start();
	targetFood = NULL;

	if (hunger <= 0) {
		getListGuppy()->remove(*this);
	}
}

//fungsi memakan FishFood
void Guppy::eat(){
	getListFishFood()->remove(*targetFood);
	targetFood = NULL;
	hunger = MAX_HUNGER;
	timesEaten++;

	if ((timesEaten != 0) && (timesEaten % 3 == 0) && (state < 3)) {
		state++;
	}
}

//fungsi drop coin
void Guppy::dropCoin(){
	getListCoin()->add(new Coin(getX(), getY(), COIN_DROP_VALUE * state));
	lastDropTime = time_since_start();
}

//fungsi pengecekan hunger
bool Guppy::isHungry(){
	//not implemented yet
	return (hunger <= HUNGER_TIME);
}

//getter
double Guppy::getRadius() const{
	return this->radius;
}

bool Guppy::operator!=(const Guppy& guppy){
	//not impelented yet
	return !((this->getX() == guppy.getX()) && (this->getY() == guppy.getY()));
}

int Guppy::getHunger() {
	return this->hunger;
}

int Guppy::getState() {
	return this->state;
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