#include "factory_utils.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "Conveyor.h"
#include "Tray.h"
#include "Egg.h"

void load_conveyors(std::vector<Conveyor*>& assembly_line)
{
 Tray* current_tray = nullptr;
 Conveyor* current_conveyor = nullptr;
 std::string line;
 while (getline(std::cin, line)) 
 {
//    if (line.empty()) continue;
  switch (line[0])
  {
    case 'C':
        current_conveyor=new Conveyor();
        assembly_line.push_back(current_conveyor);
        break;
    case 'T':
        if(current_conveyor !=nullptr)
        {
          current_tray=new Tray();
          current_conveyor->attach_back(current_tray);
        }
        break;
        default:{
        if(current_tray!=nullptr)
        {
            float weight=std::stof(line);  
            Egg new_egg(weight);  
            current_tray->place_back(new_egg);   
        }
        break;
        }
   }
 }
}

std::string basic_report(const std::vector<Conveyor*>& assembly_line)
{
  std::ostringstream report;
  for (size_t i = 0;i<assembly_line.size(); ++i)
  {
    
    report<<*(assembly_line[i]); 
    report<<"\n";
    report<<"\n"; 
  }
  return report.str();
}

std::string vertical_report(const std::vector<Conveyor*>& assembly_line)
{
  std::vector<std::string> string_conveyors;
  for (Conveyor* current : assembly_line)
  {
    std::ostringstream oss;
    oss<<*current; 
    string_conveyors.push_back(oss.str());
  }
  size_t max_lines=0;
  std::vector<std::vector<std::string>> lines;
  for (const std::string& conveyor_str :string_conveyors)
  {
    std::istringstream iss(conveyor_str);
    std::vector<std::string>conveyor_lines;
    std::string line;
    while (getline(iss, line))
    {
        conveyor_lines.push_back(line);
    }
    max_lines = std::max(max_lines,conveyor_lines.size());
    lines.push_back(conveyor_lines);
    }
    std::ostringstream report;
    for (size_t i=0; i<max_lines;++i)
    {
    for (size_t j=0; j<lines.size();++j)
    {
      if (i < lines[j].size())
        report<<lines[j][i];
      else
        report << std::string(lines[j][0].size(),' '); 
      if (j<lines.size()-1)
          report << "  ";
    }
    report << "  ";
    report<<"\n";
    }
    return report.str();
}