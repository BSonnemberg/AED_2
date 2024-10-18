/**
 * @file Read.h
 * @brief Definition of the Read class responsible for reading data from the system.
 */
#ifndef PROJETO2_AED_READ_H
#define PROJETO2_AED_READ_H


#include <vector>
#include "Airport.h"
#include "Graph.h"
#include <map>
#include <memory>
#include "Flight.h"
/**
 * @class Read
 * @brief Class responsible for reading data from the system.
 */
class Read {

private:
    Graph flights; /**< Graph containing information about flights. */
    unordered_map<string, Airport> airportMap; /**< Map containing information about airports. */
    unordered_map<string, Airline> airlineMap; /**< Map containing information about airlines. */
    set<Flight> flightSet; /**< Set containing information about flights. */

public:
    /**
     * @brief Read airline data from CSV file.
     * @note Complexity: O(C), where C is the number of airlines in the file.
     */
    void readAirlines();
    /**
     * @brief Reads airport data from the CSV file and adds it to the graph.
     * @note Complexity: O(V), where V is the number of vertices (airports) in the graph.
     */
    void readAirports();
    /**
     * @brief Reads flight data from the CSV file and adds it to the graph.
     * @note Complexity: O(E), where E is the number of edges (flights) in the graph.
     */
    void readFlights();
    /**
     * @brief Gets the map of read airports.
     * @return A map containing information about airports.
     */
    unordered_map<string,Airport> getAirportMap();
    /**
     * @brief Gets the map of read airlines.
     * @return A map containing information about airlines.
     */

    unordered_map<string, Airline> getAirlineMap();
    /**
     * @brief Gets the flight graph constructed from the read data.
     * @return A Graph object containing the representation of flights.
     */

    Graph getFlights();
    /**
     * @brief Gets the set of flights read.
     * @return A set containing information about flights.
     */
    set<Flight> getFlightSet();


};


#endif //PROJETO2_AED_READ_H
