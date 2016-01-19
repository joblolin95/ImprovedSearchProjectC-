// SearchProject.cpp : Defines the entry point for the console application.
//
#include "Search.h"
#include "Dijkstra.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;


int main()
{
	//Get data
	Search dfs;
	dfs.populateMatrix("distanceMatrix.txt");
	

	dfs.displayKey();

	Dijkstra d;
	d.populateMatrix("distanceMatrix.txt");
	
	// Get input
	cout << "Enter the start intersection number: ";
	int begin;
	cin >> begin;
	
	cout << "Enter the end intersection number: ";
	int end;
	cin >> end;

	//Perform DFS algorithm
	dfs.DFS(begin, end);
	cout << "-------------------------" << endl;
	cout << "DFS" << endl;
	dfs.displayList();

	//Perform Dijkstra's algorithm
	d.dijkstra(begin, end);
	cout << "-------------------------" << endl;
	cout << "DIJKSTRA" << endl;
	d.displayList();

	cout << "Press Enter to Exit" << endl;
	cin.ignore(10, '\n');	
	cin.get();
	return 0;
}

