
#include <iostream>
#include <limits>
#include "Menu.h"
#include "Read.h"
#include "Manager.h"

Menu::Menu() {

}

void Menu::firstMenu() {
    Read reader;
    reader.readAirports();
    reader.readAirlines();
    reader.readFlights();

    Graph flightsGraph = reader.getFlights();
    Manager manager(flightsGraph);


    int option;
    do {
    cout << '\n' << "Flight Management System" << endl;
    cout << "------------------------" << endl;
    cout << "1. Display Statistics" << endl;
    cout << "2. Display Airport Information" << endl;
    cout << "3. Find Best Flight Option" << endl;
    cout << "4. Identify Essential Airports" << endl;
    cout << "5. Exit" << endl;
    cout << "------------------------" << endl;

    cout << '\n' << "Please insert a number: ";
    cin >> option;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
    } else {
        switch (option) {
            case 1:
                globalStatisticsMenu();
                break;
            case 2:
                airportInformationMenu();
                break;
            case 3:
                findBestFlightOptionMenu();
                break;
            case 4:
                manager.getIdentifyEssentialAirports();
                break;
            case 5:
                cout << "Exiting the program";
                return;
            default:
                std::cout << "Choose a valid number." << std::endl;
                break;

        }
    }
    } while (option != 5);
}

void Menu::globalStatisticsMenu() {
    Read reader;
    Menu menu;
    reader.readAirports();
    reader.readAirlines();
    reader.readFlights();

    Graph flightsGraph = reader.getFlights();
    Manager manager(flightsGraph);

    int option;
    cout << "Global Statistics Menu" << endl;
    cout << "----------------------" << endl;
    cout << "1. Number of Airports" << endl;
    cout << "2. Number of Cities" << endl;
    cout << "3. Number of Countries" << endl;
    cout << "4. Number of Airlines" << endl;
    cout << "5. Number of Available Flights" << endl;
    cout << "6. Display the maximum trip" << endl;
    cout << "7. Exit to Main Menu" << endl;
    cout << "----------------------" << endl;

    cout << '\n' << "Please insert a number: ";
    cin >> option;

    switch (option) {
        case 1:
            manager.getGlobalNumAirports();
            break;
        case 2:
            manager.getGlobalNumCities();
            break;
        case 3:
            manager.getGlobalNumCountries();
            break;
        case 4:
            manager.getGlobalNumAirlines();
            break;
        case 5:
            manager.getNumAvailableFlights();
            break;
        case 6:
            manager.getMaxTrip();
            break;
        case 7:
            menu.firstMenu();
            break;
        default:
            std::cout << "Invalid option. Please enter a valid option." << std::endl;

    }
}

void Menu::airportInformationMenu() const {
    Read reader;
    Menu menu;
    reader.readAirports();
    reader.readAirlines();
    reader.readFlights();

    Graph flightsGraph = reader.getFlights();
    Manager manager(flightsGraph);
    std::cout << "Airport Information Menu" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "1. Number of Flights from an Airport" << std::endl;
    std::cout << "2. Number of Airlines from an Airport" << std::endl;
    std::cout << "3. Number of Flights per City" << std::endl;
    std::cout << "4. Number of Flights per Airline" << std::endl;
    std::cout << "5. Number of Destinations per Airline" << std::endl;
    std::cout << "6. Number of Destination Countries per City" << std::endl;
    std::cout << "7. Number of Destination Countries per Airport" << std::endl;
    std::cout << "8. Number of Destinations for an Airport" << std::endl;
    std::cout << "9. Number of Reachable Destinations from an Airport" << std::endl;
    cout << "10. The top-k airport with the greatest air traffic capacity" << endl;
    std::cout << "11. Exit to Main Menu" << std::endl;
    std::cout << "------------------------" << std::endl;

    int airportInfoOption;
    std::cout << '\n' << "Enter your choice: ";
    std::cin >> airportInfoOption;
    string code;
    string country;
    int stop;
    switch (airportInfoOption) {
        case 1:

            cout << "Enter airport code: ";
            cin >> code;
            manager.getNumFlightsFromAirport(code);
            break;
        case 2:
            cout << "Enter airport code: ";
            cin >> code;
            manager.getNumAirlinesFromAirport(code);
            break;
        case 3:
            cin.ignore();
            cout << "Enter city name: ";
            getline(cin, code);

            cout << "Enter country name: ";
            getline(cin, country);

            manager.getNumFlightsPerCity(code, country);
            break;
        case 4:

            cout <<"Enter airline code: ";
            cin>> code;

            manager.getNumFlightsPerAirline(code);
            break;
        case 5:
            cout <<"Enter airline code: ";
            cin >> code;
            manager.getNumDestinationsPerAirline(code);
            break;
        case 6:
            cin.ignore();
            cout << "Enter city name: ";
            getline(cin, code);

            cout << "Enter country name: ";
            getline(cin, country);
            manager.getNumDestCountriesPerCity(code, country);
            break;
        case 7:
            cout << "Enter airport code: ";
            cin >> code;
            manager.getNumDestCountriesPerAirport(code);
            break;
        case 8:
            cout << "Enter airport code: ";
            cin >> code;

            manager.getNumDestinations(code);
            break;
        case 9:
            cout << "Enter airport code: ";
            cin >> code;
            cout << "Enter the maximum number of stops: ";
            cin >> stop;
            manager.getCountReachableDestinations(code, stop);
            break;
        case 10:
            cout << "Enter the value of k: ";
            cin >> stop;
            manager.getTopKAirports(stop);
            break;
        case 11:
            menu.firstMenu();
            break;
        default:
            std::cout << "Invalid option. Please enter a valid option." << std::endl;

    }
}

void Menu::findBestFlightOptionMenu() {
    string source;
    string dest;
    char addFilter;
    string code;
    vector<string> filter;
    Read reader;
    reader.readAirports();
    reader.readAirlines();
    reader.readFlights();

    Graph flightsGraph = reader.getFlights();
    Manager manager(flightsGraph);
    cin.ignore();
    cout << "If you want to enter a city, input it in the format <city>-<country>. If you enter coordinates, use the format <latitude>,<longitude>." << endl;
    cout << '\n' <<"Enter the source: ";
    getline(cin, source);
    cout << "Enter the destination: ";
    getline(cin,dest);

    cout << "Do you want to add airports to the filter? (y/n): ";
    cin >>addFilter;
    if (addFilter == 'y' || addFilter == 'Y') {
        cout << "Enter airport codes to add to the filter. Enter 'd' to stop." << endl;
        string airportCode;
        do {
            cout << "Enter airport code: ";
            cin >> airportCode;
            if (airportCode != "d") {
                filter.push_back(airportCode);
            }
        } while (airportCode != "d");


    }
    manager.findBestFlightOption(source, dest, filter);


}
