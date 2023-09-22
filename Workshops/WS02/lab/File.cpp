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
// Name            Date            Reason
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
   /* TODO: read functions go here    
   bool read(................) {
      return .....
   }*/
   bool read(FILE* fptr, char*& empName) {
       char temp[128];

       if (fptr != nullptr && empName != nullptr) {
           if (fscanf(fptr, "%127[^\n]\n", temp) == 1) {
               temp[127] = '\0';
               empName = new char[strlen(temp) + 1];

               if (empName != nullptr) {
                   strcpy(empName, temp);
                   return true;
               }
               else {
                   return false;
               }
           }
       }
       return false;
   }
   /*
   bool read(................) {
      return .....
   }*/
   
   bool read(FILE* fptr, int& empNo) {
       int temp;
       if (fscanf(fptr, "%d", &temp) == 1) {
           return true;
       }
       return false;
   }
   /*
   bool read(................) {
      return .....
   }
   */
   bool read(FILE* fptr, double& empSal) {
       double temp;
       if (fscanf(fptr, "%lf", &temp) == 1) {
           return true;
       }
       return false;
   }

}