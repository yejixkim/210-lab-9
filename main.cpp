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

int main() {
    return 0;
}