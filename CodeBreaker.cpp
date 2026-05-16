#include "CodeBreaker.h"
#include <iostream>
#include <cstdlib>

using namespace std;

CodeBreaker::CodeBreaker() : Game("Code Breaker")
{
}

void CodeBreaker::play()
{
    int secret1 = rand() % 10;
    int secret2 = rand() % 10;
    int secret3 = rand() % 10;

    int g1, g2, g3;
    int attempts = 5;

    cout << "\n====================================";
    cout << "\n         CODE BREAKER";
    cout << "\n====================================\n";

    cout << "Guess the secret 3-digit code.\n";

    while (attempts > 0)
    {
        cout << "\nEnter 3 digits: ";
        cin >> g1 >> g2 >> g3;

        if (g1 == secret1 && g2 == secret2 && g3 == secret3)
        {
            cout << "\nCorrect Code! You Win!\n";
            return;
        }

        if (g1 == secret1)
            cout << "First digit correct!\n";

        if (g2 == secret2)
            cout << "Second digit correct!\n";

        if (g3 == secret3)
            cout << "Third digit correct!\n";

        attempts--;

        cout << "Attempts Left: " << attempts << endl;
    }

    cout << "\nGame Over!\n";
    cout << "Secret Code Was: "
         << secret1
         << secret2
         << secret3
         << endl;
}