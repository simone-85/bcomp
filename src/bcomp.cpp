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
#include <iomanip>
#include "utils/libbcomputils.h"

const char* progrver = "0.1a";

//ANALYZER PART:

struct byteanalyzed{
	unsigned char byte_content;
	int8_t no_occ;
};

int main(int argc, char *argv[]){
	version(progrver, &argc);
	checkparms(&argc, argv);
	//until here, all good :-)
	std::cout << "inpath: " << returnpath(in) << "\n";
//std::cout << "outpath: " << returnpath(out) << "\n";
	unsigned char* buffer = loadbuffer(returnpath(in));
	printBuffer(buffer);
	countoccurences(buffer);
	
}
