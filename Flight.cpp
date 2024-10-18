#include "Flight.h"

Flight::Flight() {}

Flight::Flight(string source, string target, string airline) {
    this->source = source;
    this->airline=airline;
    this->target = target;
}

string Flight::getAirline() {
    return airline;
}

string Flight::getSource() {
    return source;
}

string Flight::getTarget() {
    return target;
}

bool Flight::operator<(const Flight &other) const {
    return source < other.source;
}

