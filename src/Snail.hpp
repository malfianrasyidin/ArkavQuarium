#ifndef SNAIL_HPP
#define SNAIL_HPP

#include <iostream>
#include "AquariumObject.hpp"
#include "Coin.hpp"
using namespace std;

//Definisi kelas Snail
class Snail : public AquariumObject {
	public:
		//ctor
		Snail(double, double);

		//dtor
		virtual ~Snail();

		//fungsi memindahkan objek
		void move();

		//fungsi mengambil koin
		void grabCoin(Coin&);

		//getter
		double getRadius() const;

		//getter static list
		static LinkedList<Coin>* & getListCoin();
		
	private:
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	constexpr static double radius = 30;
};

#endif