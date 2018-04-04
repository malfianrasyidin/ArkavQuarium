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
		void move(LinkedList<FishFood>&);
		
		//fungsi memakan FishFood
		void eat(LinkedList<FishFood>&);

		//fungsi drop coin
		void dropCoin(LinkedList<Coin>&);

		//fungsi pengecekan hunger
		bool isHungry();

	private:
		int hunger, drop_time, state;
		const static int HUNGER_TIME = 10;
		const static int MAX_HUNGER = 60;
};

#endif