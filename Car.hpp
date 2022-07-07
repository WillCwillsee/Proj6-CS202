
#ifndef Car_hpp
#define Car_hpp
//#include <Vehicle/Vehicle.hpp>
#include "Vehicle.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*  This is the declaration of the Derived class Car belonging to the Base class Vehicle.  More information about all the members and methods of this class can be found in Car.cpp
 */

class Car : public Vehicle{
    
public:
    Car();
    Car(const float * lla);
    Car(const Car & c);
    ~Car();
    
    void operator=(const Car & c);
    
    const int getThrottle();
    void drive(const int throttle);
    virtual void Move(const float *lla);
    
private:
    virtual void serialize(ostream & os) const;
    int m_throttle;
    
};

#endif /* Car_hpp */
