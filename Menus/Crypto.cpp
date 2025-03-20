#include "../Headers/Crypto.h"
#include "../Headers/SystemUtils.h"
#include <iostream>

using namespace std;

void cryptoMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- Cryptography Tools ---\n" << RESET;
        cout << GREEN << "1. Base64 Encode/Decode\n";
        cout << "2. ROT13 Encode/Decode\n";
        cout << "3. Hash Identifier\n";
        cout << "4. Back\n" << RESET;
        cout << BOLD << "Enter your choice: " << RESET;

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "Invalid input! Please enter a number.\n" << RESET;
            continue;
        }

        if (choice == 1) {
            string text;
            cout << "Enter text to encode/decode: ";
            cin >> text;
            loadingEffect("Processing Base64 Encoding/Decoding");
            runCommand("echo " + text + " | base64 --decode 2>/dev/null || echo " + text + " | base64");
        } else if (choice == 2) {
            string text;
            cout << "Enter text to encode/decode: ";
            cin >> text;
            loadingEffect("Processing ROT13 Encoding/Decoding");
            runCommand("echo " + text + " | tr 'A-Za-z' 'N-ZA-Mn-za-m'");
        } else if (choice == 3) {
            string hash;
            cout << "Enter hash to identify: ";
            cin >> hash;
            loadingEffect("Running Hash Identifier");
            runCommand("echo " + hash + " | hash-identifier");
        } else if (choice == 4) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}
