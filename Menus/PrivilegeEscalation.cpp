#include "../Headers/PrivilegeEscalation.h"
#include "../Headers/SystemUtils.h"
#include <iostream>

using namespace std;

void privilegeEscalationMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- Privilege Escalation ---\n" << RESET;
        cout << GREEN << "1. Linux Privilege Escalation (LinPEAS)\n";
        cout << "2. Windows Privilege Escalation (WinPEAS)\n";
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
            loadingEffect("Downloading and Running LinPEAS");
            runCommand("wget -O linpeas.sh https://github.com/carlospolop/PEASS-ng/releases/latest/download/linpeas.sh && chmod +x linpeas.sh && ./linpeas.sh");
        } else if (choice == 2) {
            loadingEffect("Downloading and Running WinPEAS");
            runCommand("wget -O winpeas.exe https://github.com/carlospolop/PEASS-ng/releases/latest/download/winPEASany.exe && winpeas.exe");
        } else if (choice == 3) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}
