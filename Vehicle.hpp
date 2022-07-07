#ifndef Vehicle_hpp
#define Vehicle_hpp
#include <iostream>
#include <fstream>

using namespace std;

/*  This is the declaration of the Base class Vehicle.  More information about all the members and methods of this class can be found in Vehicle.cpp
 */

class Vehicle{
    
public:
    
    Vehicle();
    Vehicle(const float * lla);
    Vehicle(const Vehicle & vehicle);
    ~Vehicle();
    
    friend ostream & operator<<(ostream & os, const Vehicle & v);
    void operator=(const Vehicle & v);
    
    const float * getLLA() const;
    void SetLLA(const float * lla);
    virtual void Move(const float * lla) = 0;
    
    static int getIdgen();
    
protected:
    
    float m_lla[3];
    
private:
    
    virtual void serialize(ostream & os) const;
    
};


#endif /* Vehicle_hpp */
