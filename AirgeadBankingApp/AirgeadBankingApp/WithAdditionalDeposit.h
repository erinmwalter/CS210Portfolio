//WithAdditionalDeposit.h

#ifndef WITH_ADDITIONAL_DEPOSIT_H_
#define WITH_ADDITIONAL_DEPOSIT_H_
#pragma once

//WithAdditionalDeposit is the class called to make calculations and display
//to screen the number of years/ yearly interest/ annual balance WITH an
//additional monthly deposit included in calculations.

class WithAdditionalDeposit
{
public:
	void SetValues(double t_startBalance, double t_monthlyDeposit, double t_annualInterest, int t_numYears);
	void DisplayReport();
private:
	double m_startBalance;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_totalBalance = m_startBalance;
	double m_yearEndInterest = 0.0;
	int m_numYears;
	void CalculateYearEndInterest();
	void CalculateTotalBalance();
	double GetTotalBalance() { return m_totalBalance; };
};

#endif WITH_ADDITIONAL_DEPOSIT_H
