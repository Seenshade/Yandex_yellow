#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	q.bus.clear();
	q.stop.clear();
	q.stops.clear();
	string str_operation;
	is >> str_operation;
	if (str_operation == "NEW_BUS"){
		int stop_count;
		q.type = QueryType::NewBus;
		is >> q.bus >> stop_count;
		for (int i = 0; i < stop_count; ++i){
			string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
	} else if (str_operation == "BUSES_FOR_STOP"){
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (str_operation == "STOPS_FOR_BUS"){
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (str_operation == "ALL_BUSES"){
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	BusesForStopResponse() {};
	BusesForStopResponse(const vector<string>& buses){
		bus_list = buses;
	}
	vector<string> bus_list;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
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

struct StopsForBusResponse {
	StopsForBusResponse(){};
	StopsForBusResponse(const vector<pair<string, vector<string>>>& buses_for_stops){
		buses_for_stops_list = buses_for_stops;
	}
	vector<pair<string, vector<string>>> buses_for_stops_list;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
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
				os << endl;
			}
		}
	}
	return os;
}

struct AllBusesResponse {
	AllBusesResponse(){};
	AllBusesResponse(const map<string, vector<string>>& buses_and_stops){
		bus_and_stops_list = buses_and_stops;
	}
	map<string, vector<string>> bus_and_stops_list;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
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
				os << endl;
			}
		}
	}
	return os;
}

class BusManager {
private:
	map<string, vector<string>> stops_for_bus, buses_for_stop;
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		stops_for_bus[bus] = stops;
		for (const auto& stop : stops){
			buses_for_stop[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		if (buses_for_stop.count(stop) == 0){
			return {};
		}
		return buses_for_stop.at(stop);
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		if (stops_for_bus.count(bus) == 0){
			return {};
		}
		vector<pair<string, vector<string>>> list;
		for (const auto& stop : stops_for_bus.at(bus)){
			vector<string> buses_list;
			for (const auto& bus_from_list : buses_for_stop.at(stop)){
				if (bus_from_list != bus)
				buses_list.push_back(bus_from_list);
			}
			list.push_back(make_pair(stop, buses_list));
		}
		return list;
	}

	AllBusesResponse GetAllBuses() const {
		return stops_for_bus;
	}
};



int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}