#pragma once
#include "Node.h"
#include <list>
#include <stack>
#include <iostream>
#include <fstream>
#include <algorithm>

class Graph {

public:
	Graph(int countOfVertexs);
	void addEdge(int s, int v, int w);
	void seachLongestPath(int sourceVertex, int targetVertex);
	void outputInFile(std::ofstream& output);
	~Graph();

private:
	void topologicalSort(int v, bool visited[], std::stack<int>& stack, int* distTo, int* parentsList);
	void findPath(int* parents, int sourceVertex, int targetVertex);

	int countOfVertexs;
	std::list<Node>* adjList;
	std::list<int> path;
	int maxDist;
	int* distTo;
};