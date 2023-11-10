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
#include "Date.h"
using namespace std;

namespace sdds {

	bool Date::validate() {
		bool isValid = 0;

		if (m_year < 2022 || m_year > max_year){
			s = "Invalid year in date";
			s = 1;
		}
		else if (m_month < 1 || m_month > 12){
			s = "Invalid month in date";
			s = 2;
		}
		else if (m_day < 1 || m_day > Utils::daysOfMon(m_month, m_year)){
			s = "Invalid day in date";
			s = 3;
		}
		else {
			Status::clear();
			isValid = 1;		
		}

		return isValid;
	}

	int Date::uniqueDate() {
		return m_year * 372 + m_month * 31 + m_day;
	}

	Date::Date(){
		set(sdds_testYear, sdds_testMon, sdds_testDay);
		m_isFormat = 1;
	}

	Date::Date(int year, int month, int day) {
		set(year, month, day);
	}

	void Date::set(int year, int month, int day) {
		if (year != 0 && month != 0 && day != 0) {
			m_year = year;
			m_month = month;
			m_day = day;
			m_isFormat = 1;
		}
		else {
			Utils::getSystemDate(&m_year, &m_month, &m_day);
		}
	}

	Date::Date(const Date& date) {
		set(date.m_year, date.m_month, date.m_day);
	}

	Date& Date::operator=(const Date& date) {
		if (this != &date)
		{
			//shallow copy
			m_year = date.m_year;
			m_month = date.m_month;
			m_day = date.m_day;
		}
		return *this;
	}

	Date::~Date() {}

	bool Date::operator==(Date& date) {
		return (uniqueDate() == date.uniqueDate());
	}

	bool Date::operator!=(Date& date) {
		return (uniqueDate() != date.uniqueDate());
	}

	bool Date::operator<(Date& date) {
		return (uniqueDate() < date.uniqueDate());
	}

	bool Date::operator>(Date& date) {
		return (uniqueDate() > date.uniqueDate());
	}

	bool Date::operator<=(Date& date) {
		return (uniqueDate() <= date.uniqueDate());
	}

	bool Date::operator>=(Date& date) {
		return (uniqueDate() >= date.uniqueDate());
	}

	const Date::Status& Date::state() {
		return s;
	}

	Date& Date::formatted(bool flag) {
		m_isFormat = flag;
		return *this;
	}

	Date::operator bool()const {
		return (s);
	}

	ostream& Date::write(ostream& ostr) const {

		if (m_isFormat){
			ostr << m_year << "/" << setfill('0') << setw(2) << m_month << "/" << setfill('0') << setw(2) << this->m_day;
		}
		else { 
			ostr << m_year - (m_year / 100) * 100 << setfill('0') << setw(2) << m_month << setfill('0') << setw(2) << m_day; 
		}

		return ostr;
	}


	istream& Date::read(istream& istr) {

		int date, year, mon, day;
		cin >> date;

		if (!date){
			s = "Invalid date value";
			s = 0;
			istr.setstate(ios::badbit);
		}
		else if (date > 9 && date < 100) {
			s = "Invalid month in date";
			s = 2;
			istr.setstate(ios::badbit);
		}
		else if (date > 999 && date < 10000){
			mon = date / 100;
			day = date - mon * 100;
			set(2023, mon, day);
			if (!validate()) istr.setstate(ios::badbit);
		}
		else if (date > 99999 && date < 1000000){
			year = date / 10000;
			mon = (date - year * 10000) / 100;
			day = date - year * 10000 - mon * 100;
			set(year + 2000, mon, day);
			if (!validate())istr.setstate(ios::badbit);
		}
		else{
			istr.setstate(ios::badbit);
		}

		return istr;
	}

	istream& operator>>(istream& istr, Date& date) {
		return date.read(istr);
	}

	ostream& operator<<(ostream& ostr, const Date& date) {
		return date.write(ostr);
	}
}