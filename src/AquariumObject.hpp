#ifndef AQUARIUMOBJECT_HPP
#define AQUARIUMOBJECT_HPP

#include <iostream>
#include "LinkedList.hpp"
#include "../oop.hpp"

using namespace std;

//Definisi Kelas Abstrak AquariumObject
class AquariumObject {
	public:
		
		virtual void move() = 0;

		bool isIntersect(const AquariumObject&);
		bool isIntersect(double, double, double);
		double getDistance(const AquariumObject&);
		
		//getter
		double getX() const;
		double getY() const;
		virtual double getRadius() const = 0;
		
		//setter
		void setX(double);
		void setY(double);
		
	private:
		double x, y;

};

#endif