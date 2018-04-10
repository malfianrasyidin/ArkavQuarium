#ifndef AQUARIUMOBJECT_HPP
#define AQUARIUMOBJECT_HPP

#include <iostream>
#include "LinkedList.hpp"
#include "../oop.hpp"

using namespace std;

/**
 * Defisini Kelas Abstrak AquariumObject
 * Fungsi:
 * Kelas ini bersifat abstraksi dari kelas-kelas akuarium lainnya,
 * seperti Guppy, Piranha, Snail, FishFood, dan lainnya.
 */
class AquariumObject {
	public:
		/**
		 * ABC move()
		 * Setiap AquariumObject memiliki method move() yang akan
		 * didefinisikan pada kelas anak.
		 */
		virtual void move() = 0;

		/**
		 * @param AquariumObject
		 * @return TRUE jika kedua objek saling bersinggungan, FALSE jika tidak
		 * Kedua objek saling bersinggungan jika jumlah jari-jari kedua objek
		 * dikuadratkan kurang dari atau sama dengan jarak kuadrat antara
		 * kedua objek tersebut
		 */
		bool isIntersect(const AquariumObject&);

		/**
		 * @param nilai x, nilai y, dan nilai r (jari-jari)
		 * @return TRUE jika titik tersebut bersinggungan dengan objek, FALSE jika tidak
		 * Titik x,y saling bersinggungan jika selisih x dan selisih y dikuadratkan
		 * kurang dari atau sama dengan jumlah jari-jari dikuadratkan
		 */
		bool isIntersect(double, double, double);

		/**
		 * @param AquariumObject
		 * @return jarak kuadrat antara kedua objek
		 * Jarak kuadrat didefinisikan sebagai jumlah kuadrat dari selisih x dan selisih y
		 */
		double getDistance(const AquariumObject&);
		
		/// Getter
		double getX() const;
		double getY() const;
		virtual double getRadius() const = 0;
		
		/// Setter
		void setX(double);
		void setY(double);
		
	private:
		/// x adalah posisi absis, y adalah posisi ordinat
		double x, y;
};

#endif