// adventofcode1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Open the text file for reading
    ifstream file(TXTPATH);

    // Check if the file could be opened
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    // Initialize a vector to store the calorie counts of all the elves
    vector<int> calorieCounts;

    // Read the file line by line
    string line;
    int currentCalories = 0;
    while (getline(file, line)) {
        // If the line is not empty, add the calorie count from the current line to the current elf's calorie count
        if (!line.empty()) {
            currentCalories += stoi(line);
        }
        // Otherwise, this signifies the end of the current elf's calorie counts
        else {
            // Add the current calorie count to the vector
            calorieCounts.push_back(currentCalories);
            // Reset the current calorie count
            currentCalories = 0;
        }
    }

    // Don't forget to add the final elf's calorie count
    calorieCounts.push_back(currentCalories);

    // Check if the file was empty
    if (calorieCounts.empty()) {
        cerr << "Error: File is empty." << endl;
        return 1;
    }

    // Sort the calorie counts in descending order
    sort(calorieCounts.begin(), calorieCounts.end(), greater<int>());

    // Print the top three calorie counts
    cout << "The top three elves have " << calorieCounts[0] << ", " << calorieCounts[1] << ", and " << calorieCounts[2] << " calories, respectively." << endl;

    // Calculate and print the total of the top three calorie counts
    int total = calorieCounts[0] + calorieCounts[1] + calorieCounts[2];
    cout << "The total calorie count of the top three elves is " << total << "." << endl;

    return 0;
}
