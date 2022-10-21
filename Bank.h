class Bank {
public:
	float openAmt, depAmt, interest, months, years;
	float total, interestAmt, yearTotInt;

	//Getters
	void SetOpenAmt(float o);
	void SetDepAmt(float d);
	void SetInterest(float i);
	void SetMonths(float m);
	void SetYears(float y);
	void SetTotal(float t);

	//Setters
	float GetOpenAmt();
	float GetDepAmt();
	float GetInterest();
	float GetMonths();
	float GetYears();
	float GetTotal();

	float tableNoDeposit(float total);

	float tableDeposit(float);
	
	void openingMenu();

	void userInput();
};
