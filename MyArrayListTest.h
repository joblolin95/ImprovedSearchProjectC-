#pragma once
#include <string>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <array>
#include <iostream>
#include <cctype>
using namespace std;


template < typename T > 
class MyArrayListTest
{
private:
	// private data fields
	static const int CAPACITY = 10;
	int size;
	T * ptr;

	// private methods
	bool isFull();

public:
	// Declarations
	//--------------------------------------------
	MyArrayListTest();
	MyArrayListTest(T e);
	MyArrayListTest(T * nPtr);
	~MyArrayListTest();

	void addLast(T e);
	int getSize();
	void addFront(T e);
	bool contains(T e);
	T getElement(int index);
	T removeElementAt(int index);
	void displayList();
	MyArrayListTest<T>& operator=(MyArrayListTest<T> oldList);
	
};

// Implementation
//-------------------------------------------
template < typename T >
MyArrayListTest<T>::MyArrayListTest()
{
	size = 0;
	ptr = new T[CAPACITY];// create pointer array
}

template<typename T>
MyArrayListTest<T>::MyArrayListTest(T e) {
	// Create pointer array
	ptr = new T[CAPACITY];
	size = 0;
	this.addLast(e);

}// end constructor


template<typename T>
bool MyArrayListTest<T>::isFull() {
	return size % CAPACITY == 0;
}// end isFull

template<typename T>
int MyArrayListTest<T>::getSize() {
	return size;
}// end method

template<typename T>
void MyArrayListTest<T>::addLast(T e) {

	if (isFull()) {

		T * temp = new T[size + CAPACITY];

		for (int i = 0; i < size; i++) {

			temp[i] = ptr[i];

		}// end for
		delete ptr;
		temp[0];
		ptr = temp;

	}// end if
	ptr[size] = e;
	size++;

	//cout << "arrPtr[size - 1] = " << arrPtr[size - 1] << endl;
}// end addFront

template<typename T>
void MyArrayListTest<T>::addFront(T e) {
	if (isFull()) {
		T * temp = new T[size + CAPACITY];

		for (int i = 0; i < size; i++) {
			temp[i] = ptr[i];
		}// end for

		delete ptr;
		temp[0];
		ptr = temp;
	}// end if

	for (int k = size; k > 0; k--) {
		ptr[k] = ptr[k - 1];
	}// end for

	ptr[0] = e;
	size++;
}// end addFront

template<typename T>
T MyArrayListTest<T>::removeElementAt(int index) {
	T removed = NULL;

	if (index >= 0 && index < size) {
		removed = ptr[index];

		for (int j = index + 1; j < size; j++) {
			ptr[j - 1] = ptr[j];
		}// end for

		size--;
	}// end if
	return removed;
}// end removeElementAt method

template<typename T>
bool MyArrayListTest<T>::contains(T e) {

	bool response = false;
	int i = 0;
	while (e != ptr[i] && i < size) {
		i++;
	}
	if (i >= 0 && i < size) { response = true; }
	return response;
}// end contains method

template<typename T>
void MyArrayListTest<T>::displayList() {

	for (int i = 0; i < size; i++) {
		cout << ptr[i];
		cout << " ";
	}// end for
	cout << endl;


}// end method

template<typename T>
T MyArrayListTest<T>::getElement(int index) {

	
	if (index < getSize() && index >= 0) {
		return ptr[index];
	}// end else
	else {
		return NULL;
	}// end else

}// end method


template<typename T>
MyArrayListTest<T>& MyArrayListTest<T>::operator=(MyArrayListTest<T> oldList) {

	size = oldList.getSize();
	delete ptr;

	ptr = new T[size + CAPACITY];

	for (int i = 0; i < size; i++) {
		ptr[i] = oldList.getElement(i);
	}// end for
	return *this;
}// end copy

template<typename T>
MyArrayListTest<T>::~MyArrayListTest()
{
	if (*ptr) {
		//std::cout << "Deconstructed MyArrayListTest object" << endl;
		//delete [] ptr;
		ptr = 0;
	}
}