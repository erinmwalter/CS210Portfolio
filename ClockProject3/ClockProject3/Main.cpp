#include <iostream>
#include "TwentyFourHourClock.h"
#include "TwelveHourClock.h"
#include "stdlib.h"

using namespace std;

/*

PROJECT ONE
CS 210

Erin Walter 
09/16/2021

*/

//this function displays both the 12 hr and 24 hr clock in the correct
//format on the the screen. It takes a twenty four hour clock and a twelve
//hour clock object and outputs these to screen.
void DisplayClock(TwentyFourHourClock TwentyFour, TwelveHourClock Twelve) {
	cout << "************************   ************************" << endl;
	cout << "*    12-Hour Clock     *   *     24-Hour Clock    *" << endl;
	cout << "*    ";
	Twelve.Display12HrClock();
	cout << "      *   *        ";
	TwentyFour.Display24HrClock();
	cout << "      *" << endl;
	cout << "************************   ************************" << endl;
	cout << endl;
}

int main()
{
	string userSelection = "0";
	TwentyFourHourClock TwentyFourHour;
	TwelveHourClock TwelveHour;

	//initialized both of 12 and 24 hr clock objects to same time for testing purposes
	TwentyFourHour.Initialize24HrClock(23, 59, 59);
	TwelveHour.Initialize12HourClock(11, 59, 59, true);

	//main menu loop clears the screen, then displays the
	//current clocks, then displays the menu and asks user
	//for their input to change clocks or exit program
	while (userSelection != "4") {
		system("CLS");
		DisplayClock(TwentyFourHour, TwelveHour);
		cout << endl;

		//below is code for the main menu display
		cout << "*      Main Menu      *" << endl;
		cout << "***********************" << endl;
		cout << "* 1 - Add One Hour    *" << endl;
		cout << "* 2 - Add One Minute  *" << endl;
		cout << "* 3 - Add One Second  *" << endl;
		cout << "* 4 - Exit Program    *" << endl;
		cout << "***********************" << endl;
		cout << "Make Your Selection: "; //prompt user for selection
		cin >> userSelection; //saves user selection in userSelection variable
		cout << endl;

		if (userSelection == "1") {
			//adds an hour to both the 12 and 24 hr clocks
			TwentyFourHour.AddHour();
			TwelveHour.AddHour();
		}
		else if (userSelection == "2") {
			//adds a minute to both 12 and 24 hr clocks
			TwentyFourHour.AddMinute();
			TwelveHour.AddMinute();
		}
		else if (userSelection == "3") {
			//adds a second to both 12 and 24 hr clocks
			TwentyFourHour.AddSecond();
			TwelveHour.AddSecond();
		}
		else if (userSelection == "4") {
			//breaks from while loop and exits program upon
			//user request
			cout << "Program exit selected. Goodbye!";
			break;
		}
	}

	return 0;
}