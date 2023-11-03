/*
*****************************************************************************
                          workshop 6 Lab
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
#include "HealthCard.h"
using namespace std;
namespace sdds {

    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        if (name != nullptr && strlen(name) > 0 && strlen(name) < MaxNameLength &&number > 999999999 && number < 9999999999 &&strlen(vCode) == 2 && strlen(sNumber) == 9) {
            return true;
        }
        return false;
    }

    void HealthCard::setEmpty() {
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }

    void HealthCard::allocateAndCopy(const char* name) {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void HealthCard::extractChar(istream& istr, char ch) const {

        if (istr.peek() == ch){
            istr.ignore();
        }
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    ostream& HealthCard::printIDInfo(ostream& ostr) const {

        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else
        {
            delete[] m_name;
            setEmpty();
        }
    }

    //public method TODO

    HealthCard::HealthCard() {
        setEmpty();
    }

    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber)) {
            set(name, number, vCode, sNumber);
        }
        else
        {
            setEmpty();
        }
    }

    HealthCard::HealthCard(const HealthCard& hc) {

        if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
    }

    HealthCard& HealthCard::operator=(const HealthCard& hc) {

        if (&hc != this) set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        return *this;
    }

    HealthCard::~HealthCard() {
        delete[] m_name;
        m_name = nullptr;
    }

    HealthCard::operator bool() const {
        if (validID(m_name, m_number, m_vCode, m_sNumber)) {
            return true;
        }
        return  false;
    }

    ostream& HealthCard::print(ostream& ostr, bool toFile) const {

        if (toFile && operator bool())
        {
            ostr << m_name << ',';
            printIDInfo(ostr) << endl;
        }
        else if (this->operator bool())
        {
            ostr << left << setw(50) << setfill('.') << m_name;
            printIDInfo(ostr);
        }
        return ostr;
    }

    istream& HealthCard::read(istream& istr) {
        char* name = new char[100];
        long long number;
        char vCode[3];
        char sNumber[10];

        istr.get(name, 100, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');

        if (!istr.fail()) {
            set(name, number, vCode, sNumber);
        }
        else istr.clear(), istr.ignore(1000, '\n');

        delete[] name;

        return istr;
    }

    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }

    istream& operator>>(istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }
}
