#ifndef SNAIL_HPP
#define SNAIL_HPP

#include <iostream>
#include "AquariumObject.hpp"
using namespace std;

//Definisi kelas Snail
class Snail : public AquariumObject {
	public:
		//ctor
		Snail();

		//dtor
		~Snail();

		//fungsi memindahkan objek
		void move();

		//fungsi mengambil koin
		void grabCoin();
};

#endif