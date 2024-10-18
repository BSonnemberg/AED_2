
/**
 * @fileManager.h
 * @brief Declaration of the Manager class responsible for managing operations in the flight graph.
 */

#ifndef PROJETO2_AED_MANAGER_H
#define PROJETO2_AED_MANAGER_H

#include "Graph.h"
#include <stack>
#include <unordered_set>

/**
 * @brief Class responsible for managing operations in the flight graph.
 */
class Manager {
public:
    /**
     * @brief Constructor for the Manager class.
     * @param graph Graph of flights to be managed.
     */
    Manager(Graph& graph);
    /**
     * @brief Gets the global number of airports and the global number of available flights.
     * @note Complexity: O(1)
     */
    void getGlobalNumAirports() const;
    /**
     * @brief Gets the global number of distinct airport cities.
     * @note Complexity: O(V⋅logK), where V is the number of vertices (airports).
     */
    void getGlobalNumCities() const;
    /**
     * @brief Gets the total number of available flights.
     * @note Complexity: O(V+E), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getNumAvailableFlights() const;
    /**
     * @brief Gets the global number of different countries in airports.
     * @note Complexity: O(V⋅logK), where V is the number of vertices (airports).
     */
    void getGlobalNumCountries() const;
    /**
     * @brief Get the global number of specific airlines at airports.
     * @note Complexity: O(V⋅E⋅logK), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getGlobalNumAirlines() const;
    /**
     * @brief Gets the number of flights leaving an airport.
     * @param airportCode The airport code.
     * @note Complexity: O(1)
     */
    void getNumFlightsFromAirport(const string& airportCode);
    /**
     * @brief Gets the number of different airlines leaving an airport.
     * @param airportCode The airport code.
     * @note Complexity: O(E⋅logK), where E is the number of edges (flights) leaving the airport.
     */
    void getNumAirlinesFromAirport(const string& airportCode);
    /**
     * @brief Calculates the number of flights departing from a specific city in a given country.
     *
     * This function iterates through the vertices of the flight graph and accumulates
     * the total number of flights departing from the specified city in the given country.
     *
     * @param cityName The name of the city.
     * @param country The name of the country to which the city belongs.
     *
     * @note The function considers both outgoing and incoming flights to and from the city.
     *
     * @timecomplexity O(V + E), where V is the number of vertices and E is the number of edges in the graph.
     */
    void getNumFlightsPerCity(const std::string& cityName, string& country);
    /**
     * @brief Gets the number of flights for a specific airline.
     * @param airlineCode The airline code.
     * @note Complexity: O(V⋅E), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getNumFlightsPerAirline(const std::string& airlineCode);
    /**
     * @brief Retrieves the number of different countries flown to from a specific city.
     *
     * This function iterates through the vertices of the flight graph, focusing on the specified city and country.
     * It collects unique destination countries for flights departing from the given city.
     *
     * @param cityName The name of the city.
     * @param country The name of the country to which the city belongs.
     *
     * @note The function considers both outgoing and incoming flights to and from the city.
     *
     * @timecomplexity O(V + E), where V is the number of vertices and E is the number of edges in the graph.
     */
    void getNumDestCountriesPerCity(const string &cityName, string &country);
    /**
    * @brief Gets the number of different countries flown to from an airport.
    * @param airportCode The airport code.
    * @note Complexity: O(E⋅logK), where E is the number of edges (flights) leaving the airport.
    */
    void getNumDestCountriesPerAirport(const std::string& airportCode);
    /**
     * @brief Gets the main airports based on arrivals and departures criteria.
     * @param k The number of major airports to display.
     * @note Complexity: O(V log(V)), where V is the number of vertices (airports) in the graph.
     */
    void getTopKAirports(int k) const;
    /**
     * @brief Gets the total number of destinations reachable from an airport with a maximum number of layovers.
     * @param airportCode The airport code.
     * @param maxStops The maximum number of stops allowed.
     * @note Complexity: O(V+E), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getCountReachableDestinations(const std::string &airportCode, int maxStops) const;
    /**
    * @brief Gets the total number of destinations (airports, cities or countries) reachable from an airport.
    * @param airportCode The airport code.
    * @note Complexity: O(V+E+(V+E)⋅logK), where V is the number of vertices (airports) and E is the number of edges (flights).
    */
    void getNumDestinations(const string &airportCode);
    /**
     * @brief Identifies airports essential to the network's circulation capacity.
     * @note Complexity: O(V + E), where V is the number of vertices (airports) and E is the number of edges (flights) in the graph.
     */
    void getIdentifyEssentialAirports() const;
    /**
     * @brief Gets the corresponding pair(s) with the maximum distance between airports.
     * @note Complexity: O(V^2 + VE), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getMaxTrip();
    /**
     * @brief Gets the number of destinations for a specific airline.
     * @param airlineCode The airline code.
     * @note Complexity: O(V⋅E⋅logK), where V is the number of vertices (airports) and E is the number of edges (flights).
     */
    void getNumDestinationsPerAirline(const std::string& airlineCode);
    /**
     * @brief Finds the best flight option with or without airlines preferences.
     * @param source Departure airport.
     * @param destination Destination airport.
     * @param preferredAirlines Vector of preferred airline codes.
     * @note Complexity: O(V * (V + E)), where V is the number of vertices (airports) and E is the number of edges (flights) in the graph.
     */
    void findBestFlightOption(const std::string &source, const std::string &destination, const std::vector<std::string>& preferredAirlines);

private:
    Graph& flights_graph; /**< Flight graph. */
    set<string> visited; /**< Set of visited airports. */

    /**
     * @brief Performs a breadth-first search (BFS) from an airport.
     * @param startAirportCode The departure airport code.
     * @note Complexity: O(V^2 + VE), where V is the number of vertices (airports) and E is the number of edges (flights).
     */

    void bfs(const std::string &startAirportCode);
    /**
     * @brief Performs a depth-first search (DFS) to identify the articulation points in the graph.
     * @param graph The graph to be analyzed.
     * @param vertex The current vertex under analysis.
     * @param s An auxiliary stack for tracking vertices.
     * @param res A set to store the identified articulation points.
     * @param index A tracking index during DFS.
     * @note Complexity: O(V + E), where V is the number of vertices (airports) and E is the number of edges (flights) in the graph.
     */
    void dfs_art(const Graph& graph, Vertex* vertex, stack<string>& s, unordered_set<string>& res, int& index) const;
    /**
     * @brief Calculates the distance between two points on the Earth's surface using the Haversine formula.
     * @param lat1 Latitude of point 1 in degrees.
     * @param lon1 Longitude of point 1 in degrees.
     * @param lat2 Latitude of point 2 in degrees.
     * @param lon2 Longitude of point 2 in degrees.
     * @return The distance between the two points in kilometers.
     * @note Complexity: O(1).
     */

    double calculateDistance(double lat1, double lon1, double lat2, double lon2);
    /**
    * @brief Finds the nearest airports based on a latitude and longitude.
    * @param latitude Latitude of the desired location.
    * @param longitude Longitude of the desired location.
    * @return A vector of pointers to vertices representing the nearest airports.
    * @note Complexity: O(V), where V is the number of vertices (airports) in the graph.
    */

    std::vector<Vertex*> findClosestAirports(double latitude, double longitude);
    /**
     * @brief Finds vertices corresponding to a given input (airport name, coordinates, city, country).
     * @param input The input provided by the user.
     * @return A vector of pointers to vertices corresponding to the input.
     * @note Complexity: O(V), where V is the number of vertices (airports) in the graph.
     */
    vector<Vertex*>  findVertexByInput(const std::string &input);


};


#endif //PROJETO2_AED_MANAGER_H
