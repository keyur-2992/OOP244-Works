/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name: Keyurkumar Patel           Date 22-SEP-2023        STU ID# 170852214
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   //TODO: read functions go here    
   // Reads the name of the employee | Accepts as a parameter the address of an array of characters
   bool read(char* empName) {
       if (fscanf(fptr, "%127[^\n]\n", empName) == 1) {
           return true;
       }
       return false;
   }

   // Reads employee number | Accepts as a parameter a reference to an integer
   bool read(int& empNumber) {
       if (fscanf(fptr, "%d,", &empNumber) == 1) {
           return true;
       }
       return false;
   }
   
   // Reads the employee salary | Acceptes as a parameter a reference to an floating point number
   // in double precision
   bool read(double& empSalary) {
       if (fscanf(fptr, "%lf,", &empSalary) == 1) {
           return true;
       }
       return false;
   }
   
}