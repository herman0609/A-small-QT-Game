#include "place.h"
#include "thing.h"

//Throw things in the direction near tom
//It can be the north south east or west
void Throw::fire(Cave& c, string userCommand) {

    string s = tail(userCommand);

    Location* loc = c.getMap()[c.getTom()->getX()][(c.getTom()->getY())];

    if (s[5] == 'w' || s[9] == 'w'){
        loc = c.getMap()[((c.getTom()->getX())-1)][c.getTom()->getY()];
        if(c.getTom()->getX()-1!=0){
            if (s[0] == 'c'){
                loc -> add(new Coin());}
            else if (s[0] == 'm'){
                loc -> add(new Mushroom());}
            else
                cerr << "I can not throw a " << userCommand << endl;
        }
        else
            cerr << "I can not throw a " << userCommand << endl;
}
    else if  (s[5] == 'n' || s[9] == 'n'){
        loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()-1];
        if(c.getTom()->getY()-1!=0){
            if (s[0] == 'c'){
                loc -> add(new Coin());}
            else if (s[0] == 'm'){
                loc -> add(new Mushroom());}
            else
                cerr << "I can not throw a " << userCommand << endl;
        }
        else
            cerr << "I can not throw a " << userCommand << endl;
    }
    else if (s[5]=='e' || s[9] == 'e'){
        loc = c.getMap()[c.getTom()->getX()+1][c.getTom()->getY()];
        if(c.getTom()->getX()+1!=c.getWidth()-1){
            if (s[0] == 'c'){
                loc -> add(new Coin());}
            else if (s[0] == 'm'){
                loc -> add(new Mushroom());}
            else
                cerr << "I can not throw a " << userCommand << endl;
        }
        else
            cerr << "I can not throw a " << userCommand << endl;
    }
    else if (s[5]=='s' || s[9] == 's'){
        loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()+1];
        if(c.getTom()->getY()+1!=c.getHeight()-1){
            if (s[0] == 'c'){
                loc -> add(new Coin());}
            else if (s[0] == 'm'){
                loc -> add(new Mushroom());}
            else
                cerr << "I can not throw a " << userCommand << endl;
        }
        else
            cerr << "I can not throw a " << userCommand << endl;
    }
    else
        cerr << "I can not throw a " << userCommand << endl;

}
