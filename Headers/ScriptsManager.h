#ifndef SCRIPTS_MANAGER_H
#define SCRIPTS_MANAGER_H

#include <string>

// Function to display the scripts menu
void scriptsMenu();

// Function to list available scripts in the Scripts directory
void listScripts();

// Function to execute a selected script
void runScript(const std::string& scriptName);

// Function to add a new script to the directory
void addScript();

#endif
