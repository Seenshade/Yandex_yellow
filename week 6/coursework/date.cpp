#include "date.h"

Date::Date(std::string year, std::string month, std::string day)
  : year_(year)
  , month_(month)
  , day_(day)
  {};

std::string Date::Year() const {
  return year_;
}

std::string Date::Month() const {
  return month_;
}

std::string Date::Day() const {
  return day_;
}