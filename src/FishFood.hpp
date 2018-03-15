#ifndef FISHFOOD_HPP
#define FISHFOOD_HPP

#include <iostream>
#include "AquariumObject.hpp"
using namespace std;

//Definisi kelas FishFood
class FishFood : public AquariumObject{
	public:
		//ctor
    	FishFood();

		//dtor
    	~FishFood();

		//fungsi memindahkan objek
    	void move();
};

#endif