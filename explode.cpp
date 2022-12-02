#include "place.h"
#include "thing.h"

//A chain explode of the bomb
//All adjacent bombs (to the north, south, east, and west) also explode in the chain reaction -
//this continues until no more bombs are adjacent.
//An exploding bomb destroys all objects (including Rocks, but not including Tom) in the same Location.
void Explode::chain(Cave& c,int X, int Y)
{
    if(X<-1 || Y<-1 || Y>c.getHeight()|| X>c.getWidth() ){
        return;
    }
    Location*** map = c.getMap();
    vector<Thing*>* thing = map[X][Y] -> getThings();
    int num = (int)thing->size();
    int sh = 0;
    for(int i=0; i<num; i++){
        if((*thing)[i]->getName()=="bomb"){
            for(int j=0; j<num; j++){
                if((*thing)[sh]->getName()!="tom"){
                    map[X][Y]->remove((*thing)[sh]);}
                else
                    sh = 1;
            }
        }
    }
    if(Y>0){
        vector<Thing*>* north = map[X][Y-1] -> getThings();
        int northnum = (int)north->size();
        for(int i=0; i<northnum; i++){
            if((*north)[i]->getName()=="bomb"){
                chain(c, X, Y-1);
            }
        }
    }
    if(X<c.getWidth()-1){
        vector<Thing*>* east = map[X+1][Y] -> getThings();
        int eastnum = (int)east->size();
        for(int i=0; i<eastnum; i++){
            if((*east)[i]->getName()=="bomb"){
                chain(c, X+1, Y);
            }
        }
    }
    if(Y<c.getHeight()-1){
        vector<Thing*>* south = map[X][Y+1] -> getThings();
        int southnum = (int)south->size();
        for(int i=0; i<southnum; i++){
            if((*south)[i]->getName()=="bomb"){
                chain(c, X, Y+1);
            }
        }
    }
    if(X>0){
        vector<Thing*>* west = map[X-1][Y] -> getThings();
        int westnum = (int)west->size();
        for(int i=0; i<westnum; i++){
            if((*west)[i]->getName()=="bomb"){
                chain(c, X-1, Y);
            }
        }
    }
}

//If x,y is a bomb and the command is to make it explode
//Then it will cause chain explode
void Explode::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);
    int X = c.getTom() -> getX();
    int Y = c.getTom() -> getY();
    chain(c, X, Y);
}
