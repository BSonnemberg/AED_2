#ifndef PROJETO2_AED_AIRPORT_H
#define PROJETO2_AED_AIRPORT_H
#include <iostream>
#include <string>
using namespace std;

/**
 * @file Airport.h
 * @brief Airport class declaration.
 */

/**
 * @class Airport
 * @brief Represents an airport with code, name, city, country, latitude and longitude.
 */

class Airport {
private:
    string code,name,city,country;
    double latitude,longitude;

public:

/**
 * @brief Default constructor for the Airport class.
 * @details This default constructor is required for creating parameterless Airport objects.
 * @complexity O(1)
 */
    Airport();
    /**
     * @brief Constructor for the Airport class.
     * @param code Airport code.
     * @param name Name of the airport.
     * @param city City of the airport.
     * @param country Country of the airport.
     * @param latitude Latitude of the airport.
     * @param longitude Longitude of the airport.
     * @details This constructor initializes the class members with the given values.
     * @complexity O(1)
     */
    Airport(string code, string name, string city, string country, double latitude, double longitude);
    /**
     * @brief Gets the airport code.
     * @return The airport code.
     * @complexity O(1)
     */
    string getCode();
    /**
     * @brief Gets the name of the airport.
     * @return The name of the airport.
     * @complexity O(1)
     */
    string getName() const;
    /**
     * @brief Gets the airport city.
     * @return The airport city.
     * @complexity O(1)
     */
    string getCity();


    /**
     * @brief Gets the country of the airport.
     * @return The country of the airport.
     * @complexity O(1)
     */
    string getCountry();

    /**
     * @brief Gets the latitude of the airport.
     * @return The latitude of the airport.
     * @complexity O(1)
     */
    double getLatitude();

    /**
     * @brief Gets the longitude of the airport.
     * @return The longitude of the airport.
     * @complexity O(1)
     */
    double getLongitude();
    /**
     * @brief Overloading the equality operator for the Airport class.
     * @param other Another Airport object to compare.
     * @return true if the airport codes are the same, false otherwise.
     * @complexity O(1)
     */
    bool operator==(const Airport &other) const;
};


#endif //PROJETO2_AED_AIRPORT_H
