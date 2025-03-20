#include "../Headers/OSINT.h"
#include "../Headers/SystemUtils.h"
#include <iostream>

using namespace std;

void osintMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- OSINT Tools ---\n" << RESET;
        cout << GREEN << "1. Subdomain Enumeration (Amass)\n";
        cout << "2. Email Harvesting (theHarvester)\n";
        cout << "3. Subdomain Scanning (Sublist3r)\n";
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
            string domain;
            cout << "Enter target domain: ";
            cin >> domain;
            loadingEffect("Running Amass Subdomain Enumeration");
            runCommand("amass enum -d " + domain);
        } else if (choice == 2) {
            string domain;
            cout << "Enter target domain: ";
            cin >> domain;
            loadingEffect("Running theHarvester for email harvesting");
            runCommand("theHarvester -d " + domain + " -l 500 -b all");
        } else if (choice == 3) {
            string domain;
            cout << "Enter target domain: ";
            cin >> domain;
            loadingEffect("Running Sublist3r for subdomain scanning");
            runCommand("sublist3r -d " + domain);
        } else if (choice == 4) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}
