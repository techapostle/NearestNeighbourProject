// <Sofia Cardenas> 
// <"none"> 
// <Lab Section 43)> 
// <April 23rd>

//------------------------------------------------------
// AUTOGRADER INFO -- IGNORE BUT DO NOT REMOVE 
// test_cases: true
// feedback('all')
// 35b24e49-2842-4603-8ba7-0f656200c2d1
//------------------------------------------------------

// Add your code here!
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

struct Planet {
  int id;
  string name;
  int row;
  int column;
  bool visited = false;
};

vector<Planet> planets;
int gridRows, gridColumns;
int startRow, startColumn;
int endRow, endColumn;

/*
* Function: correctName
* --------------------
* This function takes a corrupted name and returns the correct name.
* Pairs of Xs can be inserted into various locations in the planet’s name
* Any spaces in the planet’s name get converted to underscores (_)
* To correct the data, any double XXs need to be removed from the planet name, and the underscores (_) need to be replaced with spaces.
*/
string correctName(string corruptedName) {
  string correctName;
  for (int i = 0; i < corruptedName.size(); i++) {
    if (corruptedName[i] == "X" && corruptedName[i+1] == "X") {
      i++;
    } else {
      correctName += corruptedName[i];
    }
  }

  replace(correctName.begin(), correctName.end(), ' ', '_');

  return correctName;
}

void readData(string locationsFilename, string namesFilename) {
  ifstream locationsFile(locationsFilename);
  ifstream namesFile(namesFilename);

  if (!locationsFile.is_open() || !namesFile.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  locationsFile >> gridRows >> gridColumns;
  locationsFile >> startRow >> startColumn;
  locationsFile >> endRow >> endColumn;

  Planet planet;
  while (locationsFile >> planet.id >> planet.row >> planet.column) {
    if (planet.row < 1 || planet.row > gridRows || planet.column < 1 || planet.column > gridColumns) {
      cout << "Invalid location" << endl;
      return;
    }
    planets.push_back(planet);
  }

  map<int, string> planetNames;
  int id;
  string name;
  while (namesFile >> id >> name) {
    planetNames[id] = correctName(name);
  }

  // for each planet in planets
  for (auto &planet : planets) {
    planet.name = planetNames[planet.id];
  }
}

vector<Planet> calculateRoute() {
  vector<Planet> route;
  int currentRow = startRow;
  int currentColumn = startColumn;

  while (route.size() < planets.size()) {
    Planet *nearestPlanet = nullptr;
    double minDistance = numeric_limits<double>::max();

    for (auto &planet : planets) {
      if (!planet.visited) {
        double dist = distance(currentRow, currentColumn, planet.row, planet.column);
        if (dist < minDistance) {
          minDistance = dist;
          nearestPlanet = &planet;
        }
      }
    }

    if (nearestPlanet) {
      nearestPlanet->visited = true;
      route.push_back(*nearestPlanet);
      currentRow = nearestPlanet->row;
      currentColumn = nearestPlanet->column;
    }
  }

  route.emplace_back(Planet{-1, "End Location", endRow, endColumn});

  return route;
}

void createJourneyFile(vector<Planet> route) {}

double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


int main() {
  string locationsFilename, namesFilename;
  cout << "Enter the name of the locations file: ";
  cin >> locationsFilename;
  cout << "Enter the name of the names file: ";
  cin >> namesFilename;

  readData(locationsFilename, namesFilename);
  auto route = calculateRoute();
  createJourneyFile(route);
}



