#pragma once

#include "Game.h"
#include <string>
using namespace std;

// Derived class from Game (Inheritance)
class CodeBreaker : public Game
{
public:
    CodeBreaker();
    void play() override;

private:
    string secretCode;       // the 4-digit code to guess
    int maxAttempts;

    string generateCode();                              // generates random 4-digit code
    void checkGuess(string guess, int& bulls, int& cows); // bulls = right digit right place, cows = right digit wrong place
};
