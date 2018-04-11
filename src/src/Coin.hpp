#ifndef COIN_HPP
#define COIN_HPP

#include "AquariumObject.hpp"

/**
 * Definisi Kelas Coin
 * Fungsi:
 * Koin merupakan kelas turunan dari AquariumObject
 * Kelas ini dihasilkan oleh instance dari Fish, dan mempunyai nilai tertentu
 * Nilai-nilai tersebut nantinya digunakan untuk menambah uang untuk pemain selama permainan
 */
class Coin : public AquariumObject{
	public:
		/**
		 * User defined ctor
		 * @param posisi x, posisi y, dan nilai dari koin
		 */
		Coin(double, double, int);

		/// Default dtor
		virtual ~Coin();

		/**
		 * @Override
		 * Koin bergerak lurus jatuh bebas, dengan kecepatan semakin dipercepat
		 * Koin yang dihasilkan Guppy dan Piranha berbeda gambar dan nilai
		 */
		void move();

		/// Default getter
		int getValue() const;
		double getRadius() const;
		void setLoopTime(double);
		static LinkedList<Coin> *&getListCoin();

		/**
		 * @Override
		 * @param objek Coin
		 * @return TRUE jika kedua koin yang dibandingkan bukan objek yang sama, FALSE jika tidak
		 * Membandingkan kedua koin berdasarkan kesamaan nilai, posisi x, dan posisi y
		 */
		bool operator!=(const Coin&);
		
  	private:
	  	/// lastLoopTime adalah waktu terakhir koin mengalami penambahan kecepatan
  		double lastLoopTime;
		/// value adalah nilai/harga dari koin
		const int value;
		/// VELOCITY merupakan nilai konstanta penambahan kecepatan
    	const static int VELOCITY = 25;
		/// radius merupakan nilai jari-jari dari koin
    	constexpr static double radius = 25;
		/// atribut yang berisikan seluruh objek-objek koin yang ada disimpan sebagai LinkedList
		static LinkedList<Coin> *&getObjectListCoin()
		{
			static LinkedList<Coin> *list_coin;
			return list_coin;
		}
};

#endif