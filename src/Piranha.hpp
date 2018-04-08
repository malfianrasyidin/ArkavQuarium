#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>

#include "AquariumObject.hpp"
#include "../oop.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"

using namespace std;

//Definisi kelas Piranha
class Piranha : public Fish, public AquariumObject{
	public:
		//ctor
		Piranha();

		//dtor
		virtual ~Piranha();

		//fungsi memindahkan objek
		void move();
		
		//fungsi memakan Guppy
		void eat();

		//fungsi drop coin
		void dropCoin();

		//fungsi pengecekan hunger
		bool isHungry();

		//getter
		double getRadius() const;

		bool operator!=(const Piranha&);

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<Guppy>* & getListGuppy();
		static LinkedList<Piranha>* & getListPiranha();

	protected:
		double targetX, targetY;
		
	private:
		int hunger;
		double lastHungerTime, lastLoopTime, lastMoveTime;

		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<Guppy>* & getObjectListGuppy() {
	        static LinkedList<Guppy>* list_guppy;
	        return list_guppy;
    	}
    	static LinkedList<Piranha>* & getObjectListPiranha() {
	        static LinkedList<Piranha>* list_piranha;
	        return list_piranha;
    	}

    	Guppy* targetFood;

		const static int HUNGER_TIME = 30;
		const static int MAX_HUNGER = 60;
		const static int VELOCITY = 50;
		const static int GUPPY_PRICE = 15;

		constexpr static double radius = 40;
};

#endif