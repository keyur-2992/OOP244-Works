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
#include <iomanip>
#include <cstring>
#include "Label.h"
#define MAXSIZE 70
using namespace std;

namespace sdds {

	Label::Label() {
		m_content = nullptr;
		m_frame = new char[9];
		strcpy(m_frame, "+-+|+-+|");
	}

	Label::Label(const char* framArg) {

		m_content = nullptr;
		readframe(framArg);
	}

	Label::Label(const char* frameArg, const char* content)
	{
		readframe(frameArg);
		copyContent(content);
	}

	void Label::readLabel()
	{
		m_content = new char[MAXSIZE + 1];
		cin.getline(m_content, MAXSIZE + 1);
	}

	void Label::readframe(const char* frame)
	{
		if (frame != nullptr)
		{
            m_frame = new char[strlen(frame) + 1];
            strcpy(m_frame,frame);
		}
	}

    void Label::copyContent(const char* content)
    {
        if (content != nullptr)
        {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
    }

    void Label::text(const char* content) {
        copyContent(content);
    }

    std::ostream& Label::printLabel() const
    {
        if (m_content != nullptr && strlen(m_content) > 0)
        {
            cout << m_frame[0];
            for (unsigned int i = 0; i < strlen(m_content) + 2; i++)
            {
                cout << m_frame[1];
            }
            cout << m_frame[2] << endl;
            cout << m_frame[7];
            for (int i = 0; m_content[i]; i++)
            {
                cout << " ";
            }
            cout << "  ";
            cout << m_frame[3] << endl;

            cout << m_frame[7];
            cout << " " << m_content << " ";
            cout << m_frame[3] << endl;

            cout << m_frame[7];
            for (int i = 0; m_content[i]; i++)
            {
                cout << " ";
            }
            cout << "  ";
            cout << m_frame[3] << endl;

            cout << m_frame[6];
            for (unsigned int i = 0; i < strlen(m_content) + 2; i++)
            {
                cout << m_frame[5];
            }
            cout << m_frame[4];
        }
        return cout;
    }

    Label::~Label()
    {
        delete[] m_frame;
        delete[] m_content;
    }
}