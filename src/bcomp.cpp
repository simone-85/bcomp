/*
 * BComp, a general purpose file compressor
 * Copyright (C) 2023 Simone Mastroianni
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>
#include <iomanip>
#include "utils/utils.h"

const char* progrver = "0.1a";

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
