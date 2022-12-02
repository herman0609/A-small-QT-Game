#ifndef LOCATION_H
#define LOCATION_H


#include <vector>

#include "thing.h"

// The location class that contaions add remove show things in this location
class Location
{
public:
    Location()
    {
        ++count;
    }
    ~Location()
    {
        for (auto t : things)
            delete(t);
        --count;
    }
    void add(Thing *t);
    void remove(Thing *t);
    char show();
    bool isBlocking();
    vector<Thing*>* getThings() { return &things; }
    static int count; // a count of the number of locations allocated/deleted

private:

    vector<Thing*> things;

};



#endif // LOCATION_H
