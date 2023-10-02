/*
*****************************************************************************
                          Workshop 3 part 2
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
#include "Train.h"

using namespace std;


namespace sdds {

    const int MIN_TIME = 700;
    const int MAX_TIME = 2300;
    const int MAX_NO_OF_PASSENGERS = 1000;

    Train::Train() {
        initialize();
    }

    Train::Train(const char* name, int noOfPassengers, int departure) {
        initialize();
        set(name, noOfPassengers, departure);
    }

    Train::~Train() {
        finalize();
    }


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
        if (m_trainName != nullptr) {
            delete[] m_trainName;
            m_trainName = nullptr;
        }

        if (name != nullptr && name[0] != '\0') {
            m_trainName = new char[strlen(name) + 1];
            strcpy(m_trainName, name);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            m_noPeople = noOfPassengers;
            m_departureTime = departure;
        }
        else {
            m_noPeople = -1;
            m_departureTime = -1;
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        if (m_trainName != nullptr) {
            delete[] m_trainName;
            m_trainName = nullptr;
        }
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

    // for part 2
    bool Train::load(int& unboardedPassengers) {
        cout << "Enter number of passengers boarding:" << endl;
        int passengers;
        cin >> passengers;

        int totalPassengers = m_noPeople + passengers;
        if (totalPassengers <= MAX_NO_OF_PASSENGERS) {
            m_noPeople = totalPassengers;
            unboardedPassengers = 0;
            return true;
        }
        else {
            unboardedPassengers = totalPassengers - MAX_NO_OF_PASSENGERS;
            m_noPeople = MAX_NO_OF_PASSENGERS;
            return false;
        }
    }



    bool Train::updateDepartureTime() {
        cout << "Enter new departure time:" << endl;
        int newDepartureTime;
        cin >> newDepartureTime;

        if (validTime(newDepartureTime)) {
            m_departureTime = newDepartureTime;
            return true;
        }
        else {
            m_departureTime = -1;
            return false;
        }
    }

    bool Train::transfer(const Train& otherTrain) {
        // Check if both trains are in a valid state
        if (isInvalid() || otherTrain.isInvalid()) {
            //cout << "Transfer Failed!" << endl;
            return false;
        }

        // Combine the names of the two trains
        string combinedName = string(getName()) + ", " + otherTrain.getName();

        // Calculate the total number of passengers
        int totalPassengers = m_noPeople + otherTrain.m_noPeople;

        // Check if the total number of passengers exceeds the maximum allowed
        if (totalPassengers <= MAX_NO_OF_PASSENGERS) {
            // Transfer successful, update the current train's information
            set(combinedName.c_str(), totalPassengers, m_departureTime);
            return true;
        }
        else {
            // Calculate the number of unboarded passengers
            int unboardedPassengers = totalPassengers - MAX_NO_OF_PASSENGERS;

            // Transfer failed, print the number of unboarded passengers and the combined name
            cout << "Train is full; " << unboardedPassengers << " passengers of " << otherTrain.getName() << " could not be boarded!" << endl;
            totalPassengers = MAX_NO_OF_PASSENGERS;
            set(combinedName.c_str(), totalPassengers, m_departureTime);
            return true;
        }
    }


}
