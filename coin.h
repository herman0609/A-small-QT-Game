#ifndef COIN_H
#define COIN_H

#include "thing.h"

// a small coin that can be picked up.
class Coin : public Thing
{
    string getName()
    {
        return "coin";
    }
};
//A Bomb can be cain explode
class Bomb : public Thing
{
    string getName()
    {
        return "bomb";
    }
};

#endif // COIN_H
