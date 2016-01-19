#pragma once
#include "Search.h"
#include <iostream>
#include <limits>

using namespace std;

class Dijkstra : public Search
{
// Declarations
//----------------------------------------------------
private:
	bool visited[INTERSECTIONS];
	int dist[INTERSECTIONS];
	int pre[INTERSECTIONS];

public:
	Dijkstra();
	~Dijkstra();

	void dijkstra(int begin, int end);
	int minVertex();
	void displayList();

};

// Implementation
//--------------------------------------------------------

/* pre : none
post: distanceSum and visited attributes are initialized

This is the default constructor for the Dijkstra class. It initializes
the distanceSum and visited attributes

*/
Dijkstra::Dijkstra()
{
	distanceSum = numeric_limits<int>::max();
	for (int i = 0; i < INTERSECTIONS; i++) {
		visited[i] = false;
	}// end for

}// end constructor


 /* pre : receives a begin point and an end point as integers
 post: the pre and dist attributes are given values

 This method performs Dijkstra's Algorithm upon a data set using a begin and end point
 */
void Dijkstra::dijkstra(int begin, int end) {

	this->begin = begin;
	this->end = end;

	for (int i = 0; i < INTERSECTIONS; i++) {
		dist[i] = numeric_limits<int>::max();
	}// end for
	dist[begin] = 0;
	pre[begin] = -1;

	for (int j = 0; j < INTERSECTIONS; j++) {
		int next = minVertex();
		visited[next] = true;

		for (int k = 0; k < INTERSECTIONS; k++) {

			if (distance[next][k] != -1 && distance[next][k] != 0) {

				int d = dist[next] + distance[next][k];
				if (dist[k] > d) {
					dist[k] = d;
					pre[k] = next;
				}// end nested if
			}// end if
		}// end for
	}// end for
}// end dijkstra method


 /* pre : none
 post: returns the intersection number as an integer that is the next best choice for traversal

 This method returns the best intersection to traverse as an integer, based upon the current
 states of the visited and dist attributes
 */

int Dijkstra::minVertex() {

	int x = numeric_limits<int>::max();
	int y = -1;

	for (int i = 0; i < INTERSECTIONS; i++) {

		if (!visited[i] && dist[i] < x) {
			x = dist[i];
			y = i;
		}// end if

	}// end for

	return y;

}// end minVertex method


 /* pre : none
 post: displays the shortest path

 This method uses the overloaded displayList method from the Search class to print out the shortest path
 */
void Dijkstra::displayList() {

	shortestList.addFront(end);
	int i = pre[end];
	while (i != -1) {

		shortestList.addFront(i);

		i = pre[i];


	}// end while


	Search::displayList();

}// end displayList method


 /* pre : none
 post: Dijkstra object is destroyed

 This is the destructor for the class
 */
Dijkstra::~Dijkstra()
{
}// end destructor