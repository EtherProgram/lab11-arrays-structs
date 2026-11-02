
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Adrian A. Mena Cruz]
 * Lab: 11 - Arrays and Structs
 * Description: CoRe Data Analyzer prototype using an array of observations.
 * Due Date: [11/01/2026]
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "observation.h"
#include "display.h"

using namespace std;

int main() {
    const int CAPACITY = 100;
    int requestedObservations = 0;
    int menuChoice = 0;

    // Declare and initialize the observations array.
    Observation observations[CAPACITY]{};

    // Request and validate the number of observations.
    do {
        cout << "How many observations will be entered (1-3)? ";

        if (!(cin >> requestedObservations)) {
            cout << "Invalid input. Enter a number from 1 to 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            requestedObservations = 0;
        }
        else if (requestedObservations < 1 || requestedObservations > 3) {
            cout << "Please enter a number from 1 to 3." << endl;
        }

    } while (requestedObservations < 1 || requestedObservations > 3);

    // Read the observations.
    for (int i = 0; i < requestedObservations; i++) {
        cout << "\nObservation " << (i + 1) << endl;

        cout << "Enter ID: ";
        while (!(cin >> observations[i].id)) {
            cout << "Invalid ID. Enter a whole number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter state: ";
        getline(cin, observations[i].state);

        while (observations[i].state.empty()) {
            cout << "State cannot be empty. Enter state: ";
            getline(cin, observations[i].state);
        }

        cout << "Enter county: ";
        getline(cin, observations[i].county);

        while (observations[i].county.empty()) {
            cout << "County cannot be empty. Enter county: ";
            getline(cin, observations[i].county);
        }

        // Validate total votes.
        cout << "Enter total votes: ";
        while (true) {
            if (!(cin >> observations[i].totalVotes)) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (observations[i].totalVotes < 0) {
                cout << "Vote count cannot be negative. Try again: ";
            }
            else {
                break;
            }
        }

        // Validate Democratic votes.
        cout << "Enter Democratic votes: ";
        while (true) {
            if (!(cin >> observations[i].democraticVotes)) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (observations[i].democraticVotes < 0) {
                cout << "Vote count cannot be negative. Try again: ";
            }
            else {
                break;
            }
        }

        // Validate Republican votes.
        cout << "Enter Republican votes: ";
        while (true) {
            if (!(cin >> observations[i].republicanVotes)) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (observations[i].republicanVotes < 0) {
                cout << "Vote count cannot be negative. Try again: ";
            }
            else {
                break;
            }
        }

        // Validate Democratic share.
        cout << "Enter Democratic share (0-100): ";
        while (true) {
            if (!(cin >> observations[i].democraticShare)) {
                cout << "Invalid input. Enter a value between 0 and 100: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (observations[i].democraticShare < 0.0 ||
                     observations[i].democraticShare > 100.0) {
                cout << "Share must be between 0 and 100. Try again: ";
            }
            else {
                break;
            }
        }

        // Mark the observation as occupied after all fields are entered.
        observations[i].isEmpty = false;
    }

    // Display menu.
    do {
        cout << "\nCoRe Data Analyzer - Lab 11 prototype\n";
        cout << "1. Display Data Frame\n";
        cout << "11. Exit application\n";
        cout << "Enter option number: ";

        if (!(cin >> menuChoice)) {
            cout << "Invalid input. Enter a menu number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuChoice = 0;
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int displayedCount = 0;

                cout << "\n"
                     << left
                     << setw(8) << "ID"
                     << setw(20) << "State"
                     << setw(24) << "County"
                     << setw(14) << "Total Votes"
                     << setw(14) << "Dem Votes"
                     << setw(14) << "Rep Votes"
                     << setw(18) << "Dem Share"
                     << endl;

                for (int i = 0; i < CAPACITY; i++) {
                    if (!observations[i].isEmpty) {
                        displayObservation(observations[i]);
                        displayedCount++;
                    }
                }

                if (displayedCount == 0) {
                    cout << "The dataset is empty." << endl;
                }
                else {
                    cout << "\nObservations displayed: "
                         << displayedCount << endl;
                }

                break;
            }

            case 11:
                cout << "Session ended." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

    } while (menuChoice != 11);

    return 0;
}

/*
 * Analysis:
 *
 * 1. Why can observation ID 151 be stored at array index 0?
 * Because the ID is a data field and is independent of the array index.
 * The first observation is stored at index 0, even if its ID is 151.
 *
 * 2. What initializes unused slots as empty, and when does a slot become occupied?
 * The array initialization with {} and the default member initializer
 * isEmpty = true initialize unused slots as empty.
 * A slot becomes occupied when all its observation data has been entered
 * and isEmpty is set to false.
 *
 * 3. Why does Display examine the capacity but print only occupied observations?
 * The array has a capacity of 100, but not every slot contains a record.
 * Display checks isEmpty and prints only occupied slots.
 *
 * 4. What record is passed to displayObservation on each function call,
 * and is it a copy?
 * One occupied Observation record is passed to displayObservation.
 * It is a copy because the function receives the record by value.
 *
 * 5. Why does the build command include main.cpp and display.cpp but not the headers?
 * The .cpp files contain the program implementation and must be compiled.
 * The headers provide declarations and are included by the .cpp files.
 */
