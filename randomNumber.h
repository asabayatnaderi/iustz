#pragma once

#include <random>
#include <chrono>

using namespace std;

// Function to generate a random number between 0 and 100
short generateRandomNumber()
{
    mt19937 mt{static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count())};
    uniform_int_distribution<int> dist(0, 100);
    return dist(mt);
}