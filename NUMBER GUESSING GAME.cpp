#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1, guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've Guessed a number between 1 and 100. Can you guess what it is?" << endl;
    cout << "Enter your guess, and may the odds be in your favor!" << endl;

    do {
        cin >> guess;
        cout << (guess > randomNumber ? "Too high. Try again!"
             : guess < randomNumber ? "Too low! Give it another shot!"
             : "Congratulations, you have guessed the correct number!") << endl;
    } while (guess != randomNumber);

    cout << "Well done, brave soul! Thanks for playing." << endl;

    return 0;
}
