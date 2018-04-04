// file : Guppy.cpp

#include "Guppy.hpp"

//ctor
Guppy::Guppy() {
	this->hunger = 10;
}

//dtor
Guppy::~Guppy() {}

//fungsi memindahkan objek
void Guppy::move(LinkedList<FishFood>& list_food) {
	
}

//fungsi memakan FishFood
void eat(LinkedList<FishFood>&);

//fungsi drop coin
void dropCoin(LinkedList<Coin>&);

bool Guppy::isHungry() {
	return hunger <= HUNGER_TIME;
}