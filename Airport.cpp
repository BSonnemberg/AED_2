#include "Airport.h"

Airport::Airport() {}

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code=code;
    this->name=name;
    this->city=city;
    this->country=country;
    this->latitude=latitude;
    this->longitude=longitude;
}

string Airport:: getCode(){return code;}
string Airport:: getName() const{return name;}
string Airport:: getCity(){return city;}
string Airport:: getCountry(){return country;}
double Airport:: getLatitude(){return latitude;}
double Airport:: getLongitude(){return longitude;}


bool Airport::operator==(const Airport &other) const {
    return this->code == other.code;
}
