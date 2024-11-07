#include "Conveyor.h"
Conveyor::Conveyor() :head(nullptr),tail(nullptr){}
Conveyor::~Conveyor()
{
  while (head!=nullptr)
  {
    Harness* temp=head;
    head = head->next;
//    delete temp->payload; 
    delete temp;         
  }
}
Conveyor::Harness::Harness(Tray* t, Harness* nxt):payload(t),next(nxt) {}
Conveyor::Harness::~Harness()
{
  delete payload; 
}
void Conveyor::attach_front(Tray* t) 
{
  Harness* newHarness=new Harness(t, head);
  head=newHarness;
  if(tail==nullptr)
  {
    tail=newHarness;
  }
}

void Conveyor::attach_back(Tray* t) 
{
  Harness* newHarness=new Harness(t,nullptr);
  if(head==nullptr)
  {
    head=tail=newHarness;
  }
  else
  {
    tail->next=newHarness;
    tail=newHarness;
  }
}

void Conveyor::remove(const Tray& trays_like_me){
  Conveyor::Harness anchor(nullptr, head);
  Harness* current_suspect = &anchor;
  while(current_suspect->next != nullptr){
    if (*current_suspect->next->payload == trays_like_me)
    {
      Harness* harness_to_delete = current_suspect->next;
      current_suspect->next = current_suspect->next->next;
      delete harness_to_delete; 
    }
    else
    {
     current_suspect = current_suspect->next; 
    }
    }
    head = anchor.next;  
    if (head == nullptr)
    {
      tail = nullptr;
    }
    else
    {
      tail = current_suspect;
    }
}



std::ostream& operator<<(std::ostream& os, const Conveyor& rhs)
{
  os <<"  |  \n";
  Conveyor::Harness* current=rhs.head;
  while (current!=nullptr)
  {
    os <<" / \\ \n";
    os <<"/   \\\n";
    os <<*(current->payload);
    os <<"\\   /\n";
    os <<" \\ / \n";
    bool isLast=(current->next == nullptr);
    os << (isLast ? "  S  \n" : "  $  \n");
    current = current->next; 
  }

  return os;
}
