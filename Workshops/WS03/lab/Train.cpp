#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds {
    const int MIN_TIME = 700;
    const int MAX_TIME = 2300;
    const int MAX_NO_OF_PASSENGERS = 1000;

    void Train::initialize() {
        m_trainName = nullptr;
        m_noPeople = -1;
        m_departureTime = -1;
    }

    bool Train::validTime(int value) const {
        if (value >= MIN_TIME && value <= MAX_TIME && (value % 100) <= 59) {
            return true;
        }
        return false;
    }

    bool Train::validNoOfPassengers(int value) const {
        if (value <= MAX_NO_OF_PASSENGERS && value >= 0) {
            return true;
       }
        return false;
    }

    void Train::set(const char* name) {
        delete[] m_trainName;
        if (name != nullptr && name[0] != '\0') {
            m_trainName = new char[strlen(name) + 1];
            strcpy(m_trainName, name);
        }
        else {
            m_trainName = nullptr;
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            m_noPeople = noOfPassengers;
            m_departureTime = departure;
        }
        else {
            initialize();
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete[] m_trainName;
        initialize();
    }

    bool Train::isInvalid() const {
        return (m_trainName == nullptr || m_noPeople < 0 || m_departureTime < 0);
    }

    int Train::noOfPassengers() const {
        return m_noPeople;
    }

    const char* Train::getName() const {
        return m_trainName;
    }

    int Train::getDepartureTime() const {
        return m_departureTime;
    }

    void Train::display() const {
        if (isInvalid()) {
            cout << "Train in an invalid State!" << std::endl;
        }
        else {
            cout << "NAME OF THE TRAIN:    " << getName() << endl;
            cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << endl;
            cout << "DEPARTURE TIME:       " << getDepartureTime() << endl;
        }
    }
}
