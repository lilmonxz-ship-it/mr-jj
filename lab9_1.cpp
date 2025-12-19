#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, rate, pay;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;
	cout << "Enter amount you can pay per year: ";
	cin >> pay;

	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	int year = 1;
	double prevBalance = loan;

	cout << fixed << setprecision(2); 

	while(prevBalance > 0) {

		double interest = prevBalance * (rate / 100.0);
		double total = prevBalance + interest;

		double actualPay = pay;
		if(total < pay) {
			actualPay = total;
		}

		double newBalance = total - actualPay;


		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevBalance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << actualPay;
		cout << setw(13) << left << newBalance;
		cout << "\n";

		prevBalance = newBalance;
		year++;
		
		if(interest >= pay && prevBalance > 0) {
			break; 
		}
	}
	
	return 0;
}
