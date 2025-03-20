#ifndef SYSTEM_UTILS_H
#define SYSTEM_UTILS_H

#include <string>

// ANSI Color Codes for better UI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Function to run system commands
void runCommand(const std::string& command);

// Function to install dependencies (only runs once)
void installDependencies();

// Function to simulate loading effect
void loadingEffect(const std::string& message);

// Function to pause until user presses Enter
void waitForEnter();

#endif
