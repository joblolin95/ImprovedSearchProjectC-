#pragma once
#include "MyArrayListTest.h"
#include <limits>
#include <fstream>
#include <iostream>

using namespace std;
class Search
{

protected:
	static const int INTERSECTIONS = 28;
	int distance[INTERSECTIONS][INTERSECTIONS];
	int distanceSum;
	int begin;
	int end;
	MyArrayListTest<int> shortestList;

private:
	 string KEY[INTERSECTIONS] = { "135 - 337", "135 - 62", "135 - 64", "135 - Quarry Rd", "Quarry Rd - Corydon Ramsey Rd", "Corydon Ramsey Rd - 62", "337 - 62", "62 - 64", "Crandall Lanesville Rd - 62", "Crandall Lanesville Rd - 64", "64 - 265", "265 - 65", "265 - Grant Line Rd", "265 - Charlestown Rd", "Grant Line Rd - Klerner Ln", "Grant Line Rd - Mt Tabor Rd", "Klerner Ln - Mt Tabor Rd", "Mt Tabor Rd - Charlestown Rd", "Charlestown Rd - Blackiston Mill Rd", "Charlestown Rd - 60", "Charlestown Rd - 31", "60 - 31", "Blackiston Mill Rd - 31", "Veterans Parkway - 31", "65 - 60", "65 - Veterans Parkway", "65 - 31", "62 - 11" };

public:
	// Declarations
	//-----------------------------------------------------
	Search();
	~Search();
	Search(string fileName);
	void populateMatrix(string fileName);
	void DFS(int start, int finish);
	void DFSHelper(MyArrayListTest<int> list, int sum, bool * visited);
	void displayList();
	void displayKey();
		
	};

// Implementation
//-----------------------------------------------------
/* pre : none
post: distanceSum attribute is initialized

This is the default constructor. It initializes the distanceSum attribute.

*/
Search::Search()
{
	distanceSum = numeric_limits<int>::max();
}


/* pre : receives a string fileName of the file to get the data from
post: distanceSum is initialized and the distance attribute is initialized

This is a constructor that initializes the distanceSum attribute and calls the populateMatrix
method to initialize the distance attribute

*/
Search::Search(string fileName) {

	distanceSum = numeric_limits<int>::max();
	populateMatrix(fileName);

}// end constructor


 /* pre : receives a string fileName of the file to read the data from
 post: the distance attribute is now initialized and filled

 This method reads the data from the file with the given name, and fills
 the distance attribute with that data

 */
void Search::populateMatrix(string fileName) {

	ifstream inf;
	inf.open(fileName);

	if (!inf.is_open()) {

		cerr << fileName << " could not be read!" << endl;
		cin.get();
		exit(1);

	}// end if

	for (int i = 0; i < INTERSECTIONS; i++) {
		for (int j = i; j < INTERSECTIONS; j++) {
			int num;
			inf >> num;
			if (i != j && num == 0) {
				distance[i][j] = -1;
			}// end if
			else {
				distance[i][j] = num;
			}// end else

			distance[j][i] = num;

		}// end for
	}// end for
	inf.close();

}// end populateMatrix


 /* pre : receives a start intersection and a finish intersection as integers
 post: the shortestPath list now holds the shortest path

 This method jumpstarts the DFS algorithm by taking the start and end points as integers
 and calling the DFSHelper method

 */
void Search::DFS(int start, int finish) {

	begin = start;
	end = finish;

	int sum = 0;
	MyArrayListTest<int> list;
	list.addLast(begin);

	bool visited[INTERSECTIONS];
	for (int i = 0; i < INTERSECTIONS; i++) {
		visited[i] = false;
	}
	visited[begin] = true;

	DFSHelper(list, sum, visited);

}// end DFS method

 /* pre : receives a MyArrayListTest object, an integer sum, and a boolean pointer to an array
 post: shortestPath is updated to hold the shortest path

 This method receives a MyArrayList list, an integer sum, and a boolean pointer to an array to
 do the grunt work of the DFS algorithm, finding the shortest path.

 */

void Search::DFSHelper(MyArrayListTest<int> list, int sum, bool * visited) {

	if (sum < distanceSum && list.getElement(list.getSize() - 1) == end) {
		//                System.out.println(list);
		//                System.out.println("Distance: " + sum);
		shortestList = list;
		distanceSum = sum;

	}// end if
	else if (sum < distanceSum) {

		for (int i = 0; i < INTERSECTIONS; i++) {
			int lastInt = list.getElement(list.getSize() - 1);
			int num1 = distance[lastInt][i];
			bool truth = visited[i];

			if (distance[lastInt][i] != -1 && distance[lastInt][i] != 0 && !visited[i]) {
				bool v2[INTERSECTIONS];
				visited[0];
				for (int k = 0; k < INTERSECTIONS; k++) {

					v2[k] = visited[k];

				}// end for
				v2[i] = true;

				MyArrayListTest<int> list2;

				for (int j = 0; j < list.getSize(); j++) {

					list2.addLast(list.getElement(j));

				}// end for
				list2.addLast(i);
				int sum2 = distance[lastInt][i];
				int sum3 = sum2 + sum;

				DFSHelper(list2, sum3, v2);

			}// end if
		}// end for

	}// end else if
}// end method


 /* pre : none
 post: prints out the shortest path using KEY and shortestPath

 This method prints out the shortest path

 */

void Search::displayList() {
	cout << "Go" << endl;

	for (int i = 0; i < shortestList.getSize() - 1; i++) {

		cout << KEY[shortestList.getElement(i)] << " to " << KEY[shortestList.getElement(i + 1)] << endl;
	}// end for

	cout << "Stop --- Arrived at destination" << endl;

}// end displayList method


 /* pre : none
 post: the key is printed to the user

 This method prints out the KEY so the user can decide the start and end intersections

 */

void Search::displayKey() {

	for (int i = 0; i < INTERSECTIONS; i++) {

		cout << i << ". " << KEY[i] << endl;

	}// end for


}// end method

 /* pre : none
 post: the Search object is destroyed

 This is the destructor for the Search class

 */
Search::~Search()
{
	cout << "Deconstructed Search object" << endl;
}

