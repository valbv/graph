#ifndef _NODE_H_
#define _NODE_H_

#include <vector>

using namespace std;

class Node
{
    string _nodeName;
    float _nodeWeight;
    bool _nodeChecked;
    Node * _nodeFrom;
    vector<size_t> _ownArcs;

public:
    Node();
    Node(string name);
    void setNodeWeight(const float & weight);
    void setChecked();
    void setNodeFrom(Node * nodeFrom);
    void setOwnArc(const size_t & arcNumber);

    const string & getNodeName() const;
    Node * getNodeFrom();
    float & getNodeWeight();
    bool & getChecked();
    size_t & getOwnArc(size_t & arcNumber);
    const size_t & getQuantityOwnArcs();
};
#endif