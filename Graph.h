#ifndef PROJETO2_AED_GRAPH_H
#define PROJETO2_AED_GRAPH_H

#include "Airline.h"
#include "Airport.h"
#include <string>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

class Edge;
class Graph;
class Vertex;
/**
 * @file Graph.h
 * @brief Definition of Graph, Vertex and Edge classes.
 */

/**
 * @classVertex
 * @brief Represents a vertex in the graph.
 */
class Vertex {
    Airport info;
    vector<Edge> adj;
    bool visited;
    bool processing;
    int num;
    int low;
    int distance;
    int arrives;


public:

    /**
     * @brief Vertex class constructor.
     * @param in Airport associated with the vertex.
     * @details Initializes a vertex with the given airport.
     * @complexity O(1)
     */
    Vertex(Airport in);
    /**
     * @brief Gets information about the airport associated with the vertex.
     * @return The airport information associated with the vertex.
     * @complexity O(1)
     */
    Airport getInfo() const;
    /**
    * @brief Gets the number of flights arriving at an airport.
    * @return The number of flights arriving at the airport.
    * @complexity O(1)
    */
    int getArrives();
    /**
     * @brief Increases the number of flights arriving at the airport.
     * @complexity O(1)
     */
    void addArrives();
    /**
     * @brief Defines the airport information associated with the vertex.
     * @param in New airport information.
     * @complexity O(1)
     */
    void setInfo(Airport in);
    /**
     * @brief Checks whether the vertex was visited during a graph traversal.
     * @return true if the vertex was visited, false otherwise.
     * @complexity O(1)
     */
    bool isVisited() const;
    /**
     * @brief Defines the visited status for the vertex.
     * @param v New visited status.
     * @complexity O(1)
     */
    void setVisited(bool v);
    /**
     * @brief Checks if the vertex is processing.
     * @return True if the vertex is processing, false otherwise.
     * @complexity O(1)
     */
    bool isProcessing() const;
    /**
     * @brief Defines whether the vertex is processing.
     * @param p New value indicating whether the vertex is in processing.
     * @complexity O(1)
     */
    void setProcessing(bool p);
    /**
     * @brief Gets the list of edges adjacent to the vertex.
     * @return The list of edges adjacent to the vertex.
     * @complexity O(1)
     */
    vector<Edge> getAdj() const;
    /**
     * @brief Defines the list of edges adjacent to the vertex.
     * @param adj New list of adjacent edges.
     * @complexity O(1)
     */
    void setAdj(const vector<Edge> &adj);
    /**
     * @brief Adds an edge to the list of edges adjacent to the vertex.
     * @param dest Edge destination vertex.
     * @param w Airline associated with the edge.
     * @details Adds an edge to the list of edges adjacent to the vertex.
     * @complexity O(1)
     */
    void addEdge(Vertex *dest, Airline w);
    /**
     * @brief Gets the distance associated with the vertex.
     * @return The distance associated with the vertex.
     * @complexity O(1)
     */
    int getDistance() const;
    /**
     * @brief Defines the distance associated with the vertex.
     * @param d The new distance associated with the vertex.
     * @complexity O(1)
     */
    void setDistance(int d);
    /**
     * @brief Removes an edge from the list of edges adjacent to the vertex.
     * @param d Destination vertex of the edge to be removed.
     * @return true if the edge was removed, false if the edge does not exist.
     * @complexity O(n), where n is the number of edges in the graph.
     */
    bool removeEdgeTo(Vertex *d);
    /**
     * @brief Equality comparison operator overload for Vertex class.
     * @param v Vertex to be compared.
     * @return true if the vertices are equal, false otherwise.
     * @complexity O(1)
     */
    bool operator==(Vertex v) ;
    /**
     * @brief Gets the number associated with the vertex.
     * @return The number associated with the vertex.
     * @complexity O(1)
     */
    int getNum() const;
    /**
     * @brief Defines the number associated with the vertex.
     * @param num The new number associated with the vertex.
     * @complexity O(1)
     */
    void setNum(int num);
    /**
     * @brief Gets the low value associated with the vertex.
     * @return The low value associated with the vertex.
     * @complexity O(1)
     */
    int getLow() const;
    /**
     * @brief Defines the low value associated with the vertex.
     * @param low The new low value associated with the vertex.
     * @complexity O(1)
     */
    void setLow(int low);
};

/**
 * @classEdge
 * @brief Represents an edge in the graph.
 */
class Edge {
    Vertex * dest;
    Airline weight;
public:
    /**
     * @brief Edge class constructor.
     * @param d Edge destination vertex.
     * @param airline Airline associated with the edge.
     * @details Initializes an edge with the given destination vertex and airline.
     * @complexity O(1)
     */
    Edge(Vertex *d, Airline airline);
    /**
     * @brief Gets the target vertex of the edge.
     * @return The destination vertex of the edge.
     * @complexity O(1)
     */
    Vertex *getDest() const;
    /**
     * @brief Defines the destination vertex of the edge.
     * @param dest New destination vertex.
     * @complexity O(1)
     */
    void setDest(Vertex *dest);
    /**
     * @brief Gets the airline associated with the edge.
     * @return The airline associated with the edge.
     * @complexity O(1)
     */
    Airline getWeight() const;
    /**
     * @brief Defines the airline associated with the edge.
     * @param weight New airline associated with the edge.
     * @complexity O(1)
     */
    void setWeight(Airline* weight);


};

/**
 * @classGraph
 * @brief Represents a graph.
 */
class Graph {
    unordered_map<string, Vertex *> vertexSet;


public:
    /**
     * @brief Gets the entry degree of an airport in the graph.
     * @param airportCode Airport code.
     * @return The indegree of the airport in the graph.
     * @complexity O(1)
     */
    int inDegree(const std::string& airportCode) const;
    /**
     * @brief Default constructor for the Graph class.
     * @details This default constructor is required for creating parameterless Graph objects.
     * @complexity O(1)
     */
    Graph();
    /**
     * @brief Finds a vertex in the graph based on the airport code.
     * @param in Airport to be searched for.
     * @return The vertex corresponding to the airport code, or nullptr if not found.
     * @complexity O(1)
     */
    Vertex *findVertex( Airport &in) const;
    /**
     * @brief Searches for and returns a pointer to a vertex with the given airport code.
     * @param airportCode Code of the airport to be searched for.
     * @return A pointer to the vertex with the airport code, or nullptr if not found.
     * @complexity O(1)
     */
    Vertex *findVertex(const string &airportCode) const;
    /**
     * @brief Gets the number of vertices in the graph.
     * @return The number of vertices in the graph.
     * @complexity O(1)
     */
    int getNumVertex() const;
    /**
     * @brief Adds a vertex to the graph.
     * @param in Airport associated with the new vertex.
     * @return true if the vertex was added, false if the vertex already exists.
     * @complexity O(1)
     */
    bool addVertex(Airport in);
    /**
     * @brief Removes a vertex from the graph.
     * @param in Airport associated with the vertex to be removed.
     * @return true if the vertex was removed, false if the vertex does not exist.
     * @complexity O(V), where V is the number of vertices in the graph.
     */
    bool removeVertex( Airport in);
    /**
     * @brief Adds a directed edge to the graph.
     * @param sourc Airport of origin of the edge.
     * @param dest Edge destination airport.
     * @param w Airline associated with the edge.
     * @return true if the edge was added, false if the origin or destination airports do not exist.
     * @complexity O(1)
     */
    bool addEdge( Airport &sourc,  Airport &dest, Airline w);
    /**
     * @brief Removes an edge from the graph.
     * @param sourc Origin airport of the edge to be removed.
     * @param dest Destination airport of the edge to be removed.
     * @return true if the edge was removed, false if the edge does not exist.
     * @complexity O(V), where V is the number of vertices in the graph.
     */
    bool removeEdge( Airport &sourc, Airport &dest);
    /**
     * @brief Gets the set of vertices of the graph.
     * @return A mapping of airport codes to vertices.
     * @complexity O(1)
     */
    unordered_map<string, Vertex * > getVertexSet() const;

};





#endif //PROJETO2_AED_GRAPH_H
