// adventofcode1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Open the text file for reading
    ifstream file("calorie_counts.txt");
       
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    // Initialize variables to store the current elf's calorie count and the maximum calorie count
    int currentCalories = 0;
    int maxCalories = 0;

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        // If the line is not empty, add the calorie count from the current line to the current elf's calorie count
        if (!line.empty()) {
            currentCalories += stoi(line);
        }
        // Otherwise, this signifies the end of the current elf's calorie counts
        else {
            // Update the maximum calorie count if necessary
            if (currentCalories > maxCalories) {
                maxCalories = currentCalories;
            }
            // Reset the current calorie count
            currentCalories = 0;
        }
    }

    // Don't forget to check the final elf's calorie count
    if (currentCalories > maxCalories) {
        maxCalories = currentCalories;
    }

    // Print the maximum calorie count
    cout << "The elf carrying the most calories has " << maxCalories << " calories." << endl;

    return 0;
}
