#include <iostream>
#include "NoAdditionalDeposit.h"
#include "InputMenu.h"
#include "WithAdditionalDeposit.h"

using namespace std;

int main()
{	
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
	char runAgain = 'y';
	InputMenu MainMenu;
	NoAdditionalDeposit noDeposit;
	WithAdditionalDeposit withDeposit;

	//this loop will continue until the user does not wish to enter another set of inputs
	while (runAgain == 'y' || runAgain == 'Y') {
		system("CLS");

		//setting all values and then displaying to screen
		MainMenu.SetValues(initialInvestment, monthlyDeposit, annualInterest, numYears); 
		MainMenu.DisplayValues();

		//these will set values and then calculate interest and display reports for
		//user's data input if no additional deposit made for specified number of years
		noDeposit.SetValues(initialInvestment, annualInterest, numYears);
		noDeposit.DisplayReport();

		//these will set values and then calculate interest and display reports for
		//user's data input with additional monthly deposits for specifice number of years
		withDeposit.SetValues(initialInvestment, monthlyDeposit, annualInterest, numYears);
		withDeposit.DisplayReport();

		//asks if user wishes to run again
		cout << "\nAgain? (y/n)";
		cin >> runAgain;
	}

	system("CLS");
	cout << "\nProgam Exited. Goodbye.";
}

