#ifndef CONVEYOR_H
#define CONVEYOR_H
#include <iostream>
#include "Tray.h"  
class Conveyor
{
public:
Conveyor();
~Conveyor();
void attach_front(Tray* tray_ptr);
void attach_back(Tray* tray_ptr);
void remove(const Tray& trays_like_me);
friend std::ostream& operator<<(std::ostream& os, const Conveyor& conveyor);

private:
struct Harness
{
  Harness(Tray* t, Harness* nxt = nullptr);
  ~Harness();
  Tray* payload;
  Harness* next;
};
  friend std::ostream operator<<(std::ostream& os,const Harness& harness);
  Harness* head;
  Harness* tail;
};
#endif
