#ifndef COIN_HPP
#define COIN_HPP

#include <iostream>
#include "AquariumObject.hpp"
#include "./../oop.hpp"
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

		int getValue() const;

		bool operator!=(const Coin&);

		static LinkedList<Coin>* & getListCoin();

  	private:
		const int value;
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}

};

#endif