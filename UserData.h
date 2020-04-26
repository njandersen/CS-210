#pragma once
#ifndef USERDATA_H
#define USERDATA_H
using namespace std;

class UserData
{
public:
	UserData(int t_investment = -1, int t_monthDeposit = -1, double t_rate = -1.0, int t_years = -1);
	void displayUserInfo();
	void displayNoDepositReport();
	void displayDepositReport();
protected:
	int m_investment;
	int m_monthDeposit;
	double m_rate;
	int m_numYears;
	int m_startingBalance;
	double m_compoundInterest;


};
#endif
