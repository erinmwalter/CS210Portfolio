#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/

void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

//function displays how many time an item user inputted was purchased
//based on frequency on the items list
void DisplayItemFrequency(string userItem, int itemFrequency) {
	cout << endl;

	if (itemFrequency == -1)
	{
		cout << "Sorry, " << userItem << " not found on list" << endl;
	}
	else if (itemFrequency == 1)
	{
		cout << userItem << " purchased " << itemFrequency << " time." << endl;
	}
	else
	{
		cout << userItem << " purchased " << itemFrequency << " times." << endl;
	}
}

//function to open the frequency file created in python, get all data,
//and print a histogram for this data.
void DisplayHistogram() {
	ifstream inputFile;
	string itemName;
	int itemFrequency;

	inputFile.open("frequency.dat");
	cout << "\nItem Histogram:" << endl;

	while (!inputFile.fail()) {
		inputFile >> itemName;
		inputFile >> itemFrequency;
		cout << setw(15) << itemName << ": ";
		for (int i = 1; i <= itemFrequency; i++) {
			cout << "*";
		}
		cout << endl;
	}

}

int main()
{
	int userSelection = 0;
	int itemFrequency;
	string userItem;

	cout << "Welcome to the Corner Grocer App" << endl;

	while (userSelection != 4) {

		//main menu for user to select options from
		cout << endl;
		cout << "************ Main Menu ************" << endl;
		cout << "1: List All Items Purchased" << endl;
		cout << "2: View Frequency of Specific Item" << endl;
		cout << "3: View Graph of Purchased Items" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter your selection (choose 1, 2, 3, or 4): ";
		cin >> userSelection;

		if (userSelection == 1) {
			//calls to function to list all items purchased
			CallProcedure("DisplayGroceryList");
		}
		else if (userSelection == 2) {
			//gets input from user and calls to functions to
			//display frequency of a single item
			cout << "Which item would you like the frequency of? ";
			cin >> userItem;

			itemFrequency = callIntFunc("FindGroceryItem", userItem);
			DisplayItemFrequency(userItem, itemFrequency);
		}
		else if (userSelection == 3) {
			//exports grocery data to .dat file
			//and then displays all grocery items as histogram
			CallProcedure("MakeGroceryList");
			DisplayHistogram();
		}
		else if (userSelection == 4) {
			//program exit
			cout << "Program Exited. Goodbye" << endl;
			break;
		}
		else {
			 //input validation
			// if user enters value other than 1, 2, 3, or 4 will display this
			cout << "\nInvalid Selection, try again." << endl;
		}
	}
	return 0;
}