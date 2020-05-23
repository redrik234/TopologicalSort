#include <iostream>
#include <fstream>
#include "Graph.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "TopologicalSort.exe <input file path>.txt <output file path>.txt" << std::endl;
        return 0;
    }
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    if (!input.is_open())
    {
        std::cout << "Input file not exist" << std::endl;
        return 0;
    }

    if (!output.is_open())
    {
        std::cout << "Output file not exist" << std::endl;
        return 0;
    }

    int countOfVertex = 0;
    int countOfEdge = 0;
    int sourceVertex = 0;
    int targetVertex = 0;
    input >> countOfVertex >> countOfEdge >> sourceVertex >> targetVertex;

    Graph g(countOfVertex);
    int s, t, w;
    while (input >> s >> t >> w)
    {
        g.addEdge((int)s, (int)t, (int)w);
    }

    g.seachLongestPath(sourceVertex, targetVertex);
    g.outputInFile(output);

    return 0;
}
