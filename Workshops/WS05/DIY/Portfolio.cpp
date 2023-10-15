/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    bool Portfolio::isVaild() const {
        return (operator bool() && m_value > 0);
    }

    Portfolio::operator bool() const {
        
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }


    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio& Portfolio::operator+=(double value) {
        if (isVaild()) m_value += value;
        return *this;
    }

    Portfolio& Portfolio::operator-=(double value) {
        if (isVaild()) m_value -= value;
        return *this;
    }

    bool Portfolio::operator~() const {
        return (m_value < 0);
    }

    Portfolio& Portfolio::operator<<(Portfolio& right) {
        if (isVaild() && right.isVaild()) {
            m_value += right.m_value;
            right.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& right) {
        if (isVaild() && right.isVaild()) {
            right.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    double operator+(Portfolio& left, Portfolio& right) {
        double sum = 0;
        if (left.isVaild() && right.isVaild()) {
            sum = left.operator double() + right.operator double();
        }
        return sum;
    }

    double operator+=(double& left, Portfolio& right) {

        left += right.operator double();

        return left;
    }

    //



}