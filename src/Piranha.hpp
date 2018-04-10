#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include <math.h>

#include "AquariumObject.hpp"
#include "../oop.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"

using namespace std;

/**
 * Definisi Kelas Piranha
 * Fungsi:
 * Kelas ini merupakan instance-instance dari Piranha
 */
class Piranha : public Fish, public AquariumObject{
	public:
		/// Default ctor
		Piranha();

		// Default dtor
		virtual ~Piranha();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Jika Piranha tidak sedang dalam keadaan lapar, Piranha akan melakukan gerakan acak
		 * Jika Piranha sedang dalam keadaan lapar, maka:
		 * Jika tidak terdapat Guppy, maka Piranha akan bergerak secara acak
		 * Jika terdapat Guppy, maka Piranha akan bergerak menuju posisi Guppy terdekat
		 */
		void move();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Mengatur ulang hunger menjadi MAX_HUNGER
		 * Menjatuhkan koin dengan memanggil fungsi dropCoin()
		 */
		void eat();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Membuat objek koin baru dengan perhitungan nilai GUPPY_PRICE * (Level Pertumbuan Guppy + 1)
		 */
		void dropCoin();

		/**
		 * Fungsi memeriksa apakah Piranha sedang dalam keadaan lapar atau tidak
		 * @return TRUE jika hunger <= HUNGER_TIME, FALSE jika tidak
		 */
		bool isHungry();

		/// Getter
		int getHunger();
		double getRadius() const;
		static LinkedList<Coin>* & getListCoin();
		static LinkedList<Guppy>* & getListGuppy();
		static LinkedList<Piranha>* & getListPiranha();

		/// Setter
		void setHunger(int);

		/**
		 * @Override
		 * @param objek Piranha
		 * @return TRUE jika kedua Piranha yang dibandingkan bukan objek yang sama, FALSE jika sebaliknya
		 * Membandingkan kedua Piranha berdasarkan kesamaan posisi x dan posisi y
		 */
		bool operator!=(const Piranha &);

	protected:
		/// Titik x,y target pergerakan acak
		double targetX, targetY;
		
	private:
		/// Daftar Atribut
		int hunger;
		double lastHungerTime, lastLoopTime, lastMoveTime;

		/// Atribut LinkedList
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<Guppy>* & getObjectListGuppy() {
	        static LinkedList<Guppy>* list_guppy;
	        return list_guppy;
    	}
    	static LinkedList<Piranha>* & getObjectListPiranha() {
	        static LinkedList<Piranha>* list_piranha;
	        return list_piranha;
    	}

    	Guppy* targetFood;

		/// Daftar Konstanta
		const static int HUNGER_TIME = 30;
		const static int MAX_HUNGER = 60;
		const static int VELOCITY = 50;
		const static int GUPPY_PRICE = 15;
		constexpr static double radius = 40;
};

#endif