#include "../Headers/ScriptsManager.h"
#include "../Headers/SystemUtils.h"
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

// Function to display the Scripts menu
void scriptsMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n--- Script Manager ---\n" << RESET;
        cout << GREEN << "1. List Available Scripts\n";
        cout << "2. Run a Script\n";
        cout << "3. Add a New Script\n";
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
            listScripts();
        } else if (choice == 2) {
            string scriptName;
            cout << "Enter script name to execute: ";
            cin >> scriptName;
            runScript(scriptName);
        } else if (choice == 3) {
            addScript();
        } else if (choice == 4) {
            break;
        } else {
            cout << RED << "Invalid choice! Try again.\n" << RESET;
        }

        waitForEnter();
    }
}

// Function to list all available scripts in the "Scripts/" directory
void listScripts() {
    cout << CYAN << "\nAvailable Scripts:\n" << RESET;
    string path = "Scripts/";

    if (!fs::exists(path)) {
        cout << RED << "[!] Scripts directory not found. Creating it now...\n" << RESET;
        fs::create_directory(path);
        return;
    }

    bool found = false;
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << GREEN << " - " << entry.path().filename().string() << RESET << endl;
        found = true;
    }

    if (!found) {
        cout << YELLOW << "[!] No scripts found in the Scripts directory.\n" << RESET;
    }
}

// Function to execute a script
void runScript(const string& scriptName) {
    string fullPath = "Scripts/" + scriptName;

    if (!fs::exists(fullPath)) {
        cout << RED << "[!] Script not found: " << scriptName << RESET << endl;
        return;
    }

    loadingEffect("Executing " + scriptName);

    // Determine file extension and execute accordingly
    if (scriptName.ends_with(".sh")) {
        runCommand("bash " + fullPath);
    } else if (scriptName.ends_with(".py")) {
        runCommand("python3 " + fullPath);
    } else if (scriptName.ends_with(".pl")) {
        runCommand("perl " + fullPath);
    } else {
        runCommand("./" + fullPath);
    }
}

// Function to add a new script to the "Scripts/" directory
void addScript() {
    string scriptName;
    cout << "Enter new script name (e.g., exploit.py, custom.sh): ";
    cin >> scriptName;

    string fullPath = "Scripts/" + scriptName;

    if (fs::exists(fullPath)) {
        cout << RED << "[!] A script with this name already exists. Choose a different name.\n" << RESET;
        return;
    }

    cout << YELLOW << "[*] Enter script content (Press Ctrl+D to save and exit):\n" << RESET;

    ofstream scriptFile(fullPath);
    if (!scriptFile) {
        cout << RED << "[!] Failed to create script file.\n" << RESET;
        return;
    }

    // Read script content from user input
    cin.ignore();
    string line;
    while (getline(cin, line)) {
        scriptFile << line << "\n";
    }

    scriptFile.close();
    runCommand("chmod +x " + fullPath); // Make the script executable

    cout << GREEN << "[+] Script added successfully: " << scriptName << RESET << endl;
}
