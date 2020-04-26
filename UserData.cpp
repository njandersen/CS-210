#include "UserData.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// constructor to initialize all  the varialbles 
UserData::UserData(int t_investment, int t_monthDeposit, double t_rate, int t_years)
{
	m_investment = t_investment;
	m_monthDeposit = t_monthDeposit;
	m_rate = t_rate;
	m_numYears = t_years;
	m_compoundInterest = pow(1 + (m_rate / 100) / 12, 12);
	m_startingBalance = m_investment + (m_monthDeposit * 12);


}



//displays all the data the user has input
void UserData::displayUserInfo()
{
	cout << "===============================" << endl;
	cout << "==========Daily Input==========" << endl;
	cout << "Initial Investment Amount: " << m_investment << endl;
	cout << "Monthly Deposit: " << m_monthDeposit << endl;
	cout << "Annual Interest: " << m_rate << '%' << endl;
	cout << "Number of Years: " << m_numYears << endl;



}

// displays the user report without a monthly deposit when called
void UserData::displayNoDepositReport()
{
	int currInvestment;
	int startingBalance;
	double currInterest;
	double startingInterest;
	vector<int> interest(m_numYears);
	vector<int> yearEndBalance(m_numYears);
	int i = 0;

	startingBalance = m_investment;
	currInvestment = startingBalance;
	for (int i = 0; i < yearEndBalance.size() - 1; ++i)
	{
		currInvestment = currInvestment * m_compoundInterest;
		yearEndBalance.at(i) = currInvestment;
	}
	currInvestment = m_investment;
	startingInterest = m_investment * (m_rate / 100) * 1;
	for (int i = 0; i < interest.size() - 1; ++i)
	{
		currInvestment = currInvestment * m_compoundInterest;
		currInterest = currInvestment * (m_rate / 100) * 1;
		interest.at(i) = currInterest;

	}

	cout << "     Balance and Interest With No Monthly Deposits" << endl;
	cout << "==========================================================" << endl;
	cout << "Year" << "     " << "Year End Balance" << "        " << "Year End Interest" << "       " << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "1" << setw(20) << '$' << startingBalance << setw(22) << '$' << startingInterest << endl;
	for (i = 0; i < yearEndBalance.size(); ++i)
	{

		cout << i + 2 << setw(20) << '$' << yearEndBalance.at(i) << setw(22) << '$' << interest.at(i) << endl;
	}

}

// displays the report with monthly deposits
void UserData::displayDepositReport()
{
	int currInvestment;
	int startingBalance;
	double currInterest;
	double startingInterest;
	vector<int> interest(m_numYears);
	vector<int> yearEndBalance(m_numYears);
	int i = 0;

	startingBalance = m_investment;
	currInvestment = startingBalance;
	for (int i = 0; i < yearEndBalance.size() - 1; ++i)
	{
		currInvestment = currInvestment + (m_monthDeposit * 12) * m_compoundInterest;
		yearEndBalance.at(i) = currInvestment;
	}
	currInvestment = m_investment;
	startingInterest = m_investment * (m_rate / 100) * 1;
	for (int i = 0; i < interest.size() - 1; ++i)
	{
		currInvestment = currInvestment + (m_monthDeposit * 12) * m_compoundInterest;
		currInterest = currInvestment * (m_rate / 100) * 1;
		interest.at(i) = currInterest;

	}

	cout << "     Balance and Interest With Monthly Deposits" << endl;
	cout << "==========================================================" << endl;
	cout << "Year" << "     " << "Year End Balance" << "        " << "Year End Interest" << "       " << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "1" << setw(20) << '$' << startingBalance << setw(22) << '$' << startingInterest << endl;
	for (i = 0; i < yearEndBalance.size(); ++i)
	{

		cout << i + 2 << setw(20) << '$' << yearEndBalance.at(i) << setw(22) << '$' << interest.at(i) << endl;
	}
}


// testbench for class
/*int main()
{
	UserData testData(1000, 50, 8, 10);
	cout << "Beginning test" << endl;

	
	testData.displayNoDepositReport();
	cout << endl;
	testData.displayDepositReport();

	testData.displayUserInfo();
}*/


