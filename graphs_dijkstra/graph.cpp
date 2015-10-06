#include "stdafx.h"
#include "graph.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

Graph::Graph()
{
    _readFuncs.push_back(& Graph::readNode);
    _readFuncs.push_back(& Graph::readArc);
    _readFuncs.push_back(& Graph::readPathBegin);
    _readFuncs.push_back(& Graph::readPathEnd);
};

void Graph::readNode(ifstream & fin, const string & strLine)
{
    _nodes.push_back(Node(strLine));
}

void Graph::readArc(ifstream & fin, const string & strLine)
{
    string argFrom, argTo, argWeight;
    stringstream strStream;
    strStream << strLine;
    strStream >> argFrom >> argTo >> argWeight;

    /* Arc-pointer "from" */
    Node * from = &* find_if(_nodes.begin(), _nodes.end(), [&](const Node & node)
    {
        return node.getNodeName() == argFrom;
    });

    /* Arc-pointer "to" */
    Node * to = &* find_if(_nodes.begin(), _nodes.end(), [&](const Node & node)
    {
        return node.getNodeName() == argTo;
    });

    /* Arc-weight */
    float argArcWeight = stof(argWeight);

    _arcs.push_back(Arc(from, to, argArcWeight));
}

void Graph::readPathBegin(ifstream & fin, const string & strLine)
{
    pathBegin = &* find_if(_nodes.begin(), _nodes.end(), [&](const Node & node)
    {
        return node.getNodeName() == strLine;
    });

    pathBegin->setNodeMinWeight(0);
}

void Graph::readPathEnd(ifstream & fin, const string & strLine)
{
    pathEnd = &* find_if(_nodes.begin(), _nodes.end(), [&](const Node & node)
    {
        return node.getNodeName() == strLine;
    });
}

void Graph::readFile(ifstream & fin)
{
    int state = -1;
    string strLine;

    while (getline(fin, strLine))
    {
        if (strLine == "***Nodes:")
        {
            state = 0;
            continue;
        }

        if (strLine == "***Arcs: (from to weight)")
        {
            state = 1;
            continue;
        }

        if (strLine == "***Path-begin:")
        {
            state = 2;
            continue;
        }

        if (strLine == "***Path-end:")
        {
            state = 3;
            continue;
        }

        if (state >= 0)
        {
            (this->*_readFuncs[state])(fin, strLine);
        }
    }
}

void Graph::dijkstra()
{
    for (size_t i = 0; i < _nodes.size(); ++i)
    {
        size_t minWeightElementNumber = 0;
        float weight = numeric_limits<float>::max();

        for (size_t k = 0; k < _nodes.size(); ++k)
        {
            if (!_nodes[k].getChecked() && _nodes[k].getNodeMinWeight() < weight)
            {
                weight = _nodes[k].getNodeMinWeight();
                minWeightElementNumber = k;
            }
        }

        for (size_t j = 0; j < _arcs.size(); ++j)
        {
            if (_arcs[j].getFrom() == &_nodes[minWeightElementNumber] &&
                _arcs[j].getTo()->getNodeMinWeight() >(_arcs[j].getFrom()->getNodeMinWeight() + _arcs[j].getWeight()))
            {
                _arcs[j].getTo()->setNodeMinWeight(_arcs[j].getFrom()->getNodeMinWeight() + _arcs[j].getWeight());
                _arcs[j].getTo()->setNodeFrom(_arcs[j].getFrom());
            }
        }

        _nodes[minWeightElementNumber].setChecked();
    }

    vector<string> shortcut;

    while (pathEnd != nullptr)
    {
        shortcut.push_back(pathEnd->getNodeName());
        pathEnd = pathEnd->getNodeFrom();
    }

    for (vector<string>::reverse_iterator & a = shortcut.rbegin(); a != shortcut.rend(); ++a)
    {
        cout << *a << " ";
    }
}

Graph::~Graph() {};