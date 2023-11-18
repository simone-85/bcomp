#include "utils.h"
#include <iostream>
#include <iomanip>

void displayHelp(){
	std::cout << "USAGE: bcomp -i [input_path] -o [output_path]\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "Arguments:\n";
	std::cout << std::setw(5) << "-h";
	std::cout << ": Display this help page\n";
	std::cout << std::setw(5) << "-i";
	std::cout << ": Specify path of the original file to compress\n";
	std::cout << std::setw(5) << "-o";
	std::cout << ": Specify path of the compressed file\n";
	std::cout << "---------------------------------------------\n";

}

void version(const char *_progrver, int *_argc){
	std::cout << "BComp ver " << _progrver << "\n";
	std::cout << "no. arg: " << *_argc << "\n";
}

void checkparms(int *_argc, char *_argv[]){
	std::cout << "Parsed Arguments: ";
	for(int i = 1; i < *_argc; i++){
		std::cout << i << " " << _argv[i] << std::endl;
		if(std::string(_argv[i]) == "-h"){
			std::cout << "\n";
			displayHelp();
			return;
		}else if(std::string(_argv[i]) == "-o"){
			//TODO: Add function pointer
			std::cout << "-o parsed as " << i << " parameter\n";
			return;
		}else if(std::string(_argv[i]) == "-i"){
			//TODO: Add function pointer
			std::cout << "-i parsed as " << i << " parameter\n";
			return;
		}
	}
	std::cout << "\n";
	displayHelp();
	return;
}

