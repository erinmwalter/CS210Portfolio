#include "TwentyFourHourClock.h"
#include <iostream>
#include <iomanip>

using namespace std;

//this function serves to initialize the 24 hour clock to inputted values
void TwentyFourHourClock::Initialize24HrClock(int hrs, int min, int sec)
{
	clockHours = hrs;
	clockMinutes = min;
	clockSeconds = sec;
}

//this function serves to display the time to the screen in the correct format
void TwentyFourHourClock::Display24HrClock()
{
	cout << setw(2) << setfill('0') << clockHours << ":" << setw(2) << setfill('0') << clockMinutes << ":" << setw(2) << setfill('0') << clockSeconds;
}

//this function serves to add an hour to the 24 hr clock
void TwentyFourHourClock::AddHour()
{
	clockHours += 1;

	//this will reset the clock hours to 0 if it reaches 24 hours
	if (clockHours == 24)
	{
		clockHours = 0;
	}
}

//this function serves to add a minute to the 24 hour clock
void TwentyFourHourClock::AddMinute()
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

//this function serves to add a second to the 24 hour clock
void TwentyFourHourClock::AddSecond()
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