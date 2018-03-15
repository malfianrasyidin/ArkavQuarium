#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

//Definisi kelas Node
template <class T>
class Node{
	public:
		//ctor
		Node();

		//dtor
		~Node();

		//getter
		T get();

		//setter
		void set(const T&);

	private:
		T data;
};

#endif