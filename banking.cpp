// banking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>

using std::cout;
using std::cin;


void showBalance(double balance);
double deposit();
double withdraw(double balance);



int main()
{
	double balance = 0;
	int choice = 0;

	do {
		cout << "enter your choice \n";
		cout << "1.show balance \n";
		cout << "2.deposit \n";
		cout << "3.withdraw \n";
		cout << "4.exit \n";

		cin >> choice;
		if (!cin >> choice) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

		switch (choice) {
		case(1): showBalance(balance);
				break;
		case(2): balance += deposit();
				showBalance(balance);
				break;
		case(3): balance -= withdraw(balance);
				showBalance(balance);
				break;
		case(4): cout << "bye bye :)";
				break;
		default: cout << "invalid choice \n";
				
		};
	} while (choice != 4);
	

	return 0;
}


void showBalance(double balance) {
	cout << "Balance: " << std::setprecision(2) << std::fixed << balance << " $\n";

};

double deposit() {
	double amount = 0;
	cout << "Enter amount to deposit: ";
	cin >> amount;

	if (amount <= 0) {
		cout << "deposit need to be a positive number \n";
		return 0;
	}
	else {
		return amount;
	}
};

double withdraw(double balance) {
	double amount = 0;
	cout << "Enter amount to withdraw: ";
	cin >> amount;

	if (amount <= 0 || amount > balance) {
		cout << "you cant withdraw that amount \n";
		return 0;
	}
	else {
		return amount;
	}
	
};


