#ifndef PROJETO2_AED_AIRPORTS_H
#define PROJETO2_AED_AIRPORTS_H
using namespace std;
#include <string>


class Airports {
private:
    string code,name,city,country,latitude,longitude;

public:
    string getCode();
    string getName();
    string getCity();
    string getCountry();
    string getLatitude();
    string getLongitude();

};


#endif //PROJETO2_AED_AIRPORTS_H
