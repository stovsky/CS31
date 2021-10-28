#include <iostream>
#include <string>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    
    // Initialize values and check ignore/set equal to -1 if they are invalid
    if (passengerName != "") mName = passengerName;
    
    if (fromCity != toCity) {
        if (fromCity != "") mFromCity = fromCity;
        if (toCity != "") mToCity = toCity;
    }
        
    if (cost < 0) mCost = -1;
    else mCost = cost;
    
    if (mileage <= 0) mMileage = -1;
    else mMileage = mileage;
}

double PlaneFlight::getCost() {
    return mCost;
}

void PlaneFlight::setCost(double cost) {
    
    // Cost is invalid if it is less than zero
    if (cost < 0) mCost = -1;
    else mCost = cost;
}

double PlaneFlight::getMileage() {
    return mMileage;
}
void PlaneFlight::setMileage(double mileage) {
    
    // Mileage is invalid if it is less than or equal to zero
    if (mileage <= 0) mMileage = -1;
    else mMileage = mileage;
}

string PlaneFlight::getName() {
    return mName;
}
void PlaneFlight::setName(string name) {
    
    // Ignore if name is the empty string
    if (name != "") mName = name;
}

string PlaneFlight::getFromCity() {
    return mFromCity;
}
void PlaneFlight::setFromCity(string from) {
    
    // Ignore if from is the empty string or equal to toCity
    if (from != "" && from != mToCity) mFromCity = from;
}

string PlaneFlight::getToCity() {
    return mToCity;
}
void PlaneFlight::setToCity(string to) {
    
    // Ignore if to is the empty string or equal to fromCity
    if (to != "" && to != mFromCity) mToCity = to;
}
