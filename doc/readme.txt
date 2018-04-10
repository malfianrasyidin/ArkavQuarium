TUGAS BESAR 1 OOP - K02D
	13516014 - Renjira Naufhal Dhiaegana
	13516035 - Muhammad Sulthan Adhipradhana
	13516074 - Muhammad Abdullah Munir
	13516104 - Muhammad Alfian Rasyidin

CARA MENJALANKAN PROGRAM
	1. Buka terminal pada folder utama program
	2. Ketik make, dan klik Enter
	3. Setelah program berhasil dikompilasi, ketik ./oopquarium dan klik Enter

HAL-HAL YANG HARUS DIPERHATIKAN
	Untuk dapat menjalankan program yang menggunakan *library* ini, diperlukan
	instalasi empat *library*, yaitu:

	- SDL2
	- SDL2_Image
	- SDL2_TTF
	- SDL2_Mixer

	Pada Ubuntu, ketiga *library* tersebut dapat diinstall dengan perintah berikut:

		apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev

	Pada Fedora, ketiga *library* tersebut dapat diinstall dengan perintah berikut:

		yum install SDL2-devel SDL2_image-devel SDL2_ttf-devel SDL2_mixer-devel

	Untuk sistem lain, dapat mengikuti instruksi di halaman-halaman berikut:
	- [SDL2](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)
	- [SDL2_Image](https://www.libsdl.org/projects/SDL_image/)
	- [SDL2_TTF](https://www.libsdl.org/projects/SDL_ttf/)
	- [SDL2_Mixer](https://www.libsdl.org/projects/SDL_mixer/)

	Untuk melihat fungsi-fungsi yang disediakan *library* ini, bacalah komentar di
	file `oop.hpp` dan contoh pemakaian di `main.cpp`.