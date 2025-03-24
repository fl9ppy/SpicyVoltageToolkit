#include <iostream>
#include "Headers/SystemUtils.h"
#include "Headers/Recon.h"
#include "Headers/Exploitation.h"
#include "Headers/PrivilegeEscalation.h"
#include "Headers/Crypto.h"
#include "Headers/BruteForce.h"
#include "Headers/OSINT.h"
#include "Headers/ScriptsManager.h"

using namespace std;

void banner() {
    cout << BLUE << "\n====================================" << endl;
    cout << BOLD << "     SpicyVoltageToolkit (ALPHA)   " << endl;
    cout << "====================================\n" << RESET << endl;
}

void mainMenu() {
    int choice;
    while (true) {
        banner();
        cout << GREEN << "1. Recon & Enumeration\n";
        cout << "2. Web Exploitation\n";
        cout << "3. Privilege Escalation\n";
        cout << "4. Cryptography Tools\n";
        cout << "5. Brute Force Attacks\n";
        cout << "6. OSINT Tools\n";
        cout << "7. Script Manager\n";
        cout << "8. Exit\n" << RESET;
        cout << BOLD << "Enter your choice: " << RESET;

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "Invalid input! Please enter a number.\n" << RESET;
            continue;
        }

        switch (choice) {
            case 1: reconMenu(); break;
            case 2: exploitationMenu(); break;
            case 3: privilegeEscalationMenu(); break;
            case 4: cryptoMenu(); break;
            case 5: bruteForceMenu(); break;
            case 6: osintMenu(); break;
            case 7: scriptsMenu(); break;
            case 8: cout << GREEN << "Exiting... Goodbye!\n" << RESET; return;
            default: cout << RED << "Invalid choice! Please enter a number between 1 and 8.\n" << RESET;
        }

        waitForEnter();
    }
}

int main() {
    installDependencies();
    mainMenu();
    return 0;
}