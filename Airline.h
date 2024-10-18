#ifndef PROJETO2_AED_AIRLINE_H
#define PROJETO2_AED_AIRLINE_H
#include <iostream>
#include <string>
using namespace std;

/**
 * @file Airline.h
 * @brief Airline class statement.
 */

/**
 * @class Airline
 * @brief Represents an airline.
 */
class Airline {
private:
    string code, name,country, callsign;

public:
    /**
     * @brief Constructor of the Airline class.
     * @param code Airline code.
     * @param name Airline name.
     * @param callsign Airline callsign.
     * @param country Airline country.
     * @details This constructor initializes the class members with the given values.
     * @complexity O(1)
     */
    Airline(string code, string name, string callsign, string country);
    /**
     * @brief Airline class standard constructor.
     * @details This default constructor is required for creating parameterless Airline objects.
     * @complexity O(1)
     */
    Airline();
    /**
     * @brief Gets the airline code.
     * @return The airline code.
     * @complexity O(1)
     */
    string getCode();

    /**
     * @brief Get the name of the airline.
     * @return The name of the airline.
     * @complexity O(1)
     */
    string getName();

    /**
     * @brief Gets the country of the airline.
     * @return The country of the airline.
     * @complexity O(1)
     */
    string getCountry();

    /**
     * @brief Gets the airline's callsign.
     * @return The airline's callsign.
     * @complexity O(1)
     */
    string getCallsign();
};


#endif //PROJETO2_AED_AIRLINE_H
