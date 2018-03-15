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

		//fungsi memakan Fish
		void eat();

	private:
		int hunger, drop_time, state;
		const static int HUNGER_TIME;
};

#endif