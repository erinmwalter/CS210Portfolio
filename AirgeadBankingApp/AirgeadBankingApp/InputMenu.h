//InputMenu.h
#ifndef INPUT_MENU_H_
#define INPUT_MENU_H_
#pragma once

//this class runs through the main menu, user input validation,
//as well as calls to WithAdditionalDeposit and NoAdditionalDeposit classes
//to run calculations and display both reports to the screen for user to view.
class InputMenu
{
public:
	void SetValues(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& numYears);
	void DisplayValues();

private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numYears;
};

#endif INPUT_MENU_H_

