#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

//Definisi kelas LinkedList
template <class T>
class LinkedList{
	public:
		//ctor
		LinkedList();
		
		//dtor
		~LinkedList();

		//mendapatkan indeks dari LinkedList yang terdapat T
		int find(const Node<T>&);
		
		//mengecek apakah LinkedList kosong
		bool isEmpty();

		//menambah Node T
		void add(const Node<T>&);
		
		//menghapus Node T
		void remove(const Node<T>&);
		
		//getter
		Node get(int);

	private:
		Node<T>* data;
		static int count;
		LinkedList *next;
};

#endif