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

#ifndef LIBBCOMPUTILS_H
#define LIBBCOMPUTILS_H
#include <cstdint>
#include <cstddef>

/*
struct byteanalyzed{
	unsigned char byte_content;
	int8_t no_occ;
};
*/

//Functions:
enum pathtype{in, out};
void displayHelp();
void checkparms(int *_argc, char *_argv[]);
void separator(int rep);
void version(const char *_progrver, int *_argc);
char* returnpath(pathtype pt);
unsigned char* loadbuffer(char *path);
void printBuffer(unsigned char* __buffer);
size_t return_buf_len();
unsigned char* bubblesort(unsigned char* _countarray);
unsigned char* countoccurences(unsigned char* __buffer);

#endif
