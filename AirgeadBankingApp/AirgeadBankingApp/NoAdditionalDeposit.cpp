#include "NoAdditionalDeposit.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//initializes all  values for the object based on user input
void NoAdditionalDeposit::SetValues(double t_initialInvestment, double t_annualInterest, int t_numYears) {
	m_startBalance = t_initialInvestment;
	m_annualInterest = t_annualInterest;
	m_numYears = t_numYears;
	m_totalBalance = m_startBalance;
	m_yearEndInterest = 0.00;
}

//calculates the year end balance and then year end interest
void NoAdditionalDeposit::CalculateYearEndInterest() {
	double yearEndBalance;
	yearEndBalance = m_startBalance * pow((1 + (m_annualInterest / 100 / 12)), 12); //first calculates entire year end balance
	m_yearEndInterest = yearEndBalance - m_startBalance; //next subtracts starting balance to only have yearly interest
}

//calculates the total balance for the year by adding starting balance and year end interest
void NoAdditionalDeposit::CalculateTotalBalance() {
	m_totalBalance = m_startBalance + m_yearEndInterest;
}

//function displays the report for yearly interest and balances with no additional 
//monthly deposit being made
void NoAdditionalDeposit::DisplayReport() {
	cout << endl;
	cout << "========================================================" << endl;
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "Year      Year End Balance      Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	
	//loop will both calculate year end interest and total balance as well as
	//display these to the screen for the number of years that the user input indicates
	for (int i = 1; i <= m_numYears; i++) {
		CalculateYearEndInterest(); 
		CalculateTotalBalance();
		cout << setw(4) << i;
		cout << setw(22) << fixed << setprecision(2) <<  m_totalBalance;
		cout << setw(30) << fixed << setprecision(2) << m_yearEndInterest;
		cout << endl;

		m_startBalance = GetTotalBalance();
	}
}
