#include "Read.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Graph.h"
#include "Flight.h"
using namespace std;

void Read::readAirports() {

    string Code,Name,City,Country;
    double Latitude,Longitude;
    string dir = "../dataset/airports.csv", line;
    ifstream ifile(dir);
    char sep = ',';
    getline(ifile,line);
    while (getline(ifile, line)){
        stringstream iss(line);
        getline(iss,Code,sep);
        getline(iss,Name,sep);
        getline(iss,City,sep);
        getline(iss, Country, sep);
        iss>>Latitude>>sep;
        iss>>Longitude>>sep;
        Airport airport = Airport(Code,Name,City, Country, Latitude,Longitude);
        airportMap.emplace(Code,airport);
        flights.addVertex(airport);
    }
}

void Read::readAirlines() {
    string Code,Name,Callsign,Country;
    string dir = "../dataset/airlines.csv", line;
    ifstream ifile(dir);
    char sep =',';
    getline(ifile,line);
    while (getline(ifile, line)){
        stringstream  iss(line);
        getline(iss,Code,sep);
        getline(iss,Name,sep);
        getline(iss,Callsign,sep);
        getline(iss,Country,sep);
        Airline airline = Airline(Code,Name,Callsign,Country);
        airlineMap.emplace(Code,airline);

    }

}

void Read::readFlights() {

    string Source,Target,airline;
    string dir = "../dataset/flights.csv", line;
    ifstream ifile(dir);
    char sep = ',';
    getline (ifile, line);

    while (getline(ifile, line)) {
        stringstream iss(line);
        getline(iss, Source, sep);
        getline(iss, Target, sep);
        getline(iss, airline, sep);

        flightSet.emplace(Source,Target,airline);

        flights.addEdge(airportMap.at(Source), airportMap.at(Target),airlineMap.at(airline) );

    }
}

unordered_map<string,Airline> Read::getAirlineMap() {
    return airlineMap;
}

unordered_map<string, Airport> Read::getAirportMap() {
    return airportMap;
}

set<Flight> Read::getFlightSet() {
    return flightSet;
}
Graph Read::getFlights() {
    return flights;
}


