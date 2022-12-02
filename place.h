#ifndef PLACE_H
#define PLACE_H

#include "coin.h"
#include "command.h"
#include "mushroom.h"
#include "rock.h"
#include <iostream>

using namespace std;
//Add things in this location
class Place : public Command
{
public:
    Place() : Command("place") {};
    void fire(Cave& c, string userCommand);
};
//Throw things in the direction near tom
//It can be the north south east or west
class Throw : public Command {
public:
    Throw() : Command("throw") {};

    void fire(Cave& c, string userCommand);
};


//A chain explode of the bomb
//All adjacent bombs (to the north, south, east, and west) also explode in the chain reaction -
//this continues until no more bombs are adjacent.
//An exploding bomb destroys all objects (including Rocks, but not including Tom) in the same Location.
class Explode : public Command {
public:
    Explode() : Command("explode") {};

    void chain(Cave& c,int X, int Y);

    void fire(Cave& c, string userCommand);

};

#endif // PLACE_H
