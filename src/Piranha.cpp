#include "Piranha.hpp"

//ctor
Piranha::Piranha(){

}

//dtor
Piranha::~Piranha(){

}

//fungsi memindahkan objek
void Piranha::move(){

}

//fungsi memakan Guppy
void Piranha::eat(){

}

//fungsi drop coin
void Piranha::dropCoin(){

}

//getter static list
LinkedList<Coin>* & Piranha::getListCoin(){
	return getObjectListCoin();
}
LinkedList<Guppy>* & Piranha::getListGuppy(){
	return getObjectListGuppy();
}