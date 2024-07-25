#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    // Word store (add more 5-letter words if desired)
    string strList[] = {
        "about", "above", "abuse", "actor", "acute", "admit", "adopt", "adult",
        "after", "again", "agent", "agree", "ahead", "alarm", "album", "alert",
        "alike", "alive", "allow", "alone", "along", "alter", "among", "anger",
        "began", "begin", "begun", "being", "below", "civil", "claim", "class",
        "clean", "drawn", "dream", "dress", "drill", "drink", "drive", "drove",
        "dying", "error", "event", "every", "flash", "fleet", "floor", "fluid",
        "group", "grown", "guard", "guess", "hotel", "house", "index", "inner",
        "input", "issue", "joint", "jones", "judge", "known", "stone", "stood",
        "valid", "value", "video", "virus", "visit", "vital", "voice", "write"
    };

    // Total word count
    int n = sizeof(strList) / sizeof(strList[0]);

    cout << "\n            WORD GUESSING GAME              \n";
    cout << "\nYou can quit anytime by entering : quit \n\n";

    // For random number generator
    srand(static_cast<unsigned int>(time(0)));
    int count = 0;
    string guess;

    // Game loop
    do
    {
        // Random index
        int index = rand() % n;

        // Random positions
        int ch1 = rand() % 5;
        int ch2 = rand() % 5;

        // Ensure different positions
        while (ch2 == ch1)
            ch2 = rand() % 5;

        string str = strList[index];
        string originalStr = str;

        // Replace characters with *
        str[ch1] = '*';
        str[ch2] = '*';

        // Show the word with *s
        cout << "word :  " << str;
        cout << "\nEnter your word guess: ";
        cin >> guess;

        // Check for quit
        if (guess == "quit")
        {
            cout << "\nYour total correct guesses: " << count << endl;
            break;
        }

        // Convert guess to lowercase for case insensitive comparison
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        // Check if the guess is correct
        if (guess == originalStr)
        {
            cout << "\n                   Your guess is correct.\n";
            count++;
        }
        else
        {
            cout << "\n                   Your guess is incorrect.\n";
            cout << "Correct word: " << originalStr << endl;
        }
    } while (true);

    return 0;
}
