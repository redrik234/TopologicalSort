#include "Graph.h"
#define NINF INT_MIN 

Graph::Graph(int countOfV)
{
	this->countOfVertexs = countOfV + 1;
	adjList = new std::list<Node>[countOfVertexs];
    distTo = new int[countOfVertexs];
    maxDist = 0;
}

Graph::~Graph()
{
	delete [] adjList;
}

void Graph::addEdge(int s, int v, int w)
{
	adjList[s].push_back(Node(v, w));
}

void Graph::topologicalSort(int v, bool visited[], std::stack<int>& stack, int* distTo, int* parentsList)
{
    visited[v] = true;
    std::list<Node>::iterator i;
    for (Node node:adjList[v]) {
        int currDist = distTo[v] + node.getWeight();
        if (distTo[node.getVertex()] < currDist)
        {
            distTo[node.getVertex()] = currDist;
            parentsList[node.getVertex()] = v;
        }

        if (!visited[node.getVertex()])
        {
            topologicalSort(node.getVertex(), visited, stack, distTo, parentsList);
        }
    }
    stack.push(v);
}

void printLocalDist(int v, Node node, int currDist)
{
    std::cout << "V: " << v << " W: " << node.getVertex() << " currDist: " << currDist << std::endl;
}

void Graph::findPath(int* parents, int sourceVertex, int targetVertex)
{
    if (sourceVertex != targetVertex && parents[targetVertex] != NINF)
    {
        path.push_back(targetVertex);
        findPath(parents, sourceVertex, parents[targetVertex]);
    }

    if (!path.empty() && targetVertex == sourceVertex)
    {
        path.push_back(targetVertex);
        path.reverse();
    }
    else 
    {
        std::list<int>::iterator it;
        it = std::find(path.begin(), path.end(), sourceVertex);
        if (it == path.end())
        {
            path.clear();
        }
    }
}

void Graph::seachLongestPath(int sourceVertex, int targetVertex)
{
	std::stack<int> stack;
    int* parentsList = new int[countOfVertexs];
	bool* visited = new bool[countOfVertexs];
    for (int i = 0; i < countOfVertexs; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i <= countOfVertexs; i++)
    {
        distTo[i] = NINF;
        parentsList[i] = NINF;
    }

    distTo[sourceVertex] = 0;

    std::cout << std::endl;
    for (int i = sourceVertex; i < countOfVertexs; ++i) {
        topologicalSort(i, visited, stack, distTo, parentsList);
    }
 
    findPath(parentsList, sourceVertex, targetVertex);
    maxDist = distTo[targetVertex];
    delete[] visited;
}

void Graph::outputInFile(std::ofstream& output)
{
    if (path.empty())
    {
        output << "No";
    }
    else
    {
        output << maxDist << std::endl;
        for (int i : path)
        {
            output << i << " ";
        }
    }
}
