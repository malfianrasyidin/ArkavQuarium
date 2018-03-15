#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include <iostream>
#include "Guppy.hpp"
#include "Snail.hpp"
#include "Piranha.hpp"
#include "FishFood.hpp"
#include "Coin.hpp"
#include "LinkedList.hpp"
using namespace std;

//Definisi kelas Aquarium
class Aquarium{
	public:
		//ctor
		Aquarium();
		
		//dtor
		~Aquarium();

	private:
		int x, y;
		LinkedList<Guppy> list_guppy;
		LinkedList<Piranha> list_piranha;
		LinkedList<FishFood> list_fish_food;
		LinkedList<Coin> list_coin;
		Snail* snail;
		const static int MAX_X = 100, MAX_Y = 100;
};

#endif