TUGAS KECIL OOP - K02D
	13516014 - Renjira Naufhal Dhiaegana
	13516035 - Muhammad Sulthan Adhipradhana
	13516104 - Muhammad Alfian Rasyidin
	13516074 - Muhammad Abdullah Munir

PENJELASAN TUGAS
1. Kelas Aquarium
- Kelas ini berisikan LinkedList dari objek-objek Aquarium tersebut.
- Nilai maksimum X dan Y juga didefinisikan di kelas ini.

2. Kelas AquariumObject
- Kelas ini merupakan kelas abstrak dari seluruh objek yang berada di dalam aquarium. 
- Method-method bawaan dari setiap objek di dalam aquarium yang sama juga didefinisikan di dalam kelas ini.
- Method move() akan dilakukan overwrite oleh kelas-kelas turunannya nanti.

3. Kelas Coin
- Kelas ini merupakan kelas turunan dari kelas AquariumObject.
- Kelas ini didefinisikan sebagai kelas objek dari koin sesuai yang dijelaskan di dalam spesifikasi.

4. Kelas Fish
- Kelas ini merupakan kelas abstrak dari seluruh objek ikan yang berada di dalam aquarium.
- Objek-objek Fish meliputi Guppy dan Piranha.
- Method-method di kelas ini akan dilakukan overwrite oleh kelas-kelas turunannya nanti.

5. Kelas FishFood
- Kelas ini merupakan kelas turunan dari kelas AquariumObject.
- Kelas ini mempunyai method-method yang sesuai dengan spesifikasi tugas yang diberikan.

6. Kelas Guppy
- Kelas ini merupakan kelas turunan dari kelas AquariumObject dan Fish (multiple inheritance).
- Kelas ini mendefinisikan method-method yang dideklarasikan di kelas Fish dan AquariumObject.
- Fungsi dari kelas ini sesuai dengan spesifikasi tugas yang diberikan.

7. Kelas LinkedList
- Kelas ini merupakan kelas yang wajib dibuat di dalam tugas ini.
- Kelas ini merupakan kelas yang menggunakan sistem templating, sehingga dapat memiliki tipe yang berbeda-beda, sesuai dengan yang akan didefinisikan nanti.
- Kelas ini mempunyai data yang bertipe Node (sebuah kelas).

8. Kelas Node
- Kelas Node merupakan definisi kelas yang akan digunakan pada kelas LinkedList.
- Method-method yang dimilikinya yaitu method-method standar seperti ctor, dtor, setter, dan lainnya.
- Atribut data memiliki tipe T yang merupakan sebuah kelas templating.

9. Kelas Piranha
- Kelas Piranha merupakan kelas turunan dari kelas AquariumObject dan Fish (multiple inheritance).
- Kelas ini mendefinisikan method-method yang dideklarasikan di kelas Fish dan AquariumObject.
- Fungsi dari kelas ini sesuai dengan spesifikasi tugas yang diberikan.

10. Kelas Snail
- Kelas ini merupakan kelas turunan dari kelas AquariumObject.
- Kelas ini mendefinisikan method-method yang telah didefinisikan oleh kelas abstraknya.
