#include "Airline.h"


Airline::Airline(string code, string name, string callsign, string country) {
    this->code=code;
    this->name=name;
    this->country=country;
    this->callsign=callsign;
}

string Airline:: getCode(){return code;}
string Airline:: getName(){return name;}
string Airline::  getCallsign(){return callsign;}
string Airline:: getCountry(){return country;}
Airline::Airline() {}
