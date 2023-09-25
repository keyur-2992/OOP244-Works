/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name:Keyurkumar Patel      Date: 25-SEP-2023      STU ID: 170852214
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {
    PostalCode* postalCodes = nullptr;
    int numPostalCodes = 0;

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    bool getPostalCode(char* postal_code_prefix) {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> ";
        cin >> postal_code_prefix;

        return postal_code_prefix[0] != '!';
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        if (!openFile(filename)) {
            cout << "Error: Unable to open file " << filename << endl;
            return false;
        }

        // Reset any existing data if needed

        while (true) {
            char code[7];
            int population;

            if (!read(code) || !read(population)) {
                break; // End of file or read error
            }

            // Check if partial_postal_code_prefix is nullptr (indicating no prefix provided)
            if (partial_postal_code_prefix == nullptr || strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(code, partial_postal_code_prefix)) {
                numPostalCodes++;
                // Allocate memory for a new PostalCode struct
                PostalCode* newPostalCodes = new PostalCode[numPostalCodes];

                // Copy existing data to the new array
                for (int i = 0; i < numPostalCodes - 1; i++) {
                    newPostalCodes[i] = postalCodes[i];
                }

                // Add the new record to the array
                strncpy(newPostalCodes[numPostalCodes - 1].code, code, sizeof(newPostalCodes[numPostalCodes - 1].code));
                newPostalCodes[numPostalCodes - 1].population = population;

                // Deallocate old array memory
                delete[] postalCodes;

                // Update the array pointer
                postalCodes = newPostalCodes;
            }
        }

        closeFile();
        return true;
    }

    bool load(const char* filename) {
        return load(filename, nullptr); // Call the two-argument overload with a default value for the prefix
    }

    void display() {
        
        // Sort the postalCodes array based on population using a custom sorting algorithm
        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < numPostalCodes - 1; i++) {
                if (postalCodes[i].population > postalCodes[i + 1].population) {
                    // Swap postalCodes[i] and postalCodes[i+1]
                    PostalCode temp = postalCodes[i];
                    postalCodes[i] = postalCodes[i + 1];
                    postalCodes[i + 1] = temp;
                    swapped = true;
                }
            }
        } while (swapped);

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        for (int i = 0; i < numPostalCodes; i++) {
            cout << i + 1 << "- " << postalCodes[i].code << ":  " << postalCodes[i].population << endl;
        }
        //shows the total number of the population 
        int totalPopulation = 0;
        for (int i = 0; i < numPostalCodes; i++) {
            totalPopulation += postalCodes[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalPopulation<< endl << endl;
    }

    void deallocateMemory() {
        if (postalCodes) {
            delete[] postalCodes;
            postalCodes = nullptr;
            numPostalCodes = 0;
        }
    }
}