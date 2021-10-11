#include "InputMenu.h"
#include "NoAdditionalDeposit.h"
#include "WithAdditionalDeposit.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// this main menu gets all inputs from the user as well as displays to screen
// what the user has inputed 
void InputMenu::SetValues(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& numYears) {
	try {
		//this gets all input values from the user
		cout << "********Main Menu: Data Input********" << endl;
		cout << "Enter Initial Investment Amount: ";
		cin >> m_initialInvestment;
		if (m_initialInvestment < 0) {
			//throws error message below if initial investment < 0
			throw runtime_error("Invalid Initial Investment Amount.");
		}
		initialInvestment = m_initialInvestment;

		cout << "Enter Monthly Deposit Amount: ";
		cin >> m_monthlyDeposit;
		if (m_monthlyDeposit < 0) {
			//throws error message below if monthly deposit amount < 0
			throw runtime_error("Invalid Monthly Deposit Amount.");
		}
		monthlyDeposit = m_monthlyDeposit;

		cout << "Enter Annual Interest Percentage: ";
		cin >> m_annualInterest;
		if (m_annualInterest < 0) {
			//throws error message below if annual interest less than 0
			throw runtime_error("Invalid Annual Interest Percentage.");
		}
		annualInterest = m_annualInterest;

		cout << "Enter Number of Years: ";
		cin >> m_numYears;
		if (m_numYears <= 0) {
			//throws below error message if num years less than or equal to 0
			throw runtime_error("Invalid Number of Years Entered.");
		}
		numYears = m_numYears;
	}

	catch (runtime_error& excpt) {
		//prints error message passed by throw statement
		cout << excpt.what() << endl;
		cout << "Try again." << endl;
	}
}

//this function will display the values that the user entered to the screen.
void InputMenu::DisplayValues()
{
	cout << "\n********Your Data Input********" << endl;
	cout << "Initial Investment: $" << m_initialInvestment << endl;
	cout << "MonthlyDeposit Amount: $" << m_monthlyDeposit << endl;
	cout << "Annual Interest Percentage: " << m_annualInterest << "%" << endl;
	cout << "Number of Years: " << m_numYears << endl;

	system("pause"); //pauses to wait for user to press key
}

