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
        cout << *it << " "; 
    } 
    cout << endl; }

// function to display the vector

void displayVector(const vector<int>& samples) {
    cout << "\nSoil samples processed each day:\n";
    for (auto it = samples.cbegin(); it != samples.cend(); ++it) { 
        cout << *it << " "; 
    } 
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
    
    if (samples.empty()) { 
        cout << "Yes\n"; 
    } 
    else { cout << "No\n"; 
    }

    // array::front() 
    
    cout << "Samples processed on Day 1: " << samples.front() << endl; 
    
    // array::back() 
    
    cout << "Samples processed on Day 30: " << samples.back() << endl; 
    
    // array::at() 
    
    cout << "Samples processed on Day 6: " << samples.at(5) << endl; 
    
    // array::operator[] 
    
    cout << "Samples processed on Day 11: " << samples[10] << endl; 
    
    // array::data() 
    
    cout << "First value using data(): " << *samples.data() << endl;

    // calc total samples

    int totalSamples = 0;

    for (auto it = samples.begin(); it != samples.end(); ++it) { 
        totalSamples += *it; 
    } 
        
    cout << "\nTotal soil samples processed: " << totalSamples << endl; 
    
    // calc average 
    
    double average = static_cast<double>(totalSamples) / samples.size(); 
    cout << "Average samples processed per day: " << average << endl;

    // find highest/lowest processing days

    auto highest = max_element(samples.begin(), samples.end()); 
    auto lowest = min_element(samples.begin(), samples.end()); 

    cout << "Highest number of samples in one day: " << *highest << endl; 
    cout << "Lowest number of samples in one day: " << *lowest << endl;

    // find which day had most/least samples

    int highestDay = (highest - samples.begin()) + 1; 
    int lowestDay = (lowest - samples.begin()) + 1; 
    
    cout << "Highest processing day: Day " << highestDay << endl; 
    cout << "Lowest processing day: Day " << lowestDay << endl;

    // find how many days were above avg

    int aboveAverage = 0; 
    for (auto it = samples.begin(); it != samples.end(); ++it) { 
        if (*it > average) { 
            aboveAverage++; 
        } 
    } 
        
        cout << "Days above the average: " << aboveAverage << endl;

    // std::vector
    
    cout << "PART 2: STD::VECTOR\n"; 

    //make an empty vector
    vector<int> sampleVector;

    // open ext data file
    ifstream inputFile("soil_samples.txt");

    if (!inputFile) {
        cout << "Error opening file\n";
        return 1;
    }

    // read data into vector
    int sampleCount; 

    while (vectorFile >> sampleCount) { 
        sampleVector.push_back(sampleCount); 
    } 
    
    vectorFile.close();

    // display vector
    displayVector(sampleVector);

    //vector functions:

    // vector::size() 
    cout << "\nNumber of days recorded: " << sampleVector.size() << endl; 
    
    // vector::capacity() 
    cout << "Vector capacity: " << sampleVector.capacity() << endl; 
    
    // vector::empty() 
    cout << "Is the vector empty? "; 
    
    if (sampleVector.empty()) { 
        cout << "Yes\n"; 
    } 
    else { 
        cout << "No\n"; 
    }

    return 0;
}