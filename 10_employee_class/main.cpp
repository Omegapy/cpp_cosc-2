///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*-------------------------------*****************************************----------------------------------
	 |                                *                                      *                                 |
	 |                                *		Classes and Objects Review       *                                 |
	 |                                *                                      *                                 |
	 ---------------------------------****************************************----------------------------------*/
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
* 
	COSC 1030 – Computer Science 2
	Professor: David Durbin
	Student : Alejandro (Alex) Ricciardi
	Due date : 01/31/ 2022
	Classes and Objects Review

											Employee Class

	Write a class that will hold the following information:
		- name (first and last name should each be stored in string variables),
		- ID Number (you will generate these (1-25 is fine) and they should be sequential),
		- pay rate (a percentage in the form of a decimal), 
		- and base pay (an integer).

	Create a file of names to read in both the first and last name of each of your fictional employees,
	assigning each one an id number at the same time.  
	The names and id numbers should be stored in arrays or vectors (your choice).
	Assign each employee a pay rate and use 15,000 as the base pay.  
	There should be a minimum of 25 employees.

	Create get and set functions for each part of the class and create both default and overloaded constructors.
	Remember that constructors will have the exact same name as the class they are part of! (Yes, capitalization matters!)

	Create objects for each employee, using either the default or the overloaded constructor.
	Print out the details (nicely spaced and with proper labels) for employees number 9 through 19
	with their calculated pay instead of the base pay.  
	Calculated pay is one plus their pay rate multiplied by the base pay.
	( 1+PR ) * BP

	When complete take a screen capture of the required output and place it in your project folder.
	ZIP YOUR ENTIRE PROJECT FOLDER and submit it for grading.Class Ship: please see ship.h and ship.cpp



*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------*****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		          Headers                *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************----------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "myGenFunc.hpp"
#include "Employee.hpp"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	            Classes               *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*

	--- see Employee.hpp and Employee.cpp ---

	 The class Employee creates employee objects with the arguments
		(private) id, first and last name, pay rate, and pay
		(static) number of employees and base pay



 */


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	      Function Declarations       *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*

	--- see myGenFunc.hpp ---

	 -------------------------------------------------

		Load files
		Handle load file exception.
		Load data into a string vector
		utilizing end-of-line as a separator,
		and returns vector.

		Requirement:
			ifstream

	 --------------------------------------------------
	vector<string> loadFile(string filePath)


	----------------------------------------------------

		Displays banner

		Requirement:
			iostream
			string

	 ---------------------------------------------------
	void displayBanner(string title)

	----------------------------------------------------

		Displays a table of data string in the console

		Requirement:
			iostream
			string

	 ---------------------------------------------------
	void displayTable(string tableName, vector<string> &colNames, vector<vector<string>> &dataRows)


 */



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *		           Main               *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 //------------------------------------------------------------------------------------
 // Program main entry point
 //------------------------------------------------------------------------------------
int main()
{
	//--- Load employee file names
	vector<string> employeeNames = loadFile("data/employee-names.txt"); // myGenFunc.hpp

	
	//---  Build employee objects 
	vector<Employee> employees;
	double payRate = 0.2; // Base pay rate 
	size_t comaPosition = 0; // Used to find the position of the coma in employee string name
	unsigned countEmployee = 0; // Employee counter used to add to the base pay rate
	// Loops trough the employee names
	for (string name : employeeNames)
	{
		// Employee object
		Employee employee;
 
		// Employee's last and first name
		comaPosition = name.find(",");
		employee.setLastName(name.substr(comaPosition + 1));
		name.resize(comaPosition);
		employee.setFirstName(name);
		 
		// Employee's pay rate (fictional pay rates)
		if (countEmployee % 5 == 0) payRate += 0.13;
		employee.setPayRate(payRate);
		countEmployee++;
		
		// Store employee
		employees.push_back(employee);
	}


	//---- All employees data (string) table (not an assignment requirement)
	vector<string> colNames = { "ID", "First Name", "Last Name", "Base Pay", "Pay Rate", "Pay" },
				   tempData;
	vector<vector<string>> employeesData;
	// Build employee data to be displayed
	for (Employee employee : employees)
	{
		tempData.push_back(to_string(employee.getId()));
		tempData.push_back(employee.getFirstName());
		tempData.push_back(employee.getLastName());
		tempData.push_back(to_string(employee.getBasePay()));
		// Pay rate
		stringstream twoDecimalPayRateDisplay; // Used display only 2 decimals when converting a double to string
		twoDecimalPayRateDisplay << fixed << setprecision(2) << employee.getPayRate(); 
		tempData.push_back(twoDecimalPayRateDisplay.str());
		// Pay
		stringstream twoDecimalPayDisplay; // Used display only 2 decimals when converting a double to string
		twoDecimalPayDisplay << fixed << setprecision(2) << employee.getPay(); // Sets double to be displayed with only 2 decimals
		
		tempData.push_back(twoDecimalPayDisplay.str());
		employeesData.push_back(tempData);

		tempData.clear();
	}

	
	//---- Employees 9 to 19 id, first and last name, and pay data (string) table
	vector<string> colNamesPay = { "ID", "First Name", "Last Name", "Pay" },
		           tempData9to19Pay;
	vector<vector<string>> employeesData9to19Pay;
	// Build employee data to be displayed
	for (unsigned i = 8; i < 19; i++)
	{
		tempData9to19Pay.push_back(to_string(employees[i].getId()));
		tempData9to19Pay.push_back(employees[i].getFirstName());
		tempData9to19Pay.push_back(employees[i].getLastName());
		// Pay
		stringstream twoDecimalPay9to19Display; // Used display only 2 decimals when converting a double to string
		twoDecimalPay9to19Display << fixed << setprecision(2) << employees[i].getPay(); // Sets double to be displayed with only 2 decimals
		
		tempData9to19Pay.push_back(twoDecimalPay9to19Display.str());
		employeesData9to19Pay.push_back(tempData9to19Pay);

		tempData9to19Pay.clear();
	}

	//---- Console
	consoleSize(700, 800, "center"); // myGenFunc.hpp

	//---- Displays banner
	displayBanner("Employees Pay"); // myGenFunc.hpp

	//---- Displays all employees data (not an assignment requirement)
	displayTable("Employees Data", colNames, employeesData); // myGenFunc.hpp
	
	//---- Displays employees 9 to 19 id, first and last name, and pay data
	displayTable("Employees 9 to 19 Pay", colNamesPay, employeesData9to19Pay); // myGenFunc.hpp

} // main()





