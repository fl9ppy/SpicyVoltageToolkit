#include "../Headers/Recon.h"
#include "../Headers/SystemUtils.h"
#include <iostream>

using namespace std;

void reconMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- Reconnaissance & Enumeration ---\n" << RESET;
        cout << GREEN << "1. Nmap Scan\n";
        cout << "2. Subdomain Enumeration (Gobuster)\n";
        cout << "3. Back\n" << RESET;
        cout << BOLD << "Enter your choice: " << RESET;

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "Invalid input! Please enter a number.\n" << RESET;
            continue;
        }

        if (choice == 1) {
            string target;
            cout << "Enter target IP/Domain: ";
            cin >> target;
            loadingEffect("Running Nmap Scan");
            runCommand("nmap -A " + target);
        } else if (choice == 2) {
            string domain;
            cout << "Enter domain: ";
            cin >> domain;
            loadingEffect("Enumerating subdomains with Gobuster");
            runCommand("gobuster dns -d " + domain + " -w /usr/share/wordlists/dirb/common.txt");
        } else if (choice == 3) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}
