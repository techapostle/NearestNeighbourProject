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

#ifndef TRAVELER_H
#define TRAVELER_H

#include <iostream>
#include <string>
#include <vector>

class Traveler {
public:
  Traveler();
  Traveler(std::string currentLocation);

  std::vector<std::string&> getVisitedLocations() const;
  std::string getCurrentLocation() const;

  void addVisitedLocation(std::string location);
  void setCurrentLocation(std::string location);

  void travelTo(std::string location);
  void travel(std::vector<std::string> locations);

private:
  std::vector<std::string> visitedLocations; // vector of visited locations
  std::vector<std::string> locations; // sorted vector of locations
  std::string currentLocation; // current location
};

#endif