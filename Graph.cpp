#include "Graph.h"

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double d1): dest(d), distance(d1) {}


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
void Vertex<T>::setInfo(T in) {
    Vertex::info = in;
}


template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *d) {
    Edge::dest = d;
}

template<class T>
double Edge<T>::getDistance() const {
    return distance;
}

template<class T>
void Edge<T>::setDistance(double weight) {
    Edge::distance = distance;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}

template <class T>
bool Graph<T>::addVertex(const T &in) {
    if (findVertex(in) == NULL) {
        Vertex<T> * it = new Vertex<T> (in);
        vertexSet.push_back(it);
        return true;
    }
    return false;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    if (findVertex(sourc) != NULL && findVertex(dest) != NULL) {
        findVertex(sourc)->addEdge(findVertex(dest),w);
        return true;
    }
    return false;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    this->adj.push_back(Edge<T>(d,w));
}


template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    vector<Edge<T>> aux= findVertex(sourc)->getAdj();
    for(auto it:aux){
        if(it.getDest()== findVertex(dest)){
            findVertex(sourc)->removeEdgeTo(findVertex(dest));
            return true;
        }
    }
    return false;
}


template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    auto it=this->adj.begin();
    while(it!=this->adj.end()){
        if(it->getDest()==d){
            this->adj.erase(it);
            return true;
        }
        it++;
    }
    return false;
}


template <class T>
bool Graph<T>::removeVertex(const T &in) {
    auto it=vertexSet.begin();
    Vertex<T> *foundVertex= nullptr;
    while(it!=vertexSet.end()){
        if((*it)->getInfo()==in){
            foundVertex=*it;
            vertexSet.erase(it);
            break;
        }
        else{
            it++;
        }
    }
    if(foundVertex==NULL){
        return false;
    }
    for(auto it:vertexSet){
        if(it==foundVertex){
            it->removeEdgeTo(foundVertex);
        }
    }
    return true;
}