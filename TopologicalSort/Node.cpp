#include "Node.h"

Node::Node(int v, int w)
{
	this->vertex = v;
	this->weight = w;
}

int Node::getVertex()
{
	return this->vertex;
}

int Node::getWeight()
{
	return this->weight;
}
