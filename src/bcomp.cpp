#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>
#include <iomanip>
#include "utils/utils.h"

//BComp, a general purpose file compressor
//Author: Simone Mastroianni
//Released under GNU General Public License v3.0
//for more details, read LICENSE

const char* progrver = "0.1a";
const char* author = "Simone Mastroianni";

//ANALYZER PART:
struct byteanalyzed{
	unsigned char byte_content;
	int8_t no_occ;
};

unsigned char* loadbuffer(char* path){
	std::ifstream in(path, std::ios::binary);
	if (!in.is_open()) {
		std::cerr << "Error opening the file." << std::endl;
		return reinterpret_cast<unsigned char*>(1);
	}
	in.seekg(0, std::ios::end);
	size_t len = in.tellg();
	in.seekg(0, std::ios::beg);
	std::cout << "len:" << len << "\n";
	unsigned char* buffer = new unsigned char[len];
	in.read(reinterpret_cast<char*>(buffer), len);	
	return buffer;		
}

int main(int argc, char *argv[]){
	version(progrver, &argc);
	checkparms(&argc, argv);
	/*
	   for(int i = 0; i < len; i++){
	   std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer[i]) << " ";
	   }
	   std::cout << "\n";
	   */
}
