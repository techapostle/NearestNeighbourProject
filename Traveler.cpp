#include "Traveler.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Traveler::Traveler() {
    this->currentLocation = "";
    this->visitedLocations = {};
}

Traveler::Traveler(string currentLocation) {
    this->currentLocation = currentLocation;
    this->visitedLocations = {};
}