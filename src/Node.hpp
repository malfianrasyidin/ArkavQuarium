#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

//Definisi kelas Node
template <class T>
class Node{
	public:
		//ctor
		Node(T* data){
			this->data = data;
		}

		//dtor
		~Node(){
			delete this->data;
		}

		//getter
		T& getData() {
			return (*data);
		}
		Node<T>* getNext(){
			return this->next;
		}

		//setter
		void setNext(Node<T>* next){
			this->next = next;
		}

	private:
		T* data;
		Node<T>* next;
};

#endif