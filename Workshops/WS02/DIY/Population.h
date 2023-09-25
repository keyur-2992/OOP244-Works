/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:Keyurkumar Patel      Date: 25-SEP-2023      STU ID: 170852214
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct PostalCode {
        char code[7];
        int population;
    };

   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);
   // Function to get a partial postal code from the user
   bool getPostalCode(char* postal_code_prefix);
   // Function to load population data from a file with only the filename
   bool load(const char* filename);
   // Function to load population data from a file with both filename and partial postal code prefix
   bool load(const char* filename, const char* partial_postal_code_prefix);
   // Function to display the population report
   void display();
   // Function to deallocate memory
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_