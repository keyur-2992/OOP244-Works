/*
*****************************************************************************
						  Milestone 1 
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
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Status.h"
using namespace std;

namespace sdds {
	void Status::setEmpty() {
		m_desc = nullptr;
		m_code = 0;
	}

	Status::Status()
	{
		setEmpty();
	}

	Status::Status(const char* desc, int code)
	{
		if (desc != nullptr)
		{
			setEmpty();
			set(desc, code);
		}
		else setEmpty();
	}

	void Status::set(const char* desc, int code) {
		delete[] m_desc;
		//if(desc != nullptr)
		if (desc != nullptr)
		{
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
			m_code = code;

		}
		else { 
			setEmpty();
		}
		
	}

	Status::Status(const Status& s) {
		setEmpty();
		set(s.m_desc, s.m_code);
	}

	Status& Status::operator=(const Status& s) {
		if (&s != this) set(s.m_desc, s.m_code);
		return *this;
	}

	Status::~Status()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}

	Status& Status::operator=(int code) {
		m_code = code;
		return *this;
	}

	Status& Status::operator=(const char* desc) {
		delete[] m_desc;
		if (desc != nullptr) {

			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
		}
		else {
			delete[] m_desc;
			m_desc = nullptr;
		}
		return *this;
	}

	Status::operator int() const {
		return m_code;
	}

	Status::operator const char* () const {
		return m_desc;
	}

	Status::operator bool()const {
		return (m_desc == nullptr) ? true : false;
	}

	Status& Status::clear() {
		delete[] m_desc;
		m_desc = nullptr;
		m_code = 0;

		return *this;
	}

	ostream& operator<<(std::ostream& ostr, const Status& s) {
		int code = s.operator int();

		if (!s)
		{
			if (code != 0) ostr << "ERR#" << code << ": ";
			ostr << s.operator const char* ();
		}
		return ostr;
	}
}