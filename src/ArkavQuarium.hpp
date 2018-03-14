/* 
	TUGAS KECIL OOP - K02D
	13516014 - Renjira Naufhal Dhiaegana
	13516035 - Muhammad Sulthan Adhipradhana
	13516104 - Muhammad Alfian Rasyidin
	13516074 - Muhammad Abdullah Munir
*/

//Definisi kelas Aquarium
class Aquarium{
	public:
		Aquarium();
		~Aquarium();
		
	private:
		int x,y;
		const static int MAX_X = 100, MAX_Y = 100;
};

//Definisi Kelas Abstrak AquariumObject
class AquariumObject{
	public:
		virtual void move() = 0;
		
		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);
		
	private:
		int x,y;
};

//Definisi 
class Fish : public AquariumObject
{
public:
	virtual void eat() = 0;
	virtual void dropCoin() = 0;
};

//kelas ikan-ikan
class Guppy : public AquariumObject{
	public:
		Guppy();
		~Guppy();
		void move();
		void eat();

	private:
		int hunger,drop_time,state;
		const static int HUNGER_TIME;
};

class Piranha : public AquariumObject
{
	public:
		Piranha();
		~Piranha();
		void move();
		void eat();

	private:
		int hunger,drop_time,state;
		const static int HUNGER_TIME;		
};

//kelas snail
class Snail : public AquariumObject
{
	public:
		Snail();
		~Snail();
		void move();
		void grabCoin();
};

//class makananikan
class FishFood : public AquariumObject
{
public:
	FishFood();
	~FishFood();
	void move();

};

class Coin : public AquariumObject
{
	public:
		Coin();
		~Coin();
		void move();
		
	private:
		int value;
};

template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		int find(const T&);
		bool isEmpty();
		void add(const T&);
		void remove(const T&);
		T& get(int);

	private:
		T data;
		LinkedList *next;
};


