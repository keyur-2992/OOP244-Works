/*
*****************************************************************************
						  Workshop 4 Part 1
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
#include <iomanip>
#include "CarInventory.h"

using namespace std;

namespace sdds {

	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;

	}

	CarInventory::CarInventory()
	{
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		resetInfo();
		setInfo(type, brand, model, year, code, price);
	}

	CarInventory::~CarInventory()
	{
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_type = nullptr;
		delete[] m_model;
		m_model = nullptr;

	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;

		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);

		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);

		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;

		return *this;
	}

	void CarInventory::printInfo() const
	{
		cout << "| " << setw(10) << left << m_type << " | "
			<< setw(16) << left << m_brand << " | "
			<< setw(16) << left << m_model << " | "
			<< setw(4) << right << m_year << " | "
			<< setw(4) << right << m_code << " | "
			<< setw(9) << fixed << setprecision(2) << right << m_price << " |" << endl;
	}

	bool CarInventory::isValid() const {
		if (m_type && m_brand && m_model) {
			if (m_year >= 1990) {
				if (m_code >= 100 && m_code <= 999) {
					if (m_price > 0) {
						return true;
					}
				}
			}
		}
		return false;
	}


	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		if (m_type && car.m_type && m_brand && car.m_brand && m_year == car.m_year) {
			return true;
		}
		return false;
	}
	




	int find_similar(CarInventory car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return -1;
	}

}