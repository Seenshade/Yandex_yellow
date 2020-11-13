#pragma once

#include <map>
#include <vector>
#include <string>

struct BusesForStopResponse {
	BusesForStopResponse() {};
	BusesForStopResponse(const std::vector<std::string>& buses);
	std::vector<std::string> bus_list;
};
std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	StopsForBusResponse(){};
	StopsForBusResponse(const std::vector<std::pair<std::string, std::vector<std::string>>>& buses_for_stops);
	std::vector<std::pair<std::string, std::vector<std::string>>> buses_for_stops_list;
};
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	AllBusesResponse(){};
	AllBusesResponse(const std::map<std::string, std::vector<std::string>>& buses_and_stops);
	std::map<std::string, std::vector<std::string>> bus_and_stops_list;
};
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);