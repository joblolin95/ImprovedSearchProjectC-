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
	static const int CAPACITY = 10;
	int size;
	T * ptr;

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
	void copy(MyArrayListTest<T> oldList);
	
};

// Implementation
//-------------------------------------------
template < typename T >
MyArrayListTest<T>::MyArrayListTest()
{
	size = 0;
	ptr = new T[CAPACITY];

}

template<typename T>
MyArrayListTest<T>::MyArrayListTest(T e) {

	ptr = new T[CAPACITY];
	size = 0;
	this.addLast(e);

}// end constructor

template <typename T>
MyArrayListTest<T>::MyArrayListTest(T * nPtr) {

	size = 0;
	while (*nPtr != '\0') {
		size++;
		nPtr++;
	}// end while

	nPtr[0];
	ptr = new char[size + CAPACITY];
	for (int i = 0; i < size; i++) {

		ptr[i] = nPtr[i];

	}// end for
}// end constructor with arg


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
	/*char * ptr2 = arrPtr;*/

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
	/*char * ptr2 = arrPtr;*/
	if (isFull()) {

		T * temp = new T[size + CAPACITY];

		for (int i = 0; i < size; i++) {

			temp[i] = ptr[i];

		}// end for
		delete ptr;
		temp[0];
		ptr = temp;

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
	for (int i = 0; i < size; i++) {
		if (e == ptr[i]) {
			response = true;
		}// end if
	}// end for
	return response;
}// end contains method



template<typename T>
void MyArrayListTest<T>::displayList() {

	/*cout << ptr[0] << endl;
	cout << ptr[1] << endl;
	*/


	for (int i = 0; i < size; i++) {
		cout << ptr[i];
		cout << " ";
	}// end for
	cout << endl;


}// end method

template<typename T>
T MyArrayListTest<T>::getElement(int index) {

	T * ptr2 = ptr;
	if (index < getSize()) {
		return ptr2[index];
	}// end else
	else {
		return NULL;
	}// end else

}// end method


template<typename T>
void MyArrayListTest<T>::copy(MyArrayListTest<T> oldList) {

	size = oldList.getSize();
	delete ptr;

	ptr = new T[size + CAPACITY];

	for (int i = 0; i < oldList.getSize(); i++) {

		ptr[i] = oldList.getElement(i);

	}// end for

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