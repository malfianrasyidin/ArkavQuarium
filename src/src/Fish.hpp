#ifndef FISH_HPP
#define FISH_HPP

/**
 * Definisi Kelas Abstrak Fish
 * Fungsi:
 * Kelas abstrak ini digunakan oleh kelas turunannya yaitu Guppy dan Piranha
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
