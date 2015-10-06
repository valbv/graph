#include "stdafx.h"
#include "node.h"
#include <limits>

using namespace std;

Node::Node()
    : _nodeName("")
    , _nodeFrom(nullptr)
    , _nodeChecked(false)
    , _nodeMinWeight(numeric_limits<float>::max())
{}

Node::Node(string name)
    : _nodeName(name)
    , _nodeFrom(nullptr)
    , _nodeChecked(false)
    , _nodeMinWeight(numeric_limits<float>::max())
{}

void Node::setNodeMinWeight(const float & weight)
{
    _nodeMinWeight = weight;
}

void Node::setChecked()
{
    _nodeChecked = true;
}

void Node::setNodeFrom(Node * nodeFrom)
{
    _nodeFrom = nodeFrom;
}

const string & Node::getNodeName() const
{
    return _nodeName;
}

Node * Node::getNodeFrom()
{
    return _nodeFrom;
}

float & Node::getNodeMinWeight()
{
    return _nodeMinWeight;
}

bool & Node::getChecked()
{
    return _nodeChecked;
}