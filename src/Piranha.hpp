#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include "Fish.hpp"
#include "AquariumObject.hpp"
using namespace std;

//Definisi kelas Piranha
class Piranha : public Fish, public AquariumObject{
	public:
		//ctor
		Piranha();

		//dtor
		~Piranha();

		//fungsi memindahkan objek
		void move();
		
		//fungsi memakan Guppy
		void eat();

		//fungsi drop coin
		void dropCoin();

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<Guppy>* & getListGuppy();

	private:
		int hunger, drop_time, state;
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<Guppy>* & getObjectListGuppy() {
	        static LinkedList<Guppy>* list_guppy;
	        return list_guppy;
    	}
		const static int HUNGER_TIME = 20;
		const static int MAX_HUNGER = 100;

};

#endif