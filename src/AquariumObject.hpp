#ifndef AQUARIUMOBJECT_HPP
#define AQUARIUMOBJECT_HPP

#include <iostream>
using namespace std;

//Definisi Kelas Abstrak AquariumObject
class AquariumObject {
	public:
		virtual void move() = 0;
		
		//getter
		int getX() const;
		int getY() const;
		
		//setter
		void setX(int);
		void setY(int);
		
	private:
		int x,y;
};

#endif