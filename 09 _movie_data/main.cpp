///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*--------------------------------****************************************----------------------------------
	 |                                *                                      *                                 |
	 |                                *		           Movie Data            *                                 |
	 |                                *                                      *                                 |
	 ---------------------------------****************************************----------------------------------*/
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
* 
	COSC 1030 – Computer Science 2
	Professor: David Durbin
	Student : Alejandro (Alex) Ricciardi
	Due date : 02/07/2023
	CWeek 3: Structures


											Movie Data

	Write a program that creates a structure to store information.  The data stored should include the following: 

		Title
		Director
		Year Released
		Running Time (in minutes)
		Production Costs
		Profits

	Create two instances of your structure and input the data from two different movies 
	(yes, just google the information (I'll even overlook the use of wikipedia for this)).  
	Pass the structure to a function for output, display the information for both instances of the structure 
	and take a screen capture of the output.

	Submit your screen capture, and .cpp file in a zipped folder.  Don't forget to comment your program!


	Credits:
	
	Avatar (2009) https://www.the-numbers.com/movie/Avatar#tab=summary
		Title: Avatar
		Director: James Cameron	 
		Year Released: 2009
		Running Time (in minutes): 162 minutes
		Production Costs (Production budget): $237,000,000
		Profits: (Worldwide Box Office) - (Production budget) = $2,899,384,102 - $237,000,000 = $2,662,384,102
				
	Avengers: Endgame https://www.the-numbers.com/movie/Avengers-Endgame-(2019)#tab=summary
		Title: Avengers: Endgame
		Director: Joe Russo		 
		Year Released: 2019
		Running Time (in minutes): 181 minutes
		Production Costs (Production budget): $400,000,000
		Profits: (Worldwide Box Office) - (Production budget) = $2,794,731,755 - $400,000,000 = $2,394,731,755


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



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	            Structs               *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*----------------------------------------------------

	 creates a structure to store movies information 

 ---------------------------------------------------*/
struct Movie {
	string title,
		director;
	unsigned yearReleased = 0,
		runningTime = 0;
	double productionCosts = 0.00, // in $
		   profits = 0.00; // in $
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	      Function Declarations       *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*

	--- see myGenFunc.hpp ---


	------------------------------------------------------


		Sets size of the Console's window
		and position the console in desktop screen
		utilizing the variable positionConsole

		position_console values:
			"center", "leftCenter", "rightCenter",
			"topLeft", "topCenter", "topRight",
			"bottomLeft", "bottomCenter", "bottomRight".

		Requirement:
			Windows OS
			#include<string>
			#include<windows.h>

	--------------------------------------------------------
   void consoleSize(int consoleWidth, int consoleHeight, string positionConsole);


	----------------------------------------------------

		Displays banner

		Requirement:
			#include<iostream>
			#include<string>

	 ---------------------------------------------------
	void displayBanner(string title);

	----------------------------------------------------

		Displays a table of data string in the console

		Requirement:
			#include<iostream>
			#include<string>

	 ---------------------------------------------------
	void displayTable(string tableName, vector<string> &colNames, vector<vector<string>> &dataRows);


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

	//---  Build Movies objects 
	Movie avatar = { "Avatar", "James Cameron", 2009, 162, 237000000.00, 2662384102.00 },
		  endgame = { "Avengers: Endgame", "Joe Russo", 2019, 181, 400000000.00, 2394731755.00 };
	
	vector<Movie> movies = { avatar, endgame }; // Used to store the movies' data to be displayed in a table

	
	//---- Displays Movies' data.
	vector<string> colNames = { "Title", "Director", "Year Released", "Running Time", "Production Costs", "Profits" }; // Table columns names
	vector<vector<string>> moviesTable; // Table of movies 

	// Build movies table, to be displayed
	for (Movie movie : movies)
	{ 
		
		moviesTable.push_back(
			{
				movie.title,
				movie.director,
				to_string(movie.yearReleased),
				to_string(movie.runningTime),
				"$" + to_string((int)round(movie.productionCosts / 1000000)) + " millions", // rounded to the nearest million USD
				"$" + to_string((int)round(movie.profits / 1000000)) + " millions" // rounded to the nearest million USD
			});
	}

	//---- Console
	consoleSize(1200, 800, "center"); // myGenFunc.hpp

	//---- Displays banner
	displayBanner("Most Profitable Movies"); // myGenFunc.hpp

	//---- Displays Movies's Data in a table
	displayTable("Top Two Most Profitable Movies", colNames, moviesTable); // myGenFunc.hpp

	cout << "\n\x1B[93m   Production Costs and Profits values are rounded to the nearest million USD.\033[0m\n";

} // main()





