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
#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
#include "Utils.h"

namespace sdds {

	class Status : public Utils
	{
		char* m_desc{};
		int m_code;
		void setEmpty();

	public:
		Status();
		Status(const char* desc, int code = 0);
		void set(const char* desc, int code);
		Status(const Status& s);
		Status& operator=(const Status& s);
		Status& operator=(int code);
		Status& operator=(const char* desc);
		operator int() const;
		operator const char* () const;
		operator bool()const;
		Status& clear();
		~Status();
	};

	std::ostream& operator<<(std::ostream& ostr, const Status& s);


}

#endif // !STATUS_H_