#pragma once   

#include <string>

class Date{
public:
  Date(std::string year, std::string month, std::string day);
  std::string Year() const;
  std::string Month() const;
  std::string Day() const;
private:
  const std::string year_;
  const std::string month_;
  const std::string day_;
};