///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |  Classes and Objects Review    *      Employee Class Definitions      *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

    Contains the class Employee Definitions

    The class creates employee objects with the arguments
         (private) id, first and last name, pay rate, and pay
         (static) number of employees and base pay

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Employee.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------- Class Employee ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Static variables initialization (private)
//----------------------------------------------------------------------------------

unsigned Employee::numEmployees = 0; // Initializes static Employee id
unsigned Employee::basePay = 15000; // Initializes static base pay

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Constructors
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Default constructor
/*---------------------------------------------------

    Default construtor 

 ----------------------------------------------------*/
Employee::Employee()
{
    // Name
    firstName = " ",
    lastName = " ";
    numEmployees++; // Number of employees
    id = numEmployees; // Employee's ID number
    payRate = 0.00;  // Employee's pay rate
    pay = 0.00; // Employee's pay
}

//--------------------------------------------------------------------- Constructor-1
/*---------------------------------------------------

     constructor-1

 ----------------------------------------------------*/
Employee::Employee(string firstName, string lastName, double payRate)
{
    // Name
    this->firstName = firstName,
    this->lastName = lastName;
    numEmployees++; // Number of employees
    id = numEmployees; // Employee's ID number
    this->payRate = payRate; // Employee's pay rate
    pay = (1 + payRate) * basePay; // Employee's pay
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Accessors Methods
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method getFirstName()
/*----------------------------------------------------

      Returns the employee's first name

 -----------------------------------------------------*/
string Employee::getFirstName() 
{
    return firstName;
}

//--------------------------------------------------------------------- Method getLastName()
/*----------------------------------------------------

      Returns the employee's first name

 -----------------------------------------------------*/
string Employee::getLastName()
{
    return lastName;
}

//--------------------------------------------------------------------- Method getId()
/*----------------------------------------------------

      Returns the employee's ID

 -----------------------------------------------------*/
unsigned Employee::getId()
{
    return id;
}

//--------------------------------------------------------------------- Method getPayRate()
/*----------------------------------------------------

      Returns the employee's pay rate

 -----------------------------------------------------*/
double Employee::getPayRate()
{
    return payRate;
}

//--------------------------------------------------------------------- Method getPay()
/*----------------------------------------------------

      Returns employee's pay

 -----------------------------------------------------*/
double Employee::getPay()
{
    // Recalculates pay, in case the (static) employees' base pay was modified
    pay = (1 + payRate) * basePay;
    return round(pay * 100.0) / 100.0; // Rounds to nearest one-hundreth, pay is in $ and cents
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Static accessors methods 
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method getBasePay()
/*----------------------------------------------------

      Returns base pay

 -----------------------------------------------------*/
unsigned Employee::getBasePay()
{
    return basePay;
}

//--------------------------------------------------------------------- Method getNumEmployees()
/*----------------------------------------------------

      Returns the number of employees

 -----------------------------------------------------*/
unsigned Employee::getNumEmployees()
{
    return basePay;
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Mutators Methods
//---------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method setFirstName()
/*----------------------------------------------------

      Sets the employee's first name

 -----------------------------------------------------*/
void Employee::setFirstName(string firstName)
{
    this->firstName= firstName;
}

//--------------------------------------------------------------------- Method setLastName()
/*----------------------------------------------------

      Sets the employee's first name

 -----------------------------------------------------*/
void  Employee::setLastName(string lastName)
{
    this->lastName = lastName;
}

//--------------------------------------------------------------------- Method setId()
/*----------------------------------------------------

      Sets the employee's ID

         Warning duplicate,
         modifying the employee's ID 
         can result in a duplicate ID.
         "Two employees with the same ID"

 -----------------------------------------------------*/
void  Employee::setId(unsigned id)
{
    this->id = id;
}

//--------------------------------------------------------------------- Method setPayRate()
/*----------------------------------------------------

      Sets the employee's pay rate

 -----------------------------------------------------*/
void  Employee::setPayRate(double payRate)
{
    this->payRate = payRate;
    // Calculate the employee's pay using the new employee's pay rate
    pay = (1 + payRate) * basePay;
}

//--------------------------------------------------------------------- Method setPay()
/*----------------------------------------------------

      Sets employee's pay

 -----------------------------------------------------*/
void  Employee::setPay(double pay)
{
    this->pay = pay;
    // Calculates Employee's pay rate from the employee's new pay 
    payRate = (pay / payRate) - 1;
}
    

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

// Static mutator methods 
//----------------------------------------------------------------------------------


//--------------------------------------------------------------------- Method setBasePay()
/*----------------------------------------------------

      Sets base pay

 -----------------------------------------------------*/
void  Employee::setBasePay(unsigned basePay)
{
    Employee::basePay = basePay;
}

//--------------------------------------------------------------------- Method setNumEmployees()
/*----------------------------------------------------

    Sets the number of employees

        Warning duplicate,
        modifying the employees number can result 
        in employees duplicate IDs.
        subtracting from the employees number value, 
        and then initializing new employees,
        may cause the new employees 
        to acquirer claimed employee IDs.

 -----------------------------------------------------*/
void  Employee::setNumEmployees(unsigned numEmployees)
{
    Employee::numEmployees = numEmployees; 
}

 






