#include <iostream>
#include <iomanip>
#include "Bank.h"

using namespace std;

Bank bank;

int main()
{
	//initial prompts for user to input info
	bank.openingMenu();
	
	//Wait for input from user (Press any key to continue...)
	system("PAUSE");

	//Get data from user
	bank.userInput();
	
	//Updated total amount
	bank.SetTotal(bank.GetOpenAmt());

	//Wait for input from user (Press any key to continue...)
	system("PAUSE");

	//Display table without monthly deposits
	bank.tableNoDeposit(bank.GetTotal());

	//Set total amount to initial investment to be updated
	bank.SetTotal(bank.GetOpenAmt());

	//Display table with monthly deposits
	bank.tableDeposit(bank.GetTotal());
	
	return 0;
}