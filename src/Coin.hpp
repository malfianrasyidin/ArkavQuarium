#ifndef COIN_HPP
#define COIN_HPP

#include <iostream>

#include "AquariumObject.hpp"
#include "../oop.hpp"

using namespace std;

//Definisi kelas Coin
class Coin : public AquariumObject{
	public:
		//ctor
		Coin(double, double, int);

		//dtor
		virtual ~Coin();

		//fungsi memindahkan objek
		void move();

		//getter
		int getValue() const;
		double getRadius() const;

		bool operator!=(const Coin&);

		static LinkedList<Coin>* & getListCoin();

  	private:
  		double lastLoopTime;
		const int value;
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	const static int VELOCITY = 25;
    	constexpr static double radius = 25;

};

#endif