#include "Tray.h"
using namespace std;
Tray::Tray():current_eggs_count(0),trayCapacity(2) {
    carton = new Egg[trayCapacity];
}

Tray::~Tray(){
    delete[] carton;
}

void Tray::place_back(const Egg& egg){
    if (current_eggs_count==trayCapacity){
        trayCapacity +=2;
        Egg* new_carton =new Egg[trayCapacity];
        for(int i=0; i<current_eggs_count;++i)
        {
            new_carton[i]=carton[i];
        }
        delete[] carton;
        carton =new_carton;
    }
    carton[current_eggs_count++]=egg;
}
bool Tray::take_back(Egg& e)
{
  if (current_eggs_count>0)
  {
    e=carton[current_eggs_count -1];
    current_eggs_count--;
    return true; 
  }
  return false; 
}
int Tray::getEggTypeIndex(char type) const {
    switch(type){
        case 'E': return E;
        case '.': return PEEWEE;
        case '*': return SMALL;
        case 'o': return MEDIUM;
        case 'O': return LARGE;
        case '0': return XLARGE;
        case '@': return JUMBO;
        default: return -1;
    }
}

bool Tray::operator==(const Tray& rhs) const
{   
 if (this->trayCapacity!=rhs.trayCapacity ||this->current_eggs_count!=rhs.current_eggs_count)
  {
    return false;
  }
  if (this->current_eggs_count==0) return true;
  int lhsTrayCounts[NUM_EGG_TYPES]={0};
  int rhsTrayCounts[NUM_EGG_TYPES]={0};
  for(int i=0;i<this->current_eggs_count;++i)
  {
    int lhsEggTypeCount=this->getEggTypeIndex(this->carton[i].getType());
    if(lhsEggTypeCount>=0 && lhsEggTypeCount<NUM_EGG_TYPES)
    {
     lhsTrayCounts[lhsEggTypeCount]++;
    }
  }
  for(int i = 0; i < rhs.current_eggs_count;++i)
  {
    int rhsEggTypeCount = rhs.getEggTypeIndex(rhs.carton[i].getType());
    if(rhsEggTypeCount >=0 && rhsEggTypeCount<NUM_EGG_TYPES)
    {
      rhsTrayCounts[rhsEggTypeCount]++;
    }
  }
  for(int i=0;i<NUM_EGG_TYPES; ++i)
  {
    if(lhsTrayCounts[i]!=rhsTrayCounts[i]) return false;
  }
    return true;
}

ostream& operator<<(ostream& os, const Tray& rhs)
{
  os << "+---+" <<endl;
  if(rhs.current_eggs_count==0)
  {
    os << "| | |" <<endl;
  }
  else
  {
    int eggsPerRow = 2;
    int totalRows =(rhs.current_eggs_count+eggsPerRow - 1)/eggsPerRow;
    for (int row=0; row<totalRows;++row)
    {
      for(int col=0;col<eggsPerRow; ++col)
      {
        int trayPosition=row*eggsPerRow+col;
          if(trayPosition<rhs.current_eggs_count)
          {
            os<<"|"<<rhs.carton[trayPosition];
          }
          else
          {
            os << "| ";
          }
      }
      os << "|" << endl;
      if(row < totalRows - 1)
      {
        os << "|-+-|" << endl;
      }
    }
  }
  os << "+---+" << endl;
  return os;
}























// #include "Tray.h"
// using namespace std;
// Tray:: Tray():current_eggs_count(0), trayCapacity(2){
//   carton=new Egg [trayCapacity];
// }
// Tray :: ~Tray ()
// {
//   delete[]carton;
// }
// void Tray::place_back(const Egg& egg){
//   if (current_eggs_count==trayCapacity){
//     trayCapacity +=2;
//     Egg* new_carton=new Egg[trayCapacity];
//     for(int i=0;i<current_eggs_count;++i)
//     {
//       new_carton[i]=carton[i];
//     }
//     delete[]carton;
//     carton=new_carton;
//   }
//   carton[current_eggs_count++]=egg;
// }
// enum EggTypeIndex { 
//     E = 0,PEEWEE,SMALL,MEDIUM,LARGE,XLARGE,XXLARGE,JUMBO,NUM_EGG_TYPES
// };
// int getEggTypeIndex(char type) {
//   switch(type){
//     case 'E':return E;case '.':return PEEWEE;case '*':return SMALL;case 'o':return MEDIUM;
//     case 'O':return LARGE;case '0':return XLARGE;case '@':return JUMBO;
//     default: return -1;
//     }
// }
// bool operator==(const Tray& lhs, const Tray& rhs) {
//   if (lhs.trayCapacity!=rhs.trayCapacity || lhs.current_eggs_count!=rhs.current_eggs_count){
//     return false;
//     }
//     if (lhs.current_eggs_count == 0) {
//         return true;
//     }
//     int lhsTrayCounts[NUM_EGG_TYPES]={0};
//     int rhsTrayCounts[NUM_EGG_TYPES] = {0};
//     for(int i=0; i<lhs.current_eggs_count;++i) {
//         int lhsEggTypeCount =getEggTypeIndex(lhs.carton[i].getType());
//         if(lhsEggTypeCount>=0 && lhsEggTypeCount<NUM_EGG_TYPES) {
//             lhsTrayCounts[lhsEggTypeCount]++;
//         }
//     }
//     for(int i=0;i<rhs.current_eggs_count;++i)
//     {
//       int rhsEggTypeCount=getEggTypeIndex(rhs.carton[i].getType());
//       if(rhsEggTypeCount>=0 && rhsEggTypeCount<NUM_EGG_TYPES)
//       {
//           rhsTrayCounts[rhsEggTypeCount]++;
//       }
//     }
//     for(int i=0;i<NUM_EGG_TYPES;++i) {
//         if(lhsTrayCounts[i]!=rhsTrayCounts[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// ostream& operator<<(ostream& os, const Tray& rhs) {
//   os<<"+---+"<<endl;
//   if(rhs.current_eggs_count==0)
//   {
//     os<<"| | |"<<endl;
//   }
//   else{
//     int eggsPerRow=2;
//     int totalRows=(rhs.current_eggs_count+eggsPerRow-1)/eggsPerRow;

//     for (int row=0; row<totalRows; ++row)
//     {
//       for(int col =0; col<eggsPerRow;++col)
//       {
//         int trayPosition=row*eggsPerRow +col;
//         if(trayPosition<rhs.current_eggs_count)
//         {
//           os<<"|"<<rhs.carton[trayPosition];
//           }
//         else{
//           os<<"| ";}
//       }
//       os<<"|"<<endl;
//       if(row<totalRows-1)
//       {
//         os<<"|-+-|"<<endl;
//       }
//     }
//   }
//   os<<"+---+"<<endl;
//   return os;
// }
