/*
*****************************************************************************
                          Workshop 1 DIY
Full Name  : keyurkumar shankarlal patel
Student ID#: 170852214
Email      : kpatel453@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cStrTools.h"

using namespace std;
namespace sdds {

    // Function to search for partial names and display matching records
    void searchAndDisplay(FILE* file, const char* partialName) {
        bool found = false;
        char name[51], areaCode[4], prefix[4], number[5];

        // Convert the partialName to lowercase for case-insensitive search
        char lowerPartialName[51];
        for (int i = 0; partialName[i] != '\0'; i++) {
            lowerPartialName[i] = toLower(partialName[i]);
        }
        lowerPartialName[strlen(partialName)] = '\0';

        while (fscanf(file, "%50[^\t]\t%3s\t%3s\t%4s\n", name, areaCode, prefix, number) == 4) {
            // Convert the name to lowercase for case-insensitive search
            char lowerName[51];
            for (int i = 0; name[i] != '\0'; i++) {
                lowerName[i] = toLower(name[i]);
            }
            lowerName[strlen(name)] = '\0';

            if (strstr(lowerName, lowerPartialName) != nullptr) {
                cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
                found = true;
            }
        }
        /*
        //display a message if No record match found
        if (!found) {
            cout << "No match is found." << endl;
        }
        */

        fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
    }

    // Function to run the phone directory application
    void phoneDir(const char* programTitle, const char* fileName) {
        cout << programTitle<<" phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");
        if (!file) {
             cout<<fileName<<" file not found!" << endl;
             cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        char partialName[51];  // 50 characters for the name + null terminator
        bool exitLoop = false; // For breaking the Loop 
        while (!exitLoop) {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin >> partialName;

            if (strcmp(partialName, "!") == 0) {
                exitLoop = true;
            }
            else {
                searchAndDisplay(file, partialName);
            }
        }

        fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
};