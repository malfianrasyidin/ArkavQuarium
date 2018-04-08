#include "Aquarium.hpp"

//ctor
Aquarium::Aquarium(){
	snail = new Snail(320,450);
}

//dtor
Aquarium::~Aquarium(){

}

//getter
LinkedList<Guppy>& Aquarium::getListGuppy(){
	return this->list_guppy;
}
LinkedList<Piranha>& Aquarium::getListPiranha(){
	return this->list_piranha;
}
LinkedList<FishFood>& Aquarium::getListFishFood(){
	return this->list_fish_food;
}
LinkedList<Coin>& Aquarium::getListCoin(){
	return this->list_coin;
}
Snail* Aquarium::getSnail(){
	return snail;
}