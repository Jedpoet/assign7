#include "AnsiPrint.h"
#include "controller.h"
#include "view.h"
#include <iostream>
#include <string>
/**
 * Print my id
 * */
void PrintMyID(std::string studId) {

	std::string str = "ID: " + studId;
	std::cout << std::endl;
	std::cout << AnsiPrint(str.c_str(), YELLOW, RED, true, true) << std::endl
	          << std::endl;
}

int main() {
	// Integrate the Simple MVC Pattern to run the program.

	View view;
	Controller controller(view);
	controller.run();

	// change to your student ID.
	PrintMyID("113703052");
}
