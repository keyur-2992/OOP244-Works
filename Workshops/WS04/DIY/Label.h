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
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {
    class Label {
        char* m_frame;
        char* m_content;
        void readframe(const char* frame);
        void copyContent(const char* content);
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void text(const char* content);
        void readLabel();
        std::ostream& printLabel()const;
    };
}
#endif // !SDDS_LABEL_H
