#ifndef SNAIL_HPP
#define SNAIL_HPP

#include <iostream>

#include "AquariumObject.hpp"
#include "Coin.hpp"
#include "../oop.hpp"

using namespace std;

/**
 * Definisi Kelas Snail
 * Fungsi:
 * Kelas ini merupakan instance dari Snail
 */
class Snail : public AquariumObject {
	public:
		/**
		 * User defined ctor
		 * @param posisi x dan posisi y
		 */
		Snail(double, double);

		/// Default dtor
		virtual ~Snail();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Jika tidak terdapat koin, Snail akan diam pada tempatnya
		 * Jika terdapat koin, maka Snail akan bergerak ke koin terdekat
		 */
		void move();

		/**
		 * Fungsi ini melakukan hal berikut:
		 * Menghapus objek koin yang telah diambil
		 * Menambah nilai uang berdasarkan nilai koin yang diambil tersebut
		 */
		void grabCoin(Coin&);

		/// Getter
		double getRadius() const;
		static LinkedList<Coin>* & getListCoin();

		/// Setter
		void setMoney(int*);
		
	private:
		/// Daftar atribut
		double lastLoopTime;
		int* money;
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}

		/// Daftar atribut konstanta
    	const static int VELOCITY = 50;
    	constexpr static double radius = 30;
};

#endif