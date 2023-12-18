#ifndef PROJETO2_AED_GRAPH_H
#define PROJETO2_AED_GRAPH_H

#include "Airlines.h"
#include "Airports.h"
#include <string>
#include <set>
#include <list>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Vertex {
    T info;
    vector<Edge<T>> adj;
    bool visited;

    void addEdge(Vertex<T> *dest, double distance);
    bool removeEdgeTo(Vertex<T> *d);

public:
    Vertex(T in);
    T getInfo() const;
    void setInfo(T in);
    bool isVisited() const;
    void setVisited(bool v);
    const vector<Edge<T>> &getAdj() const;
    void setAdj(const vector<Edge<T>> &adj);
    friend class Graph<T>;
};

template <class T>
class Edge {
    Vertex<T> * dest;
    double distance;
public:
    Edge(Vertex<T> *d, double w);
    Vertex<T> *getDest() const;
    void setDest(Vertex<T> *dest);
    double getDistance() const;
    void setDistance(double distance);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph {
    vector<Vertex<T> *> vertexSet;
public:
    Vertex<T> *findVertex(const T &in) const;
    int getNumVertex() const;
    bool addVertex(const T &in);
    bool removeVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w);
    bool removeEdge(const T &sourc, const T &dest);
    vector<Vertex<T> * > getVertexSet() const;
    int inDegree(const T &v) const;
};



};



#endif //PROJETO2_AED_GRAPH_H
