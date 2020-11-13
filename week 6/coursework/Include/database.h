#pragma once

#include "date.h"

#include <map>
#include <vector>
#include <string>
#include <set>

class Database{
public:
  void Add(){};
  std::string PrintDatabase() const {};
  std::string FindIf() const {};
  void RemoveIf(){};
  std::string Last() const {};
private:
  std::map<Date, std::vector<std::string>> events_by_date;
  std::map<Date, std::set<std::string>> unique_events_by_date;
};
