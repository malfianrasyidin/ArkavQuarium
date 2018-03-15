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

	private:
		int hunger, drop_time, state;
		const static int HUNGER_TIME;
};

#endif