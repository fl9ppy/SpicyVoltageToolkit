#include "../Headers/SystemUtils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

const string DEPENDENCY_FILE = "ctf_tool_installed.flag";

// Function to execute system commands
void runCommand(const string& command) {
    system(command.c_str());
}

// Function to simulate a loading effect
void loadingEffect(const string& message) {
    cout << YELLOW << "[*] " << message << "..." << RESET << flush;
    for (int i = 0; i < 3; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << " Done!" << endl;
}

// Function to install dependencies (runs only once)
void installDependencies() {
    ifstream infile(DEPENDENCY_FILE);
    if (infile.good()) {
        cout << GREEN << "[+] Dependencies already installed. Skipping...\n" << RESET;
        return;
    }

    loadingEffect("Checking and Installing Dependencies");

    runCommand("sudo apt update && sudo apt install -y nmap sqlmap gobuster steghide binwalk john exiftool hydra hashcat linpeas winpeas rot13 hash-identifier amass theharvester sublist3r");

    ofstream outfile(DEPENDENCY_FILE);
    outfile << "installed";
    outfile.close();

    cout << GREEN << "[+] Installation Complete!\n" << RESET;
}

// Function to pause until user presses Enter
void waitForEnter() {
    cout << CYAN << "\n[Press Enter to return to the menu] " << RESET;
    cin.ignore();
    cin.get();
}
