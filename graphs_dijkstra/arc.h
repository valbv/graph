#ifndef _ARC_H_
#define _ARC_H_

using namespace std;

class Node;

class Arc
{
    Node * _from;
    Node * _to;
    float _arcWeight;

public:
    Arc(Node * from, Node * to, float & arcWeight);
    
    void setFrom(Node * from);
    void setTo(Node * to);
    void setWeight(float & arcWeight);

    Node * getFrom();
    Node * getTo();
    float getWeight();
};
#endif