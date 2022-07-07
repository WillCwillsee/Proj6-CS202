//#include <Car/Car.hpp>
#include "Car.hpp"

/*  This is the definition of the default constructor override for the Derived class Vehicle::Car
 */

Car::Car() : Vehicle(),  m_throttle(0)
{
    cout << endl << "Car: Default-ctor" << endl;
}

/*  This is the definition of the parameterized constructor override for the Derived class, which takes 3 parameters.  A const char pointer to the license plates, a const int of the VIN, and a const float pointer to the LLA.  It uses an initializer for the VIN because it is a const int and uses set methods for the other arguments
 */

Car::Car(const float * lla) : m_throttle(0)
{
    SetLLA(lla);
    cout << endl << "Car: Parametrized-ctor" << endl;
}

/*  This is the definition of the copy constructor override for the Derived class.  It takes one parameter, a reference to a Car object.  Since the VIN is unique, it allows the default process of VIN creation using the static int s_idgen
 */

Car::Car(const Car & c) : Vehicle(), m_throttle(0)
{
    SetLLA(c.m_lla);
    cout << endl << "Car: Copy-ctor" << endl;
}

/*  This is the definition of the default destructor override for the Derived class.
 */

Car::~Car()
{
    cout << endl << "Car: Dtor" << endl;
}

/*  This is the definition of the insertion operator override for the Derived class.  It prints all available information about the Car object reference (passed as an argument) to the terminal
 */

/*  This is the definition of the assigment operator override for the Derived class.  It essentially allows the program to copy one Car to the location of another, without chaning the VIN.
 */

void Car::operator=(const Car & c){
    drive(c.m_throttle);
    SetLLA(c.m_lla);
    cout << endl << "Vehicle: Assignment" << endl;
}

const int Car::getThrottle(){
    return m_throttle;
}

/*  This is the definiton of the Car drive method, which changes the throttle in the Car from which the method is called
 */

void Car::drive(const int throttle){
    m_throttle = throttle;
}

/*  This is the definiton of the Car move method, which changes the location (lla) in the Car from which the method is called
 */

void Car::Move(const float *lla){
    cout << "Car: DRIVE to destination with throttle @75" << endl;
    drive(75);
    for (int i = 0; i < 3; i++){
        m_lla[i] = lla[i];
    }
}

void Car::serialize(ostream & os) const {
    os << "Car: Throttle: " << m_throttle << " @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]" << endl;
}
