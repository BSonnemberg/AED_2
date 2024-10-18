#ifndef PROJETO2_AED_FLIGHT_H
#define PROJETO2_AED_FLIGHT_H

#include <string>
using namespace std;
/**
 * @file Flight.h
 * @brief Flight class definition.
 */

/**
 * @brief Class that represents a flight between two airports by an airline.
 */
class Flight {
private:
    string source,target,airline;
public:
    /**
     * @brief Default constructor for the Flight class.
     * @details This default constructor is required for creating parameterless Flight objects.
     * @complexity O(1)
     */
    Flight();
    /**
     * @brief Constructor for the Flight class.
     * @param source Flight origin airport.
     * @param target Flight destination airport.
     * @param airline Flight airline.
     * @details This constructor initializes the class members with the given values.
     * @complexity O(1)
     */
    Flight(string source, string target, string airline);

    /**
     * @brief Gets the flight's origin airport.
     * @return The flight's origin airport.
     * @complexity O(1)
     */
    string getSource();
    /**
     * @brief Gets the flight destination airport.
     * @return The flight destination airport.
     * @complexity O(1)
     */
    string getTarget();
    /**
     * @brief Gets the airline for the flight.
     * @return The airline for the flight.
     * @complexity O(1)
     */
    string getAirline();
    /**
     * @brief Less comparison operator overhead than for the Flight class.
     * @param other Another Flight object to compare.
     * @return true if this flight's origin airport is smaller than the other flight's origin airport, false otherwise.
     * @complexity O(1)
     */
    bool operator<(const Flight &other) const;
};


#endif //PROJETO2_AED_FLIGHT_H
