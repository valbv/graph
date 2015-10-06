#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

class Node
{
    string _nodeName;
    float _nodeMinWeight;
    bool _nodeChecked;
    Node * _nodeFrom;

public:
    Node();
    Node(string name);
    void setNodeMinWeight(const float & weight);
    void setChecked();
    void setNodeFrom(Node * nodeFrom);

    const string & getNodeName() const;
    Node * getNodeFrom();
    float & getNodeMinWeight();
    bool & getChecked();
};
#endif