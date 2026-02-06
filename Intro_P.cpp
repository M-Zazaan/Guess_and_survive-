#include <iostream>
#include <windows.h>
using namespace std;

// Function to change text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {

    // Title
    setColor(11);
    cout << "\n=========================================\n";
    cout << "          GUESS AND SURVIVE\n";
    cout << "            HANGMAN GAME\n";
    cout << "=========================================\n\n";

    // Hanging Wood & Rope ASCII Art
    setColor(6); // Brownish (Yellow)
    cout << "        ___________\n";
    cout << "       |           |\n";
    cout << "       |           |\n";
    cout << "       |           O\n";
    cout << "       |          /|\\\n";
    cout << "       |          / \\\n";
    cout << "       |\n";
    cout << "    ___|___\n\n";

    // Description
    setColor(10);
    cout << "Welcome to Guess and Survive!\n";
    cout << "A Hangman word guessing game.\n";
    cout << "Guess the hidden word before it's too late!\n\n";

    // Credits
    setColor(14);
    cout << "Presented By:\n\n";

    setColor(13);
    cout << "  * Ibtihaj Muhammad\n";
    cout << "  * Muhammad Zazaan Qazi\n";
    cout << "  * Arslan Mehmood\n";
    cout << "  * Kashif Ali\n\n";

    // Start Prompt
    setColor(9);
    cout << "Press Enter to Start the Game...";

    setColor(7);
    cin.get();

    return 0;
}
