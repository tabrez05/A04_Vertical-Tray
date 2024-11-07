#ifndef EGG_H
#define EGG_H

#include <iostream>
#include <string>

class Egg 

{ 
    public:
    Egg();
    Egg(float eggWeight);
    bool operator==(const Egg& check_match) const;
    bool operator<(const Egg& check_less_than) const;
    char getType() const;
    friend std::ostream& operator<<(std::ostream& outputOperator, const Egg& egg);

private:

    float egg_size;                
    char egg_type;     
    char checkEggType(float egg_size) const;

};
#endif
