#ifndef COIN_HPP
#define COIN_HPP

#include <iostream>
#include "AquariumObject.hpp"
using namespace std;

//Definisi kelas Coin
class Coin : public AquariumObject{
	public:
		//ctor
		Coin();

		//dtor
		~Coin();

		//fungsi memindahkan objek
		void move();

  	private:
		int value;
};

#endif