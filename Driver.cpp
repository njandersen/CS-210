#include "UserData.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void main()
{
	// declares and initializes all needed variables 
	int investment = 0;
	int monthlyDeposit = 0;
	double interestRate = 0;
	int numYears = 0;
	bool quit = false;
	char quitCmd = ' ';

	

	while (quitCmd != 'q')
	{
		try
		{
			cout << "Enter inital investment:" << endl;
			cin >> investment;
			if (investment < 0 )
			{
				throw runtime_error("Invalid Investment."); // error checking investment
			}
			
			cout << "Enter Monthly Deposit:" << endl;
			cin >> monthlyDeposit;
			if (monthlyDeposit < 0 )
			{
				throw runtime_error("Invalid Deposit."); // error checking deposit
			}
			
			cout << "Enter interest rate:" << endl;
			cin >> interestRate;
			if (interestRate < 0 )
			{
				throw runtime_error("Invalid Interest Rate."); // error checking interest 
			}

			cout << "Enter number of years:" << endl;
			cin >> numYears;
			if (numYears < 0 )
			{
				throw runtime_error("Invalid Number of Years."); // error checking years
			}
			UserData UserInfo(investment, monthlyDeposit, interestRate, numYears);
			UserInfo.displayUserInfo();
		
			
		
		}
		catch (runtime_error& except)
		{
			cout << except.what() << endl;
			cout << "cannot compute info." << endl;
		}
		UserData UserInfo(investment, monthlyDeposit, interestRate, numYears);
		cout << "Enter any key to continue or q to quit." << endl;
		cin >> quitCmd;
		UserInfo.displayNoDepositReport();
		UserInfo.displayDepositReport();
	}


}
