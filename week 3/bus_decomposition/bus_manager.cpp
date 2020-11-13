#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    stops_for_bus[bus] = stops;
    for (const auto& stop : stops){
        buses_for_stop[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
    if (buses_for_stop.count(stop) == 0){
        return {};
    }
    return buses_for_stop.at(stop);
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
		if (stops_for_bus.count(bus) == 0){
			return {};
		}
		std::vector<std::pair<std::string, std::vector<std::string>>> list;
		for (const auto& stop : stops_for_bus.at(bus)){
			std::vector<std::string> buses_list;
			for (const auto& bus_from_list : buses_for_stop.at(stop)){
				if (bus_from_list != bus)
				buses_list.push_back(bus_from_list);
			}
			list.push_back(make_pair(stop, buses_list));
		}
		return list;
	}

AllBusesResponse BusManager::GetAllBuses() const {
    return stops_for_bus;
}