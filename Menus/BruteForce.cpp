#include "../Headers/BruteForce.h"
#include "../Headers/SystemUtils.h"
#include <iostream>

using namespace std;

void bruteForceMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- Brute Force Attacks ---\n" << RESET;
        cout << GREEN << "1. Hydra (Online Password Cracking)\n";
        cout << "2. John the Ripper (Offline Cracking)\n";
        cout << "3. Hashcat (Advanced GPU Cracking)\n";
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
            string target, service, wordlist;
            cout << "Enter target IP/Host: ";
            cin >> target;
            cout << "Enter service (ssh, ftp, http, etc.): ";
            cin >> service;
            cout << "Enter wordlist path: ";
            cin >> wordlist;
            loadingEffect("Running Hydra brute-force attack");
            runCommand("hydra -L usernames.txt -P " + wordlist + " " + target + " " + service);
        } else if (choice == 2) {
            string hashfile;
            cout << "Enter hash file path: ";
            cin >> hashfile;
            loadingEffect("Running John the Ripper");
            runCommand("john --wordlist=/usr/share/wordlists/rockyou.txt " + hashfile);
        } else if (choice == 3) {
            string hashfile, hashType;
            cout << "Enter hash file path: ";
            cin >> hashfile;
            cout << "Enter hash type (example: 0 for MD5, 1000 for NTLM): ";
            cin >> hashType;
            loadingEffect("Running Hashcat for GPU password cracking");
            runCommand("hashcat -m " + hashType + " " + hashfile + " /usr/share/wordlists/rockyou.txt --force");
        } else if (choice == 4) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}
