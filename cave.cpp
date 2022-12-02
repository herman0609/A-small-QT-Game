#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "cave.h"
#include "rock.h"
#include "thing.h"
#include "location.h"
#include "move.h"
#include "place.h"

using namespace std;
//Initialize the cave that we want to play
//If the size is not proper, we cannot launch it
//Set Tom in the middle of the map
Cave::Cave(int w, int h) : width(w), height(h) // width and height of the cave
{
    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    map = new Location**[width];

    for (int x = 0; x < width; x++) {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }

    // create some rocks
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++)
            if ((x == 0 || y == 0 || x == width-1 || y == height-1) )
                 map[x][y] -> add( new Rock() );
    }

    tom = new Tom();

    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}


//Delete the 3D array of the map
Cave::~Cave()
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++){
            delete (map[x][y]);}
        delete (map[x]);
    }// fixme: I don't think this deletes all Locations and arrays declared in the constructor...
    delete[] map; // fixme: ...neither does this.
}

//A Copy of Cave Function that the specification required
Cave::Cave(const Cave &c){
    width = c.width;
    height = c.height;
    map = new Location**[width];

    for (int x = 0; x < width; x++) {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++){
            column[y] = new Location();
            map[x][y]=column[y];
        }
    }
    for (int x = 0; x < c.width; x++) {
        for (int y = 0; y < c.height; y++){
            for (auto t : *c.map[x][y]->getThings()){
                if ( dynamic_cast<Bomb*>(t) ){
                    map[x][y] -> add( new Bomb() );
                }
                else if ( dynamic_cast<Coin*>(t) ){
                    map[x][y] -> add( new Coin() );
                }
                else if ( dynamic_cast<Mushroom*>(t) ){
                    map[x][y] -> add( new Mushroom() );
                }
                else if ( dynamic_cast<Rock*>(t) ){
                    map[x][y] -> add( new Rock() );
                }
        }
    }
    }
    tom = new Tom();
    tom ->setLocation(this, c.tom->getX(), c.tom->getY());
}
//A Copy of Cave Function
Cave Cave::operator=(const Cave& c){
    Cave cave;
    cave.width = c.width;
    cave.height = c.height;
    cave.map = new Location**[cave.width];

    for (int x = 0; x < cave.width; x++) {
        Location** column = new Location*[cave.height];
        cave.map[x] = column;
        for (int y = 0; y < cave.height; y++){
            column[y] = new Location();
            cave.map[x][y]=column[y];
        }
    }
    for (int x = 0; x < c.width; x++) {
        for (int y = 0; y < c.height; y++){
            for (auto t : *c.map[x][y]->getThings()){
                if ( dynamic_cast<Bomb*>(t) ){
                    cave.map[x][y] -> add( new Bomb() );
                }
                else if ( dynamic_cast<Coin*>(t) ){
                    cave.map[x][y] -> add( new Coin() );
                }
                else if ( dynamic_cast<Mushroom*>(t) ){
                    cave.map[x][y] -> add( new Mushroom() );
                }
                else if ( dynamic_cast<Rock*>(t) ){
                    cave.map[x][y] -> add( new Rock() );
                }
        }
    }
    }
    cave.tom = new Tom();
    cave.tom ->setLocation(this, c.tom->getX(), c.tom->getY());
    return cave;
}

//Ensure the usercommand and do what the user want to do
void Cave::command (string userCommand)
{
    if (Move().triggersOn(userCommand))
        Move().fire(*this, userCommand);
    else if (Place().triggersOn(userCommand))
        Place().fire(*this, userCommand);
    else if (Throw().triggersOn(userCommand))
        Throw().fire(*this,userCommand);
    else if (Explode().triggersOn(userCommand))
        Explode().fire(*this,userCommand);
    else
        cerr << "tom doesn't know how to "+userCommand << endl;;
}

//Display the cave map now
void Cave::show()
{
    vector<Thing*>* thingsWithTom = map[tom -> getX()][tom -> getY()] -> getThings();

    for (int y = 0; y < height; y++)
    { // for all rows
        for (int x = 0; x < width; x++) // for all columns
            cout << map[x][y] -> show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size())
            cout << (*thingsWithTom)[y] -> getName();

        cout << endl;
    }

    cout << endl;
}
