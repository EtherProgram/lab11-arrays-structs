/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Adrian A. Mena Cruz]
 * Lab: 11 - Arrays and Structs
 * Description: Defines the Observation struct and its electoral data fields.
 * Due Date: [11/01/2026]
 */

#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string>

struct Observation {
    int id = 0;

    std::string state = "";
    std::string county = "";

    int totalVotes = 0;
    int democraticVotes = 0;
    int republicanVotes = 0;

    double democraticShare = 0.0;

    bool isEmpty = true;
};

#endif