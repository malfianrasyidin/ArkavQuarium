#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

/**
 * Definisi Kelas Template LinkedList
 * Fungsi:
 * Kelas ini merupakan template class, yang dapat menyimpan objek-objek lain
 * Kelas ini digunakan untuk menyimpan semua objek-objek yang setipe yang ada dalam permainan
 */
template <class T>
class LinkedList{
	public:
		/// Default ctor
		LinkedList() {
			this->count = 0;
			this->first = NULL;
		}
		
		//Default dtor
		~LinkedList() {
			while (!isEmpty()) {
				remove((*first).getData());
			}
		}

		/**
		 * @param T&
		 * @return indeks dalam integer
		 * Fungsi ini akan mengembalikan nilai indeks dari LinkedList yang terdapat T
		 */
		int find(T& val) {
			Node<T>* it = first;
			int i = 0;

			while (((*it).getNext() != NULL) && ((*it).getData() != val)) {
				it = (*it).getNext();
				i++;
			} 

			return (i == count ? -1 : i);
		}
		
		/**
		 * @return TRUE jika LinkedList kosong, FALSE jika sebaliknya
		 */
		bool isEmpty() {
			return (getCount() == 0);
		}

		/**
		 * @param T*
		 * Menambahkan Node T* ke dalam LinkedList
		 */
		void add(T* val){
			Node<T> *node = new Node<T>(val);
			count++;
			(*node).setNext(first);
			first = node;
		}
		
		/**
		 * @param T&
		 * Menghapus Node T dari LinkedList
		 */
		void remove(T& node){
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
		
		/// Getter
		T& get(int idx) {
			Node<T>* it = first;
			for (int i=0; i<idx; i++)
				it = (*it).getNext();
			return (*it).getData();
		}
		int getCount(){
			return this->count;
		}

	private:
		/// Atribut yang menyimpan Node pertama dari LinkedList
		Node<T>* first;
		/// Atribut yang menyimpan banyaknya Node dalam LinkedList
		int count;
};

#endif