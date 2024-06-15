#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess = 0;
    int attempts = 0;

    cout<< "Guess the number (1 to 100): ";

    do {
        if (!(cin>> guess)) {
            cout<< "Please enter a valid number!" << endl;
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard input
            continue;
        }

        attempts++;

        if (guess < number) {
            cout << "Too low. Try again: ";
        } else if (guess > number) {
            cout<< "Too high. Try again: ";
        } else {
            cout<< "Correct! You guessed the number in " << attempts<< " attempts." << endl;
        }
    } while (guess != number);

    return 0;
}