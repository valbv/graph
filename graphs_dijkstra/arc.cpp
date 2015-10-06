#include "stdafx.h"
#include "arc.h"

Arc::Arc(Node * from, Node * to, float & arcWeight)
    : _from(from)
    , _to(to)
    , _arcWeight(arcWeight)
{}

void Arc::setFrom(Node * from)
{
    _from = from;
}

void Arc::setTo(Node * to)
{
    _to = to;
}

void Arc::setWeight(float & arcWeight)
{
    _arcWeight = arcWeight;
}

Node * Arc::getFrom()
{
    return _from;
}

Node * Arc::getTo()
{
    return _to;
}

float Arc::getWeight()
{
    return _arcWeight;
}