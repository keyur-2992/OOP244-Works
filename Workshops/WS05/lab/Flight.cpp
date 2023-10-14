/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name keyurkumar Patel  Date 10-OCT-2023  STU ID 170852214
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 && fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        if (m_passengers > 0 && m_fuel >= 600 * m_passengers) {
            return true;
        }
        return false;
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator ~() const {
        return (m_passengers == 0);
    }

    Flight& Flight::operator=(Flight& first) {
        m_passengers += first.m_passengers;
        m_fuel += first.m_fuel;
        strcpy(m_title, first.m_title);
        first.emptyPlane();

        return *this;
    }

    Flight& Flight::operator=(int passenger) {
        if (passenger > 0 && passenger <= Boen747Capacity) m_passengers = passenger;
        return *this;
    }

    Flight& Flight::operator=(double fuel) {
        if (fuel > 0 && fuel <= FuelTankCapacity) m_fuel = fuel;
        return *this;
    }

    Flight& Flight::operator+=(double fuel) {

        if (fuel > 0 && m_fuel < FuelTankCapacity) m_fuel += fuel;
        return *this;
    }

    Flight& Flight::operator+=(int passenger) {
        if (passenger > 0 && m_passengers < Boen747Capacity) m_passengers += passenger;
        return *this;
    }

    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0 && m_fuel > 0) m_fuel -= fuel;
        return *this;
    }

    Flight& Flight::operator-=(int passenger) {
        if (passenger > 0 && m_passengers > 0) m_passengers -= passenger;
        return *this;
    }

    Flight& Flight::operator>>(Flight& right) {
        int movePassenger = m_passengers + right.m_passengers;
        int remianPassenger = 0;

        if (right.operator bool() && operator bool())
        {
            if (movePassenger > Boen747Capacity)
            {
                remianPassenger = movePassenger - Boen747Capacity;
                right.m_passengers = Boen747Capacity;
                m_passengers = remianPassenger;
            }
            else
            {
                right.m_passengers = movePassenger;
                m_passengers = 0;
            }

        }

        return *this;
    }

    Flight& Flight::operator<<(Flight& left) {
        int movePassenger = m_passengers + left.m_passengers;
        int remianPassenger = 0;

        if (left.operator bool() && operator bool())
        {
            if (movePassenger > Boen747Capacity)
            {
                remianPassenger = movePassenger - Boen747Capacity;
                left.m_passengers = Boen747Capacity;
                m_passengers = remianPassenger;
            }
            else
            {
                left.m_passengers = movePassenger;
                m_passengers = 0;
            }

        }

        return *this;
    }

    int operator+ (Flight& left, Flight& right) {
        int sum = 0;
        if (left.operator bool() && right.operator bool()) {
            sum = left.operator int() + right.operator int();
        }
        else
        {
            sum = 0;
        }

        return sum;
    }

    int operator+=(int& left, Flight& right) {
        left += right.operator int();

        return left;
    }
}