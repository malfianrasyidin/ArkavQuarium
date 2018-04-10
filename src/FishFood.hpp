#ifndef FISHFOOD_HPP
#define FISHFOOD_HPP

#include <iostream>

#include "AquariumObject.hpp"
#include "../oop.hpp"

using namespace std;

/**
 * Definisi Kelas FishFood
 * Fungsi:
 * Kelas ini digunakan sebagai instance dari makanan Guppy
 * FishFood dibuat dengan cara pembelian dengan uang yang dimiliki oleh pemain
 */
class FishFood : public AquariumObject{
	public:
		/**
		 * User defined ctor
		 * @param posisi x dan posisi y
		 */
    	FishFood(double, double);

		/// Default dtor
    	virtual ~FishFood();

		/**
		 * @Override
		 * FishFood bergerak jatuh bebas dengan kecepatan semakin bertambah
		 * Jika FishFood telah sampai ke dasar, maka objek tersebut dihapus
		 */
    	void move();

        /// Default dtor
        double getRadius() const;

		/**
		 * @Override
		 * @param objek FishFood
		 * @return TRUE jika kedua FishFood yang dibandingkan bukan objek yang sama, FALSE jika tidak
		 * Membandingkan kedua FishFood berdasarkan kesamaan posisi x dan posisi y
		 */
		bool operator!=(const FishFood&);

    	/// Getter
    	static LinkedList<FishFood>* & getListFishFood();

    private:
		/// lastLoopTime adalah waktu terakhir FishFood mengalami penambahan kecepatan
		double lastLoopTime;
		/// VELOCITY merupakan nilai konstanta penambahan kecepatan
		const static int VELOCITY = 25;
		/// radius merupakan nilai jari-jari dari koin
		constexpr static double radius = 5;
		/// atribut yang berisikan seluruh objek-objek koin yang ada disimpan sebagai LinkedList
		static LinkedList<FishFood> *&getObjectListFishFood()
		{
			static LinkedList<FishFood> *list_fish_food;
			return list_fish_food;
		}
};

#endif