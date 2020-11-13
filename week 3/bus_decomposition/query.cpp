#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	q.bus.clear();
	q.stop.clear();
	q.stops.clear();
	std::string str_operation;
	is >> str_operation;
	if (str_operation == "NEW_BUS"){
		int stop_count;
		q.type = QueryType::NewBus;
		is >> q.bus >> stop_count;
		for (int i = 0; i < stop_count; ++i){
			std::string stop;
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