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

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		
	private:
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
};

#endif