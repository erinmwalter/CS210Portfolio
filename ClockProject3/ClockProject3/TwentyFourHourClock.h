#pragma once
class TwentyFourHourClock
{
public:
	void AddHour();
	void AddMinute();
	void AddSecond();
	void Display24HrClock();
	void Initialize24HrClock(int hr, int min, int sec);
private:
	int clockHours;
	int clockMinutes;
	int clockSeconds;
};

