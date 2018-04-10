#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>

#include "../oop.hpp"
#include "Fish.hpp"
#include "FishFood.hpp"
#include "AquariumObject.hpp"
#include "FishFood.hpp"
#include "Coin.hpp"
using namespace std;

/**
 * Definisi Kelas Guppy
 * Fungsi:
 * Kelas ini merupakan instance-instance dari objek Guppy
 */
class Guppy : public Fish, public AquariumObject{
  	public:
		/// Default ctor
		Guppy();

		/// Default dtor
		virtual ~Guppy();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Jika Guppy tidak sedang dalam keadaan lapar, Guppy akan melakukan gerakan acak
		 * Jika Guppy sedang dalam keadaan lapar, maka:
		 * Jika tidak terdapat FishFood, maka Guppy akan bergerak secara acak
		 * Jika terdapat FishFood, maka Guppy akan bergerak menuju posisi FishFood terdekat
		 */
		void move();
		
		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Mengatur ulang hunger menjadi MAX_HUNGER
		 * Menambah counter berapa banyak kali ikan telah memakan FishFood
		 * Menambah level pertumbuhan ikan jika telah setiap kelipatan counter = 3
		 */
		void eat();

		/**
		 * @Override
		 * Fungsi ini melakukan hal berikut:
		 * Mengatur lastDropTime menjadi waktu saat melakukan drop
		 * Membuat objek koin baru dengan perhitungan nilai (COIN_DROP_VALUE * state)
		 */
		void dropCoin();

		/**
		 * Fungsi memeriksa apakah Guppy sedang dalam keadaan lapar atau tidak
		 * @return TRUE jika hunger <= HUNGER_TIME, FALSE jika tidak
		 */
		bool isHungry();

		/// Getter
		double getRadius() const;
		int getHunger();
		int getState();
		int getTimesEaten();
		static LinkedList<Coin> *&getListCoin();
		static LinkedList<FishFood> *&getListFishFood();
		static LinkedList<Guppy> *&getListGuppy();

		/// Setter
		void setHunger(int);
		void setState(int);
		void setTimesEaten(int);
		
		/**
		 * @Override
		 * @param objek Guppy
		 * @return TRUE jika kedua Guppy yang dibandingkan bukan objek yang sama, FALSE jika tidak
		 * Membandingkan kedua Guppy berdasarkan kesamaan posisi x dan posisi y
		 */
		bool operator!=(const Guppy &);

	protected:
		/// Titik x,y target pergerakan acak
		double targetX, targetY;

	private:
		/// Daftar Atribut
		int hunger, state, timesEaten;
		double lastDropTime, lastHungerTime, lastLoopTime, lastMoveTime;

		/// Atribut LinkedList
		static LinkedList<Coin>* & getObjectListCoin() {
	        static LinkedList<Coin>* list_coin;
	        return list_coin;
    	}
    	static LinkedList<FishFood>* & getObjectListFishFood() {
	        static LinkedList<FishFood>* list_fish_food;
	        return list_fish_food;
    	}
    	static LinkedList<Guppy>* & getObjectListGuppy() {
	        static LinkedList<Guppy>* list_guppy;
	        return list_guppy;
    	}

    	FishFood* targetFood;
		
		/// Daftar Konstanta
		const static int HUNGER_TIME = 40;
		const static int DROP_TIME = 15;
		const static int MAX_HUNGER = 60;
		const static int COIN_DROP_VALUE = 7;
		const static int VELOCITY = 50;
		constexpr static double radius = 30;
};

#endif