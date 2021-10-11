#include "WithAdditionalDeposit.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//constructor to initialize all the values for the object
void WithAdditionalDeposit::SetValues(double t_startBalance, double t_monthlyDeposit, double t_annualInterest, int t_numYears) {
	m_startBalance = t_startBalance;
	m_monthlyDeposit = t_monthlyDeposit;
	m_annualInterest = t_annualInterest;
	m_numYears = t_numYears;
	m_totalBalance = m_startBalance;
}

//this function calculates the year-end interest 
//interest is compounded monthly and a monthly deposit is also made
void WithAdditionalDeposit::CalculateYearEndInterest() {
	double monthlyBalance = m_startBalance;
	double tempBalance;
	double monthlyInterest = 0;
	
	//this loop runs 12 times (for 12 months in the year)
	//will calculate the monthly balance and add up monthly interest earned
	//then will calculate the year end interest for one year
	for (int i = 1; i <= 12; i++) {
		tempBalance = (monthlyBalance + m_monthlyDeposit) * (1 + (m_annualInterest / 100 / 12)); 
		monthlyInterest += tempBalance - (monthlyBalance + m_monthlyDeposit); //calculating only the interest for each month and adding to total interest for year
		monthlyBalance = tempBalance;
	}
	m_yearEndInterest = monthlyInterest;
	
}

//this function calculates the total balance for the end of each year
//takes the start balance for the year plus the 12 monthly deposits plus the calculated year end interest
void WithAdditionalDeposit::CalculateTotalBalance() {
	m_totalBalance = m_startBalance + (12 * m_monthlyDeposit) + m_yearEndInterest;
}

//this function will display the report for the interest earned and total balance
//at the end of each year WITH an additional deposit each month
void WithAdditionalDeposit::DisplayReport() {
	cout << endl;
	cout << "========================================================" << endl;
	cout << "  Balance and Interest With Additional Monthly Deposits " << endl;
	cout << "========================================================" << endl;
	cout << "Year      Year End Balance      Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;

	//loops through the number of years, calculates yearly interest and 
	//year end balance for each year and displays this to the screen
	for (int i = 1; i <= m_numYears; i++) {
		CalculateYearEndInterest();
		CalculateTotalBalance();
		cout << setw(4) << i;
		cout << setw(22) << fixed << setprecision(2) << m_totalBalance;
		cout << setw(30) << fixed << setprecision(2) << m_yearEndInterest;
		cout << endl;

		m_startBalance = GetTotalBalance();
	}
}