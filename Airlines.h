#ifndef PROJETO2_AED_AIRLINES_H
#define PROJETO2_AED_AIRLINES_H
using namespace std;
#include <string>


class Airlines {
private:
    string code, name,country, callsign;

public:
    string getCode();
    string getName();
    string getCountry();
    string getCallsign();



};


#endif //PROJETO2_AED_AIRLINES_H
