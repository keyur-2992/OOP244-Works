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
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include "Status.h"

namespace sdds {
	class Date : public Status
	{
		const int max_year = 2030;
		int m_year;
		int m_month;
		int m_day;
		bool m_isFormat;
		Status s;
		bool validate();
		int uniqueDate();

	public:
		Date();
		Date(int year, int month, int day);
		void set(int year, int month, int day);
		Date(const Date& date);
		Date& operator=(const Date& date);
		~Date();
		bool operator==(Date& date);
		bool operator!=(Date& date);
		bool operator<(Date& date);
		bool operator>(Date& date);
		bool operator<=(Date& date);
		bool operator>=(Date& date);
		const Date::Status& state();
		Date& formatted(bool flag);
		operator bool()const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::istream& operator>>(std::istream& istr, Date& date);
	std::ostream& operator<<(std::ostream& ostr, const Date& date);


}

#endif // !DATE_H_
