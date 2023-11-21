/*
 * Library BComp Utils
 *
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

#include "libbcomputils.h"
#include <iostream>
#include <fstream>
#include <iomanip>

char *inpath;
char *outpath;
size_t buf_len;

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
	std::cout << std::setw(5) << "-W";
	std::cout << ": Display WARRANTY Notice\n";
	std::cout << "---------------------------------------------\n";

}

void version(const char *_progrver, int *_argc){
	std::cout << "BComp ver " << _progrver << " Copyright (C) 2023 Simone Mastroianni\n";
	std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `-W'.\n";
	std::cout << "\n";

}

char* returnpath(pathtype pt){
	if(pt == in){
		return inpath;
	}else{
		return outpath;
	}
}

void checkparms(int *_argc, char *_argv[]){
	//particular cases:
	if(*_argc == 1){
		std::cout << "No parameters parsed\n";
		displayHelp();
		return;
	}
	for(int i = 1; i < *_argc; i++){
		if(std::string(_argv[i]) == "-h"){
			//-h parsed:
			std::cout << "\n";
			displayHelp();
			return;
		}else if(std::string(_argv[i]) == "-o"){
			//-o parsed:
			if(std::string(_argv[i+1]).substr(0,1) == "-"){
				std::cerr << "[-o]: Cannot parse this path: " << std::string(_argv[i+1]) << "\n"; 
				return;
			}else{
				outpath = _argv[i+1];
			}
		}else if(std::string(_argv[i]) == "-i"){
			//-i parsed:
			if(std::string(_argv[i+1]).substr(0,1) == "-"){
				std::cerr << "[-i]: Cannot parse this path: " << std::string(_argv[i+1]) << "\n";
				return;	
			}else{
				inpath = _argv[i+1];
			}
		}else if(std::string(_argv[i]) == "-W"){
			//-W parsed:
			std::cout << "WARRANTY NOTICE: \n";
			std::cout << std::setw(10) << "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n";
			return;
		}
	}
	std::cout << "\n";
}
size_t return_buf_len(){
	return buf_len;
}
void printBuffer(unsigned char* __buffer){
	std::cout << "BUFFER LENGTH: " << buf_len << " BYTES \nCONTENT:\n";
	for(int i = 0; i < buf_len; i++){
		std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(__buffer[i]) << " ";
	}
	std::cout << "\n";
	return;
}

size_t countoccurences(unsigned char* __buffer){
	size_t count = 0;
	for(size_t i = 0; i < 256; i++){
		for(size_t j = 0; j < buf_len; j++){
			//std::cout << std::hex << std::setw(2) << std::setfill('0')<< static_cast<int>(__buffer[j]);
		       	//std::cout << ", " << std::hex << i << "\n";
			if(__buffer[j] == i){
				count++;
			}	
		}
		if(count != 0){
		std::cout << std::hex << std::setw(2) << i << " is repeated: " << std::dec << count << "\n"; 
		}
		//std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(__buffer[i]);
		//std::cout << " is repeated: " << std::dec << count << "\n";	
		count = 0;
}
return count;
}

unsigned char* loadbuffer(char* path){
	std::ifstream in(path, std::ios::binary);
	if (!in.is_open()){
		std::cerr << "Error opening the file. Maybe " << path << " is wrong?\n";
		return 00;
	}
	in.seekg(0, std::ios::end);
	buf_len = in.tellg();
	in.seekg(0, std::ios::beg);
	unsigned char* _buffer = new unsigned char[buf_len];
	in.read(reinterpret_cast<char*>(_buffer), buf_len);	
	std::cout << "\n";
	return _buffer;	
}
