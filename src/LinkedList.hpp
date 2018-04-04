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
		LinkedList() {
			this->count = 0;
			this->first = NULL;
		}
		
		//dtor
		~LinkedList() {
			while (!isEmpty()) {
				remove(*first);
			}
		}

		//mendapatkan indeks dari LinkedList yang terdapat T
		int find(Node<T>& node) {
			Node<T>* it = first;
			int i = 0;

			while (((*it).getNext() != NULL)  && ((*it).getData() != node.getData())) {
				it = (*it).getNext();
				i++;
			} 

			return (i == count ? -1 : i);
		}
		
		//mengecek apakah LinkedList kosong
		bool isEmpty() {
			return (getCount() == 0);
		}

		//menambah Node T
		void add(Node<T>* node){
			count++;
			(*node).setNext(first);
			first = node;
		}
		
		//menghapus Node T
		void remove(Node<T>& node){
			int i = find(node);
			Node<T>* it = first;

			for (int j=0; j<i-1; j++){
				it = (*it).getNext();
			}

			if (i==0) {
				count--;
				first = (*it).getNext();
				delete it;
			}
			else {
				count--;
				Node<T>* temp = (*it).getNext();
				(*it).setNext((*it).getNext()->getNext());
				delete temp;
			}
		}
		
		//getter
		Node<T>& get(int idx) {
			Node<T>* it = first;
			for (int i=0; i<idx; i++)
				it = (*it).getNext();
			return *it;
		}

		int getCount(){
			return this->count;
		}

	private:
		Node<T>* first;
		int count;
};


#endif