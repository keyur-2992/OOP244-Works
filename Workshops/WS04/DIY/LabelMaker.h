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
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include"Label.h"

namespace sdds {
    class LabelMaker {
        Label* m_labels;
        int m_noOfLabels;
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}
#endif // !SDDS_LABELMAKER_H
