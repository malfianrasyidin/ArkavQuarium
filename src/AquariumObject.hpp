#ifndef AQUARIUMOBJECT_HPP
#define AQUARIUMOBJECT_HPP

#include <iostream>
#include "Aquarium.hpp"

using namespace std;

//Definisi Kelas Abstrak AquariumObject
class AquariumObject {
	public:
		
		virtual void move() = 0;
		
		//getter
		double getX() const;
		double getY() const;
		
		//setter
		void setX(double);
		void setY(double);
		
	private:
		double x,y;
		static Aquarium aquarium;

};

#endif