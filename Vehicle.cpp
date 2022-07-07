//#include <Vehicle/Vehicle.hpp>
#include "Vehicle.hpp"

/*  This is the definition of the default Vehicle constructor, which takes no parameters, and only creates a unique VIN for the Vehicle
 */

Vehicle::Vehicle() : m_lla()
{
    cout << endl << "Vehicle: Default-ctor" << endl;
}


/*  This is the definition of the second parameterized constructor which takes two parameters.  It takes a const int for the VIN creation and a const float pointer for the lla
 */

Vehicle::Vehicle( const float * lla) : m_lla()
{
    SetLLA(lla);
    cout << endl << "Vehicle: Parametrized-ctor" << endl;
}

/*  This is the definition of the copy constructor which takes one parameter, a Vehicle object reference.  It copies all available information to a newly constructed Vehicle object
 */

Vehicle::Vehicle(const Vehicle & v) : m_lla()
{
    SetLLA(v.m_lla);
    cout << endl << "Vehicle: Copy-ctor" << endl;
}

/*  This is the definition of the default destructor.
 */

Vehicle::~Vehicle()
{
    cout << endl << "Vehicle: dtor" << endl;
}

/*  This is the definiton of the insertion operator.  It prints all available information in a Vehicle object reference to the terminal
 */

void Vehicle::serialize(ostream & os) const {
    os << "Vehicle @ " << "[" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]";
}

ostream & operator<<(ostream & os, const Vehicle & v){
    v.serialize(os);
    return os;
}

/*  This is the definition of the assigment operator.  It essentially copies the members of a preexsting Vehicle object reference into another Vehicle object
 */

void Vehicle::operator=(const Vehicle & v){
    SetLLA(v.m_lla);
    cout << endl << "Vehicle: Assignment" << endl;
}

/*  This is the definition of the get method for the m_lla member.  It returns the value of m_lla
 */

const float * Vehicle::getLLA() const{
    return m_lla;
}

/*  This is the definition of the set method for the m_lla member.  It takes one parameter, a const float pointer and uses that to set the value of m_lla
 */

void Vehicle::SetLLA(const float * lla){
    for (int i = 0; i < 3; i++){
        m_lla[i] = lla[i];
    }
}

/*  This is the definiton of the move method.  It is intended to be used only for an object of the Derived class Vehicle in order to change its location (stored in m_lla)
 */

void Vehicle::Move(const float * lla){
    cout << endl << "Vehicle: CANNOT MOVE - I DON'T KNOW HOW" << endl;
}



