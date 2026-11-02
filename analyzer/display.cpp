/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Adrian A. Mena Cruz]
 * Lab: 11 - Arrays and Structs
 * Description: Implements the function that displays an electoral observation.
 * Due Date: [11/01/2026]
 */

#include <iostream>
#include <iomanip>
#include "observation.h"
#include "display.h"

using namespace std;

void displayObservation(Observation observation) {
    cout << left
         << setw(8) << observation.id
         << setw(20) << observation.state
         << setw(24) << observation.county
         << setw(14) << observation.totalVotes
         << setw(14) << observation.democraticVotes
         << setw(14) << observation.republicanVotes
         << fixed << setprecision(2)
         << setw(18) << observation.democraticShare
         << endl;
}