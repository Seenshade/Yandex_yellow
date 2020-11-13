#include <exception>
#include <iostream>
#include <sstream>
#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number){
    stringstream ss(international_number);
    char plus_symbol, first_separator, second_separator;
    int country_code, city_code;
    string local_number;
    ss >> plus_symbol >> country_code >> first_separator >> city_code >> second_separator >> local_number;
    if (plus_symbol != '+'){
        throw invalid_argument("Wrong number");
    }
    if (ss.fail()){
        throw invalid_argument("Wrong number");
    }
    country_code_ = to_string(country_code);
    city_code_ = to_string(city_code);
    local_number_ = local_number;
}

string PhoneNumber::GetCountryCode() const{
    return country_code_;
}
string PhoneNumber::GetCityCode() const{
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
    return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}