// AI Disclosure: Code written with assistance from Claude (Anthropic) - logic and structure by student

#include "CodeBreaker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor calls base class constructor with title
CodeBreaker::CodeBreaker() : Game("Code Breaker")
{
    maxAttempts = 8;
}

// Generates a random 4-digit code with unique digits
string CodeBreaker::generateCode()
{
    string code = "";
    string digits = "0123456789";

    srand(time(0));

    while (code.length() < 4)
    {
        int idx = rand() % digits.length();
        char digit = digits[idx];

        // make sure no repeated digits
        if (code.find(digit) == string::npos)
            code += digit;
    }

    return code;
}

// Bulls = correct digit, correct position
// Cows  = correct digit, wrong position
void CodeBreaker::checkGuess(string guess, int& bulls, int& cows)
{
    bulls = 0;
    cows = 0;

    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == secretCode[i])
        {
            bulls++;
        }
        else if (secretCode.find(guess[i]) != string::npos)
        {
            cows++;
        }
    }
}

// Main game loop - overrides base class pure virtual function
void CodeBreaker::play()
{
    cout << "\n==============================" << endl;
    cout << "       CODE BREAKER           " << endl;
    cout << "==============================" << endl;
    cout << "Guess the 4-digit secret code!" << endl;
    cout << "Digits are unique (no repeats)." << endl;
    cout << "BULLS = right digit, right spot" << endl;
    cout << "COWS  = right digit, wrong spot" << endl;
    cout << "You have " << maxAttempts << " attempts." << endl;
    cout << "------------------------------" << endl;

    secretCode = generateCode();
    int attempts = 0;
    bool won = false;

    while (attempts < maxAttempts)
    {
        string guess;
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter 4-digit guess: ";
        cin >> guess;

        // Basic input validation
        if (guess.length() != 4)
        {
            cout << "Please enter exactly 4 digits!" << endl;
            continue;
        }

        attempts++;

        int bulls = 0, cows = 0;
        checkGuess(guess, bulls, cows);

        cout << "Bulls: " << bulls << "  |  Cows: " << cows << endl;

        if (bulls == 4)
        {
            cout << "\n*** You cracked the code! Well done! ***" << endl;
            won = true;
            break;
        }
    }

    if (!won)
    {
        cout << "\nGame over! The code was: " << secretCode << endl;
    }

    cout << "==============================\n" << endl;
}
