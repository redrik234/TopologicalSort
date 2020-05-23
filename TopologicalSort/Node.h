#pragma once

class Node {

public:
	Node(int v, int w);
	int getVertex();
	int getWeight();

private:
	int vertex;
	int weight;
};