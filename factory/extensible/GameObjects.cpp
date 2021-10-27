// @file GameObjects.cpp
#include "GameObjects.hpp"
#include "Factory.hpp"

int Plane::ObjectsCreated = 0;

// Initialize our static
MyGameObjectFactory::CallBackMap MyGameObjectFactory::s_Objects;
