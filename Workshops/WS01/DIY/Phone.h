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
#ifndef SDDS_PHONE_H 
#define SDDS_PHONE_H
#include <cstdio>

namespace sdds {
	//globalizing FILE pointer
	extern FILE* file;
	
	// Function to search for partial names and display matching records
	void searchAndDisplay(FILE* file, const char* partialName);
	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName);
	
	
}
#endif