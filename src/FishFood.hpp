#ifndef FISHFOOD_HPP
#define FISHFOOD_HPP

#include <iostream>

#include "AquariumObject.hpp"
#include "../oop.hpp"

using namespace std;

//Definisi kelas FishFood
class FishFood : public AquariumObject{
	public:
		//ctor
    	FishFood(double, double);

		//dtor
    	virtual ~FishFood();

		//fungsi memindahkan objek
    	void move();

        //getter
        double getRadius() const;

        bool operator!=(const FishFood&);

    	//getter static list
    	static LinkedList<FishFood>* & getListFishFood();

    private:
        double lastLoopTime;

        const static int VELOCITY = 25;
        constexpr static double radius = 5;

    	static LinkedList<FishFood>* & getObjectListFishFood() {
	        static LinkedList<FishFood>* list_fish_food;
	        return list_fish_food;
    	}
};

#endif