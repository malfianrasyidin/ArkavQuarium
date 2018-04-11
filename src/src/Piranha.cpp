/// Implementasi Kelas Piranha
#include "Piranha.hpp"

Piranha::Piranha(){
	hunger = MAX_HUNGER;
	targetFood = NULL;
	lastLoopTime = time_since_start();
	lastHungerTime = time_since_start();
	lastMoveTime = time_since_start();
	targetX = rand() % 1080;
	targetY = (rand() % 550) + 120;
	this->setX(rand() % 1080);
	this->setY((rand() % 550) + 120);
}

Piranha::~Piranha() {}

void Piranha::move(){

	/// Mengurangkan nilai hunger
	if (time_since_start() - lastHungerTime >= 1) {
		hunger--;
		lastHungerTime = time_since_start();
	}

	Guppy* tempGuppy = NULL;

	// Pergerakan Piranha
	if (isHungry() && getListGuppy()->getCount() != 0) {
		/// Piranha sedang dalam keadaan lapar
		LinkedList<Guppy>* listGuppy = getListGuppy();

		int idx = 0;
		double min = getDistance(listGuppy->get(0));

		/// Mencari posisi Guppy terdekat
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
		/// Piranha bergerak menuju Guppy terdekat
		targetFood = tempGuppy;

		double angle = atan2(targetFood->getY() - this->getY(), targetFood->getX() - this->getX());

		this->setX(getX() + VELOCITY * (1.5) * cos(angle) * (time_since_start() - lastLoopTime));
		this->setY(getY() + VELOCITY * (1.5) * sin(angle) * (time_since_start() - lastLoopTime));

		if (cos(angle) >= 0){
			draw_image("piranhar.png", getX(), getY());
		} else {
			draw_image("piranhal.png", getX(), getY());
		}

		if (isIntersect(*targetFood)) {
			/// Piranha memakan makanan
			eat();
		}
	} else {
		/// Piranha bergerak dengan arah acak
		if (time_since_start() - lastMoveTime >= 3){
			targetX = rand() % 1280;
			while (fabs(targetX-this->getX()) < 200){
				targetX = rand() % 1280;
			}
			targetY = rand() % 500;
			while (fabs(targetY-this->getY()) < 200){
				targetY = rand() % 500;
			}
			lastMoveTime = time_since_start();
		}
		double angle = atan2(targetY - this->getY(), targetX - this->getX());

		this->setX(getX() + VELOCITY * cos(angle) * (time_since_start() - lastLoopTime));
		this->setY(getY() + VELOCITY * sin(angle) * (time_since_start() - lastLoopTime));

		if (cos(angle) >= 0){
			draw_image("piranhar.png", getX(), getY());
		} else {
			draw_image("piranhal.png", getX(), getY());
		}
	}

	lastLoopTime = time_since_start();
	targetFood = NULL;

	if (hunger <= 0) {
		getListPiranha()->remove(*this);
	}
}

void Piranha::eat(){
	dropCoin();
	getListGuppy()->remove(*targetFood);
	targetFood = NULL;
	hunger = MAX_HUNGER;
}

void Piranha::dropCoin(){
	getListCoin()->add(new Coin(getX(), getY(), GUPPY_PRICE * (targetFood->getState() + 1)));
}

bool Piranha::isHungry() {
	return (hunger <= HUNGER_TIME);
}

double Piranha::getRadius() const {
	return this->radius;
}

bool Piranha::operator!=(const Piranha& piranha){
	return !((this->getX() == piranha.getX()) && (this->getY() == piranha.getY()));
}

int Piranha::getHunger() {
	return this->hunger;
}

void Piranha::setHunger(int hunger) {
	this->hunger = hunger;
}

void Piranha::setLoopTime(double loopTime) {
	this->lastLoopTime = loopTime;
}

LinkedList<Coin>* & Piranha::getListCoin(){
	return getObjectListCoin();
}

LinkedList<Guppy>* & Piranha::getListGuppy(){
	return getObjectListGuppy();
}

LinkedList<Piranha>* & Piranha::getListPiranha(){
	return getObjectListPiranha();
}