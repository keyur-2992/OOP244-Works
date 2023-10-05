/*
*****************************************************************************
                          Workshop 4 DIY
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
#include <cstring>
#include "LabelMaker.h"

using namespace std;

namespace sdds {

    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_noOfLabels = noOfLabels;
        m_labels = new Label[noOfLabels];
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; ++i) {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            m_labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel() << endl;
        }
    }



    LabelMaker::~LabelMaker()
    {
        delete[] m_labels;
    }
}