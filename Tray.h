#ifndef TRAY_H
#define TRAY_H

#include "Egg.h"
#include <iostream>

using namespace std;

enum EggTypeIndex { 
    E = 0, PEEWEE, SMALL, MEDIUM, LARGE, XLARGE, XXLARGE, JUMBO, NUM_EGG_TYPES
};

class Tray 
{
private:
    Egg* carton; 
    int current_eggs_count; 
    int trayCapacity;
public:
    Tray(); 
    ~Tray();
    void place_back(const Egg& egg);
    bool take_back(Egg& egg); 
    bool operator==(const Tray& rhs) const;
    int getEggTypeIndex(char type) const;
    friend ostream& operator<<(ostream& os, const Tray& rhs);
};

#endif 







// #ifndef TRAY_H
// #define TRAY_H

// #include "Egg.h"
// #include <iostream>


// using namespace std;
// class Tray 
// {

// private:

//     Egg* carton; 
//     int current_eggs_count; 
//     int trayCapacity;

// public:

//     Tray(); 
//     ~Tray();

//    void place_back(const Egg& egg); 
//    friend ostream& operator<<(ostream& os, const Tray& rhs);
//    friend bool operator==(const Tray& lhs, const Tray& rhs);

// };

// #endif 






