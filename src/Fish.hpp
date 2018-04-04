#ifndef FISH_HPP
#define FISH_HPP

#include <iostream>
using namespace std;

//Definisi kelas Fish
class Fish {
	public:
		virtual void eat() = 0;
		virtual void dropCoin(LinkedList<Coin>&) = 0;
};

#endif
