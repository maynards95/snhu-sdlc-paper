#include "Bank.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Bank::SetDepAmt(float d) 
{
	depAmt = d;
}

void Bank::SetInterest(float i) {
	interest = i;
}

void Bank::SetOpenAmt(float o) {
	openAmt = o;
}

void Bank::SetMonths(float m) {
	months = m;
}

void Bank::SetYears(float y) {
	years = y;
}

void Bank::SetTotal(float t) {
	total = t;
}

float Bank::GetDepAmt() {
	return depAmt;
}

float Bank::GetInterest() {
	return interest;
}

float Bank::GetMonths() {
	return months;
}

float Bank::GetOpenAmt() {
	return openAmt;
}

float Bank::GetYears() {
	return years;
}

float Bank::GetTotal() {
	return total;
}



void Bank::openingMenu() {
	//Displays intial data for user to fill out
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";
}

void Bank::userInput() {
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: $";
	cin >> openAmt;
	SetOpenAmt(openAmt);
	cout << "Monthly Deposit: $";
	cin >> depAmt;
	SetDepAmt(depAmt);
	cout << "Annual Interest Percentage: ";
	cin >> interest;
	SetInterest(interest);
	cout << "Number of years: ";
	cin >> years;
	SetYears(years);
	SetMonths(years * 12);
}

float Bank::tableNoDeposit(float total)
{
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (int i = 0; i < years; i++)
	{
		//Calculate yearly interest
		interestAmt = (GetTotal()) * ((GetInterest() / 100));
		//Calculate year end total
		total = interestAmt + GetTotal();
		SetTotal(total);
		//Print table
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << GetTotal() << "\t\t\t$" << interestAmt << "\n" << endl;
	}
	return 0;
}

float Bank::tableDeposit(float total) {
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (int i = 0; i < years; i++)
	{
		yearTotInt = 0;
		for (int j = 0; j < 12; j++)
		{
			//Calculate monthly interest
			interestAmt = (GetTotal() + GetDepAmt()) * ((GetInterest() / 100) / 12);
			//Calculate year end interest
			yearTotInt = yearTotInt + interestAmt;
			//Calculate year end total
			total = GetTotal() + GetDepAmt() + interestAmt;
			SetTotal(total);
		}
		//Print table
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << GetTotal() << "                   $" << yearTotInt << "\n" << endl;
	}
	return 0;
}



