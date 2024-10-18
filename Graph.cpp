#include "Graph.h"

Vertex::Vertex(Airport in): info(in) {}

Edge::Edge(Vertex *d, Airline airline){
    this->dest = d;
    this->weight = airline;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

unordered_map<string, Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

Airport Vertex::getInfo() const {
    return info;
}

void Vertex::setInfo(Airport in) {
    Vertex::info = in;
}


Vertex *Edge::getDest() const {
    return dest;
}


void Edge::setDest(Vertex *d) {
    Edge::dest = d;
}

Airline Edge::getWeight() const {
    return weight;
}

bool Vertex::operator==(Vertex v)  {
    return this->info==v.info;
}

Vertex * Graph::findVertex( Airport &in) const {
    auto f = vertexSet.find(in.getCode());
    return (f != vertexSet.end()) ? f->second: nullptr;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool v) {
    Vertex::visited = v;
}

vector<Edge> Vertex::getAdj() const {
    return adj;
}

void Vertex::setAdj(const vector<Edge> &adj) {
    Vertex::adj = adj;
}

bool Graph::addVertex( Airport in) {
    if (findVertex(in) != nullptr) {
        return false;
    }
    vertexSet.emplace(in.getCode(), new Vertex(in));
    return true;
}

bool Graph::addEdge( Airport &sourc,  Airport &dest, Airline w) {
    if (findVertex(sourc) != NULL && findVertex(dest) != NULL) {
        findVertex(sourc)->addEdge(findVertex(dest),w);
        findVertex(dest)->addArrives();
        return true;
    }
    return false;
}

void Vertex::addEdge(Vertex *d, Airline w) {
    this->adj.push_back(Edge(d,w));
}

bool Graph::removeEdge( Airport &sourc,  Airport &dest) {
    vector<Edge> aux= findVertex(sourc)->getAdj();
    for(auto it:aux){
        if(it.getDest()== findVertex(dest)){
            findVertex(sourc)->removeEdgeTo(findVertex(dest));
            return true;
        }
    }
    return false;
}

bool Vertex::removeEdgeTo(Vertex *d) {
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

bool Graph::removeVertex( Airport in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it).first == in.getCode()) {
            Vertex *v = it->second;
            vertexSet.erase(it);
            for (auto n: vertexSet)
                n.second->removeEdgeTo(v);
            vertexSet.erase(in.getCode());
            return true;
        }
    return false;
}

Graph::Graph(){};

int Graph::inDegree(const std::string &airportCode) const {

        int inDegree = 0;

        for (const auto& entry : vertexSet) {
            const Vertex* vertex = entry.second;

            for (const Edge& edge : vertex->getAdj()) {
                if (edge.getDest()->getInfo().getCode() == airportCode) {
                    inDegree++;
                }
            }
        }

        return inDegree;
}


int Vertex::getArrives() {
    return arrives;
}

void Vertex::addArrives() {
    arrives++;
}

Vertex* Graph::findVertex(const std::string &airportCode) const {
    auto  f  = vertexSet.find(airportCode);
    return (f != vertexSet.end()) ? f->second : nullptr;
}


int Vertex::getNum() const {
    return num;
}

void Vertex::setNum(int num) {
    Vertex::num = num;
}

int Vertex::getLow() const {
    return low;
}

void Vertex::setLow(int low) {
    Vertex::low=low;
}

int Vertex::getDistance() const {
    return distance;
}


void Vertex::setDistance(int d) {
    distance = d;
}