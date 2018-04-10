#ifndef FISH_HPP
#define FISH_HPP

#include <iostream>
using namespace std;

/**
 * Definisi Kelas Abstrak Fish
 * Fungsi:
 * 
 */
class Fish {
	public:
		/**
		 * eat() dan dropCoin() akan diimplementasikan di kelas anak
		 */
		virtual void eat() = 0;
		virtual void dropCoin() = 0;
};

#endif
