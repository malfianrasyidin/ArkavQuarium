#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include "AquariumObject.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
using namespace std;

//Definisi kelas Piranha
class Piranha : public Fish, public AquariumObject{
	public:
		//ctor
		Piranha(double, double);

		//dtor
		virtual ~Piranha();

		//fungsi memindahkan objek
		void move();
		
		//fungsi memakan Guppy
		void eat();

		//fungsi drop coin
		void dropCoin();

		//getter
		double getRadius() const;

		bool operator!=(const Piranha&);

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<Guppy>* & getListGuppy();
		static LinkedList<Piranha>* & getListPiranha();

	private:
		int hunger, state;
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
		const static int HUNGER_TIME = 20;
		const static int MAX_HUNGER = 100;
		constexpr static double radius = 40;
};

#endif