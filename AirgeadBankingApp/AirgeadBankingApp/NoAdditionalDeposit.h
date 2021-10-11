//NoAdditionalDeposit.h
#ifndef NO_ADDITIONAL_DEPOSIT_H_
#define NO_ADDITIONAL_DEPOSIT_H_
#pragma once

//NoAdditionalDeposit is the class called to make calculations and display
//to screen the number of years/ yearly interest/ annual balance if no
//additional monthly deposit is made.

class NoAdditionalDeposit
{
public:
	void SetValues(double t_startBalance, double t_annualInterest, int t_numYears);
	void DisplayReport();
	double GetTotalBalance() { return m_totalBalance; };
private:
	double m_startBalance;
	double m_annualInterest;
	double m_totalBalance;
	double m_yearEndInterest;
	int m_numYears;
	void CalculateYearEndInterest();
	void CalculateTotalBalance();
};

#endif NO_ADDITIONAL_DEPOSIT_H_
