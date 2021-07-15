#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

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
  string request;
  is >> request;
  if(request == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int n;
    is >> n;
    string stop;
    vector<string> stops;
    for(int i = 0; i < n; ++i) {
      is >> stop;
      stops.push_back(stop);
    }
    q.stops = stops;
    return is;
  } else if(request == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
    return is;
  } else if(request == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
    return is;
  } else {
    q.type = QueryType::AllBuses;
    return is;
  }
}

struct BusesForStopResponse {
    bool exist;
    string stop;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if(!r.exist) {
        os << "No stop";
        return os;
    }
    bool first = true;
    for(const auto& bus : r.stops_to_buses.at(r.stop)) {
        if(!first) {
            os << " ";
        }
        first = false;
        os << bus;
    }
    return os;
}

struct StopsForBusResponse {
    bool exist;
    string bus;
    map<string, vector<string>> stops_to_buses;
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if(!r.exist) {
      os << "No bus";
      return os;
    }
    for(const auto& stop : r.buses_to_stops.at(r.bus)) {
      os << "Stop " << stop << ":";
      if(r.stops_to_buses.at(stop).size() == 1) {
        os << " no interchange";
      } else {
        for(const auto& bus : r.stops_to_buses.at(stop)) {
          if(bus != r.bus) {
            os << " " << bus;
          }
        }
      }
      os << endl;
    }
    return os;
}

struct AllBusesResponse {
  bool exist = false;
  map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if(!r.exist) {
    os << "No buses";
    return os;
  }
  for(const auto& bus : r.buses) {
    os << "Bus " << bus.first << ":";
    for(const auto& stop : bus.second) {
      os << " " << stop;
    }
    os << endl;
  }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for(const auto& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    BusesForStopResponse response;
    response.exist = stops_to_buses.find(stop) != stops_to_buses.end();
    response.stop = stop;
    response.stops_to_buses = stops_to_buses;
    return response;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse response;
    response.exist = buses_to_stops.find(bus) != buses_to_stops.end();
    response.bus = bus;
    response.buses_to_stops = buses_to_stops;
    response.stops_to_buses = stops_to_buses;
    return response;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse response;
    if(buses_to_stops.empty()) {
      response.exist = false;
    } else {
      response.exist = true;
    }
    response.buses = buses_to_stops;
    return response;
  }
private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

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
