#include <iostream>
#include <string>
#include "Car.h"


    Car::Car(const std::string& model, int year) {
        m_model = model;
        m_year = year;
    }
    Car::Car(){
        m_model="who?";
        m_year=0;
    }
    Car::Car(const Car& other) {
        m_model = other.m_model;
        m_year = other.m_year;
    }
    Car& Car::operator=(const Car& other) {
        if (this != &other) {
            m_model = other.m_model;
            m_year = other.m_year;
        }
        return *this;
    }
    
    Car::~Car() {}
    
    std::string Car::getModel() {
        return m_model;
    }
    
    int Car::getYear() {
        return m_year;
    }

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << car.m_model;
    return os;
}

