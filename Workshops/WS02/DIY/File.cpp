/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:Keyurkumar Patel      Date: 25-SEP-2023      STU ID: 170852214
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO : implement the read fuction
   bool read(char* code) {
       if (fscanf(fptr, "%[^,],", code) == 1) {
           return true;
       }
       return false;
   }
   bool read(int& population) {
       if (fscanf(fptr, "%d\n", &population) == 1) {
           return true;
       }
       return false;
   }
}