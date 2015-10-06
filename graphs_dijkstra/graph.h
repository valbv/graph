#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include "node.h"
#include "arc.h"

class Graph
{
    vector<Node> _nodes;
    vector<Arc> _arcs;
    Node * pathBegin;
    Node * pathEnd;

    vector <void (Graph:: *) (ifstream & fin, const string & strLine)> _readFuncs;

public:
    explicit Graph();
    
    void readNode(ifstream & fin, const string & strLine);
    void readArc(ifstream & fin, const string & strLine);
    void readPathBegin(ifstream & fin, const string & strLine);
    void readPathEnd(ifstream & fin, const string & strLine);
    void readFile(ifstream & fin);

    void dijkstra();
    virtual ~Graph();
};
#endif
