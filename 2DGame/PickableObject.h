#pragma once
#include "GameObject.h"
class PickableObject : public GameObject
{
public:
    uint16_t dist = 10;

public:
    PickableObject();
};

