#ifndef SYSTEM_UTILS_H
#define SYSTEM_UTILS_H

#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void runCommand(const std::string& command);

void installDependencies();

void loadingEffect(const std::string& message);

void waitForEnter();

#endif
