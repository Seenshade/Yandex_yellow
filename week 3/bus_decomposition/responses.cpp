#include "responses.h"

#include <iostream>

BusesForStopResponse::BusesForStopResponse(const std::vector<std::string>& buses){
	bus_list = buses;
}

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
	if (r.bus_list.empty()){
		os << "No stop";
	} else {
		int bus_iterator = 0;
		for (const auto& bus : r.bus_list){
			bus_iterator++;
			os << bus;
			if (bus_iterator != r.bus_list.size()){
				os << " ";
			}
		}
	}
	return os;
}

StopsForBusResponse::StopsForBusResponse(const std::vector<std::pair<std::string, std::vector<std::string>>>& buses_for_stops){
	buses_for_stops_list = buses_for_stops;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
	if (r.buses_for_stops_list.empty()){
		os << "No bus";
	} else {
		int stop_iterator = 0;
		for(const auto& [stop, buses] : r.buses_for_stops_list){
			stop_iterator++;
			os << "Stop " << stop << ": "; 
			if (buses.empty()){
				os << "no interchange";
			} else {
				int bus_iterator = 0;
				for (const auto& bus : buses){
					bus_iterator++;
					os << bus;
					if (bus_iterator != buses.size()){
						os << " ";
					}
				}
			}
			if (stop_iterator != r.buses_for_stops_list.size()){
				os << std::endl;
			}
		}
	}
	return os;
}

AllBusesResponse::AllBusesResponse(const std::map<std::string, std::vector<std::string>>& buses_and_stops){
	bus_and_stops_list = buses_and_stops;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
	if (r.bus_and_stops_list.empty()){
		os << "No buses";
	} else {
		int bus_iterator = 0;
		for (const auto& [bus, stops] : r.bus_and_stops_list){
			bus_iterator++;
			os << "Bus " << bus << ": ";
			int stop_iterator = 0;
			for(const auto& stop : stops){
				stop_iterator++;
				os << stop;
				if (stop_iterator != stops.size()){
					os << " ";
				}
			}
			if (bus_iterator != r.bus_and_stops_list.size()){
				os << std::endl;
			}
		}
	}
	return os;
}