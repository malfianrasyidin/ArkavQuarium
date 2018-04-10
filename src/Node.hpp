#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

/**
 * Definisi Kelas Template Node
 * Fungsi:
 * Kelas ini digunakan untuk menyimpan informasi
 * data dari objek-objek dalam LinkedList
 */
template <class T>
class Node{
	public:
		/// User defined ctor
		Node(T* data){
			this->data = data;
		}

		/// Default dtor
		~Node(){
			delete this->data;
		}

		/// Getter
		T& getData() {
			return (*data);
		}
		Node<T>* getNext(){
			return this->next;
		}

		/// Setter
		void setNext(Node<T>* next){
			this->next = next;
		}

	private:
		/// Atribut yang menyimpan data Node
		T* data;
		/// Atribut yang menyimpan alamat Node berikutnya
		Node<T>* next;
};

#endif