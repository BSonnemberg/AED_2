
#include <stack>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <limits>
#include <cmath>
#include "Manager.h"
#include "Flight.h"

Manager::Manager(Graph& graph) : flights_graph(graph) {}



void Manager::getGlobalNumAirports() const {
    int numAirports=flights_graph.getNumVertex();
    std::cout << "Global number of airports: " << numAirports << std::endl;
}



void Manager::getGlobalNumCities() const {
    std::set<std::pair<std::string, std::string>> uniqueCityCountry;

    for (const auto &vertexPair : flights_graph.getVertexSet()) {
        const Vertex *vertex = vertexPair.second;

        uniqueCityCountry.insert({vertex->getInfo().getCity(), vertex->getInfo().getCountry()});
    }

    std::cout << "Global number of cities: " << uniqueCityCountry.size() << std::endl;
}


void Manager::getGlobalNumCountries() const {
    std::set<std::string> uniqueCountries;

    for (const auto &vertexPair : flights_graph.getVertexSet()) {
        const Vertex *vertex = vertexPair.second;

        uniqueCountries.insert(vertex->getInfo().getCountry());
    }

    std::cout << "Global number of countries: " << uniqueCountries.size() << std::endl;
}


void Manager::getGlobalNumAirlines() const {
    std::set<std::string> uniqueAirlines;

    for (const auto &vertexPair : flights_graph.getVertexSet()) {
        const Vertex *vertex = vertexPair.second;

        for (const Edge &edge : vertex->getAdj()) {
            uniqueAirlines.insert(edge.getWeight().getCode());
        }
    }

    std::cout << "Global number of airlines: " << uniqueAirlines.size() << std::endl;
}



void Manager::getNumAvailableFlights() const {
    int numAvailableFlights=0;
    auto vertexSet = flights_graph.getVertexSet();

    for (const auto& entry : vertexSet) {
        const Vertex* vertex = entry.second;
        numAvailableFlights += vertex->getAdj().size();
    }
    std::cout << "Number of available flights: " << numAvailableFlights<< std::endl;
}


void Manager::getNumFlightsFromAirport(const std::string& airportCode){

    Vertex* airportVertex = flights_graph.findVertex(airportCode);

    if (airportVertex != nullptr) {
        unsigned numFlights = airportVertex->getAdj().size();
        std::cout << "Number of flights out of airport " << airportCode << ": " << numFlights << std::endl;
    } else {
        std::cout << "Airport not found!" << std::endl;
    }
}


void Manager::getNumAirlinesFromAirport(const std::string& airportCode){
    Vertex* airportVertex = flights_graph.findVertex(airportCode);
    if (airportVertex != nullptr) {
        set<std::string> uniqueAirlines;

        for (const Edge& edge : airportVertex->getAdj()) {
            uniqueAirlines.insert(edge.getWeight().getCode());
        }

        unsigned numAirlines = uniqueAirlines.size();
        std::cout << "Number of different airlines out of airport " << airportCode << ": " << numAirlines << std::endl;

    } else {
        std::cout << "Airport not find!" << airportCode << std::endl;
    }

}

void Manager::getNumFlightsPerCity(const std::string& cityName, string& country){
    unsigned numFlights=0;
    const auto& vertexSet = flights_graph.getVertexSet();

    for (const auto& vertexPair : vertexSet) {
        const Vertex* vertex = vertexPair.second;

        if (vertex->getInfo().getCity() == cityName && vertex->getInfo().getCountry()==country) {
            numFlights += vertex->getAdj().size();
            numFlights += flights_graph.inDegree(vertex->getInfo().getCode());
        }
    }

    std::cout<< "Number of flights from " << cityName << ": " << numFlights << std::endl;
}


void Manager::getNumFlightsPerAirline(const std::string& airlineCode){
    unsigned numFlights=0;
    for(const auto &vertex:flights_graph.getVertexSet()){
        for(const auto &edge:vertex.second->getAdj()){
            if(edge.getWeight().getCode()==airlineCode){
                numFlights++;
            }
        }
    }
    std::cout<< "Number of flights from " << airlineCode << ": " << numFlights << std::endl;
}

//----------------
void Manager::getNumDestinationsPerAirline(const std::string& airlineCode) {
    std::set<std::string> uniqueDestinations;// cria um set auxiliar para guardar os destinos

    for (const auto& vertexPair : flights_graph.getVertexSet()) {
        const Vertex* vertex = vertexPair.second;  //itera sobre todos os vertices do graph

        for (const Edge& edge : vertex->getAdj()) { //para cada edge de cada vertice
            if (edge.getWeight().getCode() == airlineCode) {//verifica se o codigo da ailine corresponde à airline fornecida
                const Vertex* destVertex = edge.getDest();//se isso se verificar adiciona o codigo do vertice de destino ao set
                uniqueDestinations.insert(destVertex->getInfo().getCode());
            }
        }
    }

    unsigned numDestinations = uniqueDestinations.size();
    std::cout << "Number of destinations for airline " << airlineCode << ": " << numDestinations << std::endl;
}


void Manager::getNumDestCountriesPerCity(const string &cityName, string &country) { //recebe dois parametros
    std::set<std::string> countries; //cria um set onde vai armazenar os paises

    for (const auto& vertexPair :flights_graph.getVertexSet()) { //itera sobre os vertices do graph
        const Vertex* vertex = vertexPair.second;

        if (vertex->getInfo().getCity() == cityName && vertex->getInfo().getCountry() == country) {  //e verifica se a cidade e o pais sao os mesmos que os que a funcao recebe
            for (const Edge& edge : vertex->getAdj()) { //se isso  se verificar , itera todos os edges desse vertice
                countries.insert(edge.getDest()->getInfo().getCountry());//e insere esses paises no set
            }
        }
    }
    std::cout << "Number of different countries flown to from " << cityName << ": " << countries.size() << std::endl;

}

void Manager::getNumDestCountriesPerAirport(const std::string& airportCode){
    std::set<std::string> countries;// criado tambem um set onde se armazena os paises
    for(const auto &edge : flights_graph.getVertexSet().at(airportCode)->getAdj()){ //iteramos sobre todos os edges correspondentes do vertice com aquele airportCode
        countries.insert(edge.getDest()->getInfo().getCountry());//adicionamos ao set o pais de cada edge
    }
    std::cout << "Number of different countries flown to from " << airportCode<< ": " << countries.size() << std::endl;

}

void Manager::getNumDestinations(const string &airportCode) {//semelhante a um ex da aula
    Vertex* startVertex = flights_graph.findVertex(airportCode); //armazenamos o aeroporto desejado num vertice
    int airports = 0; //criamos um counter para contar o numero de aeroportos
    if(startVertex == nullptr){ //verificamos se existe o aeroporto pedido
        cout << "Airport not found!";
        return;
    }
    for(const auto &pair : flights_graph.getVertexSet()){//se existir iteramos sobre todos os vertices do graph e marcamo-os como nao visitados
        pair.second->setVisited(false);
    }
    set<string> countries; //criamos um set para armazenar os paises q podemos atingir
    set<pair<string, string>> citiesAndCountries;//e criamos outro para armazenar as cidades em funcao do seu país
    queue<pair<Vertex*,int>> bfs; //criamos uma queue para fazermos uma procura BFS
    bfs.emplace(startVertex, 0);// adicionamos o primeiro vertice  com um distancia inicial de 0, e  marcamos como visitado
    startVertex->setVisited(true);

    while (!bfs.empty()){//em seguida realizamos um loop ate a queue estar vazia
        auto[curVertex, dist] = bfs.front(); //tiramos e eliminamos da queue  o vertice e a distancia
        bfs.pop();

        for(const auto &k : curVertex->getAdj()){ //iteramos sobre todos os edges desse vertice para obter os seus neighbors
            Vertex * neighbor = k.getDest();
            if(!neighbor->isVisited()){ //se o neighbor n foi visitado adicionamos 1 aos aeroportos
                airports++;
                pair<string, string> cityAndCountry = make_pair(neighbor->getInfo().getCity(), neighbor->getInfo().getCountry());
                citiesAndCountries.insert(cityAndCountry);//ADICIONamos a sua respetiva cidade
                countries.insert(neighbor->getInfo().getCountry());// e adicionamos o respetivo pais
                bfs.emplace(neighbor, dist + 1); //e adicionamos esse vizinho á queue incrementando 1 á distancia
                neighbor->setVisited(true);//e marcamos como visitado

            }
        }
    }

    cout << "From " << airportCode << " airport " << "there are: " << airports << " airports, " << citiesAndCountries.size() << " cities and " << countries.size() << " countries reachable. " << endl;

}

//--------------------------------
void Manager::getCountReachableDestinations(const std::string &airportCode, int maxStops) const {
    Vertex* startVertex = flights_graph.findVertex(airportCode);
    if(startVertex == nullptr){
        cout << "Airport not found!";

        return;
    }
    int airports = 0;
    for(const auto &pair : flights_graph.getVertexSet()){
        pair.second->setVisited(false);
    }
    set<string> countries;
    set<pair<string, string>> citiesAndCountries;
    queue<pair<Vertex*,int>> bfs;
    bfs.emplace(startVertex, 0);
    startVertex->setVisited(true);

    while (!bfs.empty()){
        auto[curVertex, dist] = bfs.front();
        bfs.pop();

        if(dist >= maxStops) continue;

        for(const auto &k : curVertex->getAdj()){
            Vertex * neighbor = k.getDest();
            if(!neighbor->isVisited()){
                airports++;
                pair<string, string> cityAndCountry = make_pair(neighbor->getInfo().getCity(), neighbor->getInfo().getCountry());
                citiesAndCountries.insert(cityAndCountry);
                countries.insert(neighbor->getInfo().getCountry());
                bfs.emplace(neighbor, dist + 1);
                neighbor->setVisited(true);
            }
        }
    }
    cout << "From " << airportCode << " airport " << "there are: " << airports << " airports, " << citiesAndCountries.size() << " cities and " << countries.size() << " countries reachable. " << "With up to " << maxStops << " stops.";
}


void Manager::bfs(const std::string &startAirportCode) {
    for (auto &vertexPair : flights_graph.getVertexSet()) {
        Vertex *vertex = vertexPair.second;
        vertex->setVisited(false);
        vertex->setDistance(-1);
    }

    std::queue<Vertex *> bfsQueue;
    Vertex *startVertex = flights_graph.findVertex(startAirportCode);


    if (startVertex == nullptr) {
        std::cerr << "Airport not found: " << startAirportCode << std::endl;
        return;
    }

    startVertex->setDistance(0);
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        Vertex *currentVertex = bfsQueue.front();
        bfsQueue.pop();

        for (const Edge &edge : currentVertex->getAdj()) {
            Vertex *neighbor = edge.getDest();
            if (!neighbor->isVisited()) {
                neighbor->setVisited(true);
                neighbor->setDistance(currentVertex->getDistance() + 1);
                bfsQueue.push(neighbor);
            }
        }
    }
}


void Manager::getMaxTrip() {
    int max_distance = 0;
    std::unordered_set<std::string> max_distance_pair;

    for (const auto &airportPair : flights_graph.getVertexSet()) {
        Vertex *startAirportVertex = airportPair.second;

        bfs(startAirportVertex->getInfo().getCode());

        for (const auto &otherAirportPair :flights_graph.getVertexSet()) {
            Vertex *otherAirportVertex = otherAirportPair.second;


            if (otherAirportVertex->getInfo().getCode() != startAirportVertex->getInfo().getCode()) {
                int distance = flights_graph.findVertex(otherAirportVertex->getInfo().getCode())->getDistance();

                if (distance > max_distance) {

                    max_distance = distance;
                    max_distance_pair.clear();
                    max_distance_pair.insert(startAirportVertex->getInfo().getCode() + "-" + otherAirportVertex->getInfo().getCode());
                } else if (distance == max_distance) {
                    max_distance_pair.insert(startAirportVertex->getInfo().getCode() + "-" + otherAirportVertex->getInfo().getCode());
                }


            }
        }

    }
    std::cout << "Corresponding pair(s) with the maximum distance (" << max_distance << "):" << std::endl;
    for (const auto &pair : max_distance_pair) {
        std::cout << pair << std::endl;
    }

}


void Manager::getTopKAirports(int k) const {
    vector<pair<Vertex *, int >> airports;
    for (const auto & vertex: flights_graph.getVertexSet()){
        airports.emplace_back(vertex.second, vertex.second->getAdj().size()+ vertex.second->getArrives());
    }
    sort(airports.begin(), airports.end(), [](const pair<Vertex *, int>& a, const pair<Vertex *, int>& b) {
        return a.second > b.second;
    });

    cout<<"The top-" << k<<" airport are: "<< endl;
    for (int i = 0; i < k && i < airports.size(); ++i) {
        cout << airports[i].first->getInfo().getName() << ": " << airports[i].second << endl;
    }

}

void Manager::dfs_art(const Graph& graph, Vertex* vertex, stack<string>& s, unordered_set<string>& res, int& index)  const {
    vertex->setNum(index);
    vertex->setLow(index);
    index++;

    vertex->setVisited(true);
    s.push(vertex->getInfo().getCode());

    for (const auto& edge : vertex->getAdj()) {
        Vertex* neighbor = edge.getDest();

        if (neighbor->getNum() == -1) {
            dfs_art(graph, neighbor, s, res, index);

            vertex->setLow(min(vertex->getLow(), neighbor->getLow()));

            if (vertex->getNum() == 1 && s.size() > 1) {
                res.insert(vertex->getInfo().getCode());
            } else if (vertex->getNum() > 1 && neighbor->getLow() >= vertex->getNum()) {
                res.insert(vertex->getInfo().getCode());
            }
        } else if (s.size() > 1 && neighbor->getNum() < vertex->getNum()) {
            vertex->setLow(min(vertex->getLow(), neighbor->getNum()));
        }
    }
    s.pop();
}

void Manager::getIdentifyEssentialAirports() const {
    unordered_set<string> res;
    Graph undirectedGraph;

    for (const auto& v : flights_graph.getVertexSet()) {
        undirectedGraph.addVertex(v.second->getInfo());
    }

    for (const auto& v : flights_graph.getVertexSet()) {
        for (const auto& edge : v.second->getAdj()) {
            Airport a = v.second->getInfo();
            Airport b = edge.getDest()->getInfo();
            undirectedGraph.addEdge(a, b, edge.getWeight());
            undirectedGraph.addEdge(b, a, edge.getWeight());
        }
    }

    for (auto v : undirectedGraph.getVertexSet()) {
        v.second->setVisited(false);
        v.second->setNum(-1);
        v.second->setLow(-1);
    }

    int index = 0;
    stack<string> s;

    for (auto vtx : undirectedGraph.getVertexSet()) {
        if (!vtx.second->isVisited()) {
            dfs_art(undirectedGraph, vtx.second, s, res, index);
        }
    }

    cout << "Number of Articulation Points: " << res.size() << endl;
    int count=0;
    for( auto r: res){
        count++;
        auto v=undirectedGraph.getVertexSet().at(r);
        cout << count << "-" << v->getInfo().getName() <<endl;
    }


}

double Manager::calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double earthRadius = 6371.0;

    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = sin(dLat / 2.0) * sin(dLat / 2.0) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2.0) * sin(dLon / 2.0);

    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    double distance = earthRadius * c;

    return distance;
}

std::vector<Vertex*> Manager::findClosestAirports(double latitude, double longitude) {
    std::vector<Vertex*> closestAirports;
    double minDistance = std::numeric_limits<double>::max();

    for (const auto &vertexPair : flights_graph.getVertexSet()) {
        Vertex* vertex = vertexPair.second;
        double distance = calculateDistance(latitude, longitude, vertex->getInfo().getLatitude(), vertex->getInfo().getLongitude());

        if (distance < minDistance) {
            minDistance = distance;
            closestAirports.clear();
            closestAirports.push_back(vertex);
        } else if (distance == minDistance) {
            closestAirports.push_back(vertex);
        }
    }
    return closestAirports;
}

vector<Vertex*>  Manager::findVertexByInput(const std::string &input) {
    Vertex *vertex = flights_graph.findVertex(input);
    vector<Vertex*> airCity;
    std::size_t commaPos = input.find(',');
    size_t c = input.find('-');
    string city;
    string country;
    if (commaPos != std::string::npos) {
        double latitude = std::stod(input.substr(0, commaPos));
        double longitude = std::stod(input.substr(commaPos + 1));

        std::vector<Vertex*> closestAirports = findClosestAirports(latitude, longitude);

        return closestAirports;
    }

    if(c != string::npos){
        for (const auto &vertexPair : flights_graph.getVertexSet()){
            if(vertexPair.second->getInfo().getCity()== input.substr(0, c) && vertexPair.second->getInfo().getCountry() == input.substr(c + 1)){
                city = vertexPair.second->getInfo().getCity();
                country = vertexPair.second->getInfo().getCountry();
            }
        }
    }
    if (vertex != nullptr) {
        airCity.push_back(vertex);
    } else {
        for (const auto &vertexPair : flights_graph.getVertexSet()) {
            Vertex *currentVertex = vertexPair.second;
            if(currentVertex->getInfo().getName()==input){
                airCity.push_back(currentVertex);
            }
            else if (currentVertex->getInfo().getCity() == city && currentVertex->getInfo().getCountry()==country) {
                airCity.push_back(currentVertex);
            } else if (currentVertex->getInfo().getCountry() == input) {
                airCity.push_back(currentVertex);
            }
        }
    }
    return airCity;
}


void Manager::findBestFlightOption(const std::string &source, const std::string &destination,const std::vector<std::string>& preferredAirlines) {

    std::vector<Vertex*> sourceAirports = findVertexByInput(source);
    vector<Vertex*> destAirports = findVertexByInput(destination);

    if(sourceAirports.empty() || destAirports.empty()){
        cout << "Invalid Inputs!";
        return;
    }

    std::vector<std::pair<int, std::string>> flightOptions;
    int minStops = INT_MAX;

    for (Vertex *sourceVertex : sourceAirports) {

        for (auto &vertexPair : flights_graph.getVertexSet()) {
            Vertex *vertex = vertexPair.second;
            vertex->setVisited(false);
        }

        std::queue<std::tuple<Vertex*, int, std::string>> bfsQueue;
        bfsQueue.push({sourceVertex, 0, sourceVertex->getInfo().getCode()});

        while (!bfsQueue.empty()) {
            auto [currentVertex, stops, path] = bfsQueue.front();
            bfsQueue.pop();

            for (auto destinationVertex: destAirports) {
                if (currentVertex->getInfo() == destinationVertex->getInfo()) {

                    if (stops < minStops) {
                        minStops = stops;
                        flightOptions.clear();
                    }
                    if (stops == minStops) {
                        flightOptions.push_back({stops, path});

                    }
                    break;
                }
            }

            for (const Edge &edge : currentVertex->getAdj()) {
                Vertex *neighbor = edge.getDest();
                if (!neighbor->isVisited() && (preferredAirlines.empty() || std::find(preferredAirlines.begin(), preferredAirlines.end(), edge.getWeight().getCode()) != preferredAirlines.end())) {
                    neighbor->setVisited(true);
                    bfsQueue.push({neighbor, stops + 1, path + "->" + neighbor->getInfo().getCode()});
                }
            }
        }
    }

    cout << "Flight from " << sourceAirports.front()->getInfo().getCity() << " to " << destAirports.front()->getInfo().getCity() << std::endl;
    cout << "--------------------------" << endl;
    if (flightOptions.empty()) cerr << "No flights available!";

    for (const auto &flightOption : flightOptions) {
        int stops = flightOption.first;
        std::string path = flightOption.second;
        std::cout << "Stops: " << stops-1 << " | Path: " << path << std::endl;
    }
}

