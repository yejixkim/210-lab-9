// COMSC 210 | Lab 9 | Yeji Kim

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

// this is a simulation of the number of soil samples that gets processed each day for 30 days

const int DAYS = 30;

// function to display the array

void displayArray(const array<int, DAYS>& samples) { 
    cout << "\nSoil samples processed each day:\n"; 
    for (auto it = samples.cbegin(); it != samples.cend(); ++it) { 
        cout << *it << " "; } 
    cout << endl; }

// function to display the vector

void displayVector(const vector<int>& samples) {
    cout << "\nSoil samples processed each day:\n";
    for (auto it = samples.cbegin(); it != samples.cend(); ++it) { 
        cout << *it << " "; } 
    cout << endl; 
}

int main() {
    // std::array

    cout << "SOIL SAMPLE PROCESSING SIMULATION\n"; 
    cout << "\nPART 1: STD::ARRAY\n";

    // make an array to store the number of samples processed during each of the 30 days

    array<int, DAYS> samples;

    // open external data file

    ifstream inputFile("soil_samples.txt");

    if (!inputFile) {
        cout << "Error opening file\n";
        return 1;
    }

    // read the data from file into array

    for (int i = 0; i < DAYS; i++) {
        inputFile >> samples[i];
    }

    inputFile.close();

    // display data

    displayArray(samples);

    // array functions:

    // array::size()
    
    cout << "\nNumber of days recorded: " << samples.size() << endl; 
    
    // array::max_size() 
    
    cout << "Maximum possible array size: " << samples.max_size() << endl; 
    
    // array::empty() 
    
    cout << "Is the array empty? ";

    return 0;
}