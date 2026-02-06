#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to change text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string selectRandomWord() {
    vector<string> wordList;
    wordList.push_back("programming");
    wordList.push_back("condition");
    wordList.push_back("repitition");
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % wordList.size();
    return wordList[index];
}

int main() {
    // Title
    setColor(11);
    cout << "\n=========================================\n";
    cout << "           GUESS AND SURVIVE\n";
    cout << "             HANGMAN GAME\n";
    cout << "=========================================\n\n";

    // Hanging Wood & Rope ASCII Art
    setColor(6); // Brownish (Yellow)
    cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         O\n";
    cout << "        |        /|\\\n";
    cout << "        |        / \\\n";
    cout << "        |\n";
    cout << "     ___|___\n\n";

    // Description
    setColor(10);
    cout << "Welcome to Guess and Survive!\n";
    cout << "A Hangman word guessing game.\n";
    cout << "Guess the hidden word before it's too late!\n\n";

    // Credits
    setColor(14);
    cout << "Presented By:\n\n";
    setColor(13);
    cout << "    * Ibtihaj Muhammad\n";
    cout << "    * Muhammad Zazaan Qazi\n";
    cout << "    * Arslan Mehmood\n";
    cout << "    * Kashif Ali\n\n";

    // Start Prompt
    setColor(9);
    cout << "Press Enter to Start the Game...";
    setColor(7);
    cin.get();

    string secretWord = selectRandomWord();
    string guessedWord(secretWord.length(), '_');
    vector<char> guessedLetters;
    int maxIncorrectGuesses = 7;
    int incorrectGuesses = 0;
    int consecutiveWrong = 0;
    bool dealOffered = false;
    bool hintGiven = false;

    setColor(4); // Red color
    cout << "\nYou have " << maxIncorrectGuesses << " incorrect guesses allowed." << endl;
    setColor(7); // Reset to default color

    while (incorrectGuesses < maxIncorrectGuesses && guessedWord != secretWord) {
    	setColor(10);
        cout << "\nCurrent word: " << guessedWord << endl;
        cout << "Enter your guess (single letter): ";
        setColor(7); // Reset to default color
        
        char guess;
        cin >> guess;
        guess = tolower(guess);

        // Check if the letter was already guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
        	setColor(1); 
            cout << "You already guessed that letter. Try another one." << endl;
            setColor(7); // Reset to default color
            continue;
        }

        guessedLetters.push_back(guess);
        bool correctGuess = false;

        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
        	setColor(6);
            cout << "Good job! The letter '" << guess << "' is in the word." << endl;
            setColor(7); // Reset to default color
            consecutiveWrong = 0; // Reset consecutive wrong counter
        } else {
            incorrectGuesses++;
            consecutiveWrong++;
            setColor(3);
            cout << "Sorry, the letter '" << guess << "' is not in the word." << endl;
            cout << "Incorrect guesses: " << incorrectGuesses << "/" << maxIncorrectGuesses << endl;
            setColor(7); // Reset to default color

            // Deal offer after 2 consecutive wrong guesses
            if (consecutiveWrong == 2 && !dealOffered && incorrectGuesses < maxIncorrectGuesses) {
            	setColor(8);
                cout << "\n*** SPECIAL DEAL ***" << endl;
                cout << "You've made 2 consecutive wrong guesses!" << endl;
                cout << "We can reveal a letter for you, but it will cost 2 lives." << endl;
                cout << "Enter 1 for YES (accept deal) or 2 for NO (reject deal): ";
                setColor(7); // Reset to default color
                int dealChoice;
                cin >> dealChoice;

                if (dealChoice == 1) {
                    // Find an unrevealed letter
                    for (size_t i = 0; i < secretWord.length(); ++i) {
                        if (guessedWord[i] == '_') {
                            char revealedLetter = secretWord[i];
                            // Reveal all instances of this letter
                            for (size_t j = 0; j < secretWord.length(); ++j) {
                                if (secretWord[j] == revealedLetter) {
                                    guessedWord[j] = revealedLetter;
                                }
                            }
                            guessedLetters.push_back(revealedLetter);
                            setColor(13);
                            cout << "Letter revealed: '" << revealedLetter << "'" << endl;
                            incorrectGuesses += 2; // Cost: 2 lives
                            cout << "You now have " << incorrectGuesses << "/" << maxIncorrectGuesses << " incorrect guesses." << endl;
                            
                            break;
                        }
                    }
                    consecutiveWrong = 0;
                    dealOffered = true;
                } else {
                    cout << "Deal rejected! Continue playing..." << endl;
                    setColor(7); // Reset to default color
                    dealOffered = true; // Mark deal as offered (can only be offered once)
                }
            }

            // Hint after 3 wrong moves (if deal was rejected)
            if (incorrectGuesses == 3 && !hintGiven) {
                cout << "\n*** HINT TIME ***" << endl;
                cout << "Decode this phrase to get a hint letter:" << endl;
                // Find an unrevealed letter for the hint
                char hintLetter = '\0';
                for (size_t i = 0; i < secretWord.length(); ++i) {
                    if (guessedWord[i] == '_') {
                        hintLetter = secretWord[i];
                        break;
                    }
                }
                if (hintLetter != '\0') {
                	setColor(12);
                    cout << "The next vowel or consonant you need is: '" << hintLetter << "'" << endl;
                    cout << "(This is just a hint - you still need to guess it!)" << endl;
                    setColor(7); // Reset to default color
                }
                hintGiven = true;
            }
        }
    }

    if (guessedWord == secretWord) {
    	setColor(3);
        cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
    } else {
        cout << "\nGame over! The word was: " << secretWord << endl;
         setColor(7); // Reset to default color
    }

    return 0;
}
