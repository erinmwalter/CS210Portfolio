#include "TwelveHourClock.h"
#include "TwentyFourHourClock.h"
#include <iostream>
#include <iomanip>

using namespace std;

//this function initializes the 12 hour clock to the values passed into function from main
void TwelveHourClock::Initialize12HourClock(int hr, int min, int sec, bool isItPM)
{
	clockHours = hr;
	clockMinutes = min;
	clockSeconds = sec;
	isPM = isItPM;

}

//this function will serve to add an hour to the 12 hour clock
void TwelveHourClock::AddHour()
{
	clockHours += 1;
	//every time the clock reaches 12 it changes from AM to PM or PM to AM
	//this statement checks for this
	if (clockHours == 12) {
		if (isPM)
		{
			isPM = false;
		}
		else
		{
			isPM = true;
		}
	}
	//every time the clock gets to 13, the clock hours gets reset back to 1
	if (clockHours == 13) {
		clockHours = clockHours - 12;
	}
}

//this function serves to display the 12 hour clock to the screen in the correct format
void TwelveHourClock::Display12HrClock()
{
	//will print either A M or P M depending on the value of the bool variable
	if (isPM) {
		cout << setw(2) << setfill('0') << clockHours << ":" << setw(2) << setfill('0') << clockMinutes << ":" << setw(2) << setfill('0') << clockSeconds << " P M";
	}
	else {
		cout << setw(2) << setfill('0') << clockHours << ":" << setw(2) << setfill('0') << clockMinutes << ":" << setw(2) << setfill('0') << clockSeconds << " A M";
	}
}

//this function will serve to add a minute to the 12 hour clock object
void TwelveHourClock::AddMinute()
{
	clockMinutes += 1;

	//will reset the clock minutes to zero and call to the add hour function
	//in order to add an hour to the clock when it reaches 60 minutes
	if (clockMinutes == 60)
	{
		clockMinutes = 0;
		AddHour();
	}
}

//this function will serve to add a second to the 12 hour clock object
void TwelveHourClock::AddSecond()
{
	clockSeconds += 1;

	//if the clock seconds gets to 60, this resets to zero
	//it also calls on the add minute function to add a minute to the clock
	if (clockSeconds == 60)
	{
		clockSeconds = 0;
		AddMinute();
	}
}