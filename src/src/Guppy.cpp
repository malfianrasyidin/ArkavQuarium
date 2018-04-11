/// Implementasi Kelas Guppy
#include "Guppy.hpp"

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

Guppy::~Guppy() {}

void Guppy::move(){
	stringstream fname;
	fname << "guppy";

	/// Mengurangkan nilai hunger
	if (time_since_start() - lastHungerTime >= 1) {
		hunger--;
		lastHungerTime = time_since_start();
	}

	/// Menjatuhkan koin
	if (time_since_start() - lastDropTime >= DROP_TIME) {
		dropCoin();
	}

	FishFood* tempFood = NULL;
	/// Pergerakan mengejar FishFood terdekat
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
		/// FishFood ditemukan
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
		/// Tidak ada FishFood yang ditemukan, sehingga bergerak acak
		if (time_since_start() - lastMoveTime >= 3){
			targetX = rand() % 1080;
			while (fabs(targetX-this->getX()) < 200){
				targetX = rand() % 1080;
			}
			targetY = (rand() % 500) + 120;
			while (fabs(targetY-this->getY()) < 200){
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

void Guppy::eat(){
	getListFishFood()->remove(*targetFood);
	targetFood = NULL;
	hunger = MAX_HUNGER;
	timesEaten++;

	if ((timesEaten != 0) && (timesEaten % 3 == 0) && (state < 3)) {
		state++;
	}
}

void Guppy::dropCoin(){
	getListCoin()->add(new Coin(getX(), getY(), COIN_DROP_VALUE * state));
	lastDropTime = time_since_start();
}

bool Guppy::isHungry(){
	return (hunger <= HUNGER_TIME);
}

double Guppy::getRadius() const{
	return this->radius;
}

bool Guppy::operator!=(const Guppy& guppy){
	return !((this->getX() == guppy.getX()) && (this->getY() == guppy.getY()));
}

int Guppy::getHunger() {
	return this->hunger;
}

int Guppy::getState() {
	return this->state;
}

int Guppy::getTimesEaten() {
	return this->timesEaten;
}

void Guppy::setHunger(int hunger) {
	this->hunger = hunger;
}

void Guppy::setState(int state) {
	this->state = state;
}

void Guppy::setTimesEaten(int timesEaten) {
	this->timesEaten = timesEaten;
}

LinkedList<Coin>* & Guppy::getListCoin(){
	return getObjectListCoin();
}

LinkedList<FishFood>* & Guppy::getListFishFood(){
	return getObjectListFishFood();
}

LinkedList<Guppy>* & Guppy::getListGuppy(){
	return getObjectListGuppy();
}