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

#include "traveler.h"

using namespace std;

int main() {
  // open file locations_1.txt
  ifstream file("locations_1.txt");
  if (!file.is_open()) {
    cout << "Error: file not found" << endl;
    return 1;
  }

  // Create traveler object
  Traveler traveler;

  // Read in locations from file
  string location;
  // Declare a vector to store the locations
  vector<string> locations;
  while (file >> location) {
    locations.push_back(location);
  } // at this point, our vector should contain all the locations

  

}



