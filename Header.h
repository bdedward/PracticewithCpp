#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <ctime>

//Data types and classes
struct address {
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	int zip;
};

struct bank_accounts {
	double checking_balance;
	double savings_balance;
};

class Bank_record{
	public:
		address customer_info;
		int pin;
		Bank_record() {
			accts.checking_balance = 0.00;
			accts.savings_balance = 0.00;
			pin = 0;
		}

		void makeDeposit(double deposit, std::string account) {
			if (account == "savings")
				accts.savings_balance += deposit;
			else if (account == "checking")
				accts.checking_balance += deposit;
		}

		void makeWithdrawal(double withdrawl, std::string account) {
			if (account == "savings")
				accts.savings_balance -= withdrawl;
			else if (account == "checking")
				accts.checking_balance += withdrawl;
		}
		double getCheckingBalance() { return accts.checking_balance; }
		double getSavingsBalance() { return accts.savings_balance; }

	private:
		bank_accounts accts;
};
