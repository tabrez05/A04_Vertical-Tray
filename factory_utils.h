#ifndef FACTORY_UTILS_H
#define FACTORY_UTILS_H
#include <vector>
#include "Conveyor.h"
#include<string>
class Conveyor;
class Tray; 
void load_conveyors(std::vector<Conveyor*>& assembly_line);
std::string basic_report(const std::vector<Conveyor*>& assembly_line);
std::string vertical_report(const std::vector<Conveyor*>& assembly_line);
#endif 
