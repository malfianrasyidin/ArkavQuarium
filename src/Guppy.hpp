#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>

#include "../oop.hpp"
#include "Fish.hpp"
#include "FishFood.hpp"
#include "AquariumObject.hpp"
#include "FishFood.hpp"
#include "Coin.hpp"
using namespace std;

//Definisi kelas Guppy
class Guppy : public Fish, public AquariumObject{
  	public:
		//ctor
		Guppy();

		//dtor
		virtual ~Guppy();

		//fungsi memindahkan objek
		void move();
		
		//fungsi memakan FishFood
		void eat();

		//fungsi drop coin
		void dropCoin();

		//fungsi pengecekan hunger
		bool isHungry();

		//getter
		double getRadius() const;

		bool operator!=(const Guppy&);

		int getHunger();

		int getState();

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<FishFood>* & getListFishFood();
		static LinkedList<Guppy>* & getListGuppy();

	private:
		int hunger, state, timesEaten;
		double lastDropTime, lastHungerTime, lastLoopTime;

		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<FishFood>* & getObjectListFishFood() {
	        static LinkedList<FishFood>* list_fish_food;
	        return list_fish_food;
    	}
    	static LinkedList<Guppy>* & getObjectListGuppy() {
	        static LinkedList<Guppy>* list_guppy;
	        return list_guppy;
    	}

    	FishFood* targetFood;

		const static int HUNGER_TIME = 30;
		const static int DROP_TIME = 15;
		const static int MAX_HUNGER = 60;
		const static int COIN_DROP_VALUE = 5;
		const static int VELOCITY = 50;

		constexpr static double radius = 30;
};

#endif