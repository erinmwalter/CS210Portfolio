#pragma once

class TwelveHourClock
{
public:
	void AddHour();
	void AddMinute();
	void AddSecond();
	void Display12HrClock();
	void Initialize12HourClock(int hrs, int min, int sec, bool isPM);
private:
	int clockHours;
	int clockMinutes;
	int clockSeconds;
	bool isPM;
};

