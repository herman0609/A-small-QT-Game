#ifndef CAVE_H
#define CAVE_H

#include "location.h"
#include "coin.h"
#include "mushroom.h"
#include "rock.h"

#include "tom.h"
#include "thing.h"
using namespace std;

class Tom; // forward reference

// A cave which contains everything, including tom.
class Cave
{
public:
    Cave(){};
    Cave(int width, int height);
    ~Cave();
    Location*** getMap() {return map;}
    void command (string s);
    void show();
    Tom *getTom() {return tom;}
    int getWidth() {return width;}
    int getHeight() {return height;}
    Cave(const Cave &c);
    Cave operator=(const Cave& c);

private:
    int width, height;
    Tom *tom;
    Location*** map;
};

#endif // CAVE_H
