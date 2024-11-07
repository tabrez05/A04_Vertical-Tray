#include "Egg.h"

Egg::Egg():egg_size(0.0f), egg_type ('E') {}
Egg::Egg (float eggWeight ):egg_size(eggWeight),egg_type(checkEggType(eggWeight))
{

}

char Egg::checkEggType(float size_of_egg) const {
    if (size_of_egg < 1.25f || size_of_egg >3.00f) {
        return 'E';
    } 
    else if (size_of_egg >= 1.25f&&size_of_egg< 1.50f) {
        return '.';
    } 

    else if (size_of_egg >= 1.50f && size_of_egg <1.75f) 
    {
        return '*';

    } 
    
    else if (size_of_egg>= 1.75f&&size_of_egg< 2.00f) {

        return 'o';
    }
    else if (size_of_egg>= 2.00f &&size_of_egg< 2.25f) 
    {  return 'O';} 
    else if (size_of_egg>= 2.25f &&size_of_egg< 2.50f) 
    { return '0';}
     else if (size_of_egg>= 2.50f &&size_of_egg<= 3.00f) 
     { return '@';}


    return 'E';  

}

bool Egg::operator==(const Egg& check_match) const {
    return egg_type == check_match.egg_type;
}

bool Egg::operator<(const Egg& check_less_than) const{
    return egg_size<check_less_than.egg_size;
}
char Egg::getType() const {
    return egg_type;
}

std::ostream& operator<<(std::ostream& os, const Egg& rhs) {
    os << rhs.egg_type;
    return os;
}
