#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>
#include "Fish.hpp"
#include "AquariumObject.hpp"
using namespace std;

//Definisi kelas Guppy
class Guppy : public Fish, public AquariumObject{
  	public:
		//ctor
		Guppy();

		//dtor
		~Guppy();

		//fungsi memindahkan objek
		void move();
		
		//fungsi memakan FishFood
		void eat();

		//fungsi drop coin
		void dropCoin();

		//fungsi pengecekan hunger
		bool isHungry();

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<FishFood>* & getListFishFood();

	private:
		int hunger, drop_time, state;
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<FishFood>* & getObjectListFishFood() {
	        static LinkedList<FishFood>* list_fish_food;
	        return list_fish_food;
    	}
		const static int HUNGER_TIME = 10;
		const static int MAX_HUNGER = 60;
};

#endif