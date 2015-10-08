#include "stdafx.h"
#include "node.h"
#include <limits>

using namespace std;

Node::Node()
    : _nodeName("")
    , _nodeFrom(nullptr)
    , _nodeChecked(false)
    , _nodeWeight(numeric_limits<float>::max())
{}

Node::Node(string name)
    : _nodeName(name)
    , _nodeFrom(nullptr)
    , _nodeChecked(false)
    , _nodeWeight(numeric_limits<float>::max())
{}

void Node::setNodeWeight(const float & weight)
{
    _nodeWeight = weight;
}

void Node::setChecked()
{
    _nodeChecked = true;
}

void Node::setNodeFrom(Node * nodeFrom)
{
    _nodeFrom = nodeFrom;
}

void Node::setOwnArc(const size_t & arcNumber)
{
    _ownArcs.push_back(arcNumber);
}

const string & Node::getNodeName() const
{
    return _nodeName;
}

Node * Node::getNodeFrom()
{
    return _nodeFrom;
}

float & Node::getNodeWeight()
{
    return _nodeWeight;
}

bool & Node::getChecked()
{
    return _nodeChecked;
}

size_t & Node::getOwnArc(size_t & vecIndex)
{
    return _ownArcs[vecIndex];
}

const size_t & Node::getQuantityOwnArcs()
{
    return _ownArcs.size();
}