#include "stdafx.h"
#include "graph.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    Graph myGraph;
    myGraph.readFile(fin);
    fin.close();

    myGraph.dijkstra();

    _asm nop;
}