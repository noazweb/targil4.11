/*noa zwebner 324989714
The program implements an ATM*/
#include <iostream>
#include "Clock.h"
#include "Account.h"
#include<cmath>

using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	cout << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number:" << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i > 9 || i < 0)
		throw string("ERROR: no such account number!");
	cout << "please enter the code:" << endl;
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else {
		throw string("ERROR: wrong code!");
	}
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	try {
		int i = findAccount(bank, size);
		c += 20;
		printTransaction(bank[i], balance, c);
	}
	catch (string s)
	{
		cout << c << "\t" << s << endl;
		
	}
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	try {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	
		bank[i].deposit(amount);
		c += 30;

		printTransaction(bank[i], deposit, c);
	}
	catch (string s)
	{
		cout << c << "\t" << s << endl;
		//cout << c << "\t";
	}
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	try {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;

		bank[i].withdraw(amount);
		c += 50;
		printTransaction(bank[i], withdraw, c);
	}
	catch (string s)
	{
		cout << c << "\t" << s << endl;
		//cout << c << "\t";
	}
}
int main()
try 
	{
		Clock c(8);
		Account bank[10];
		cout << "enter account number, code and email for 10 accounts:\n";
		for (int i = 0; i < 10; i++)
		{
			try {
				cin >> bank[i];
				for (int j = 0; j < i; j++)
					if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
						throw "ERROR: account number must be unique!\n";
			}
			catch (string s)
			{
				cout << c << "\t" << s << endl;
				i--;
			}
			catch (const char* msg)
			{
				cout << c << '\t' << msg;
				i--;
			}
		}
		action ac = menu();
		while (ac)
		{
			switch (ac)
			{
			case balance: getBalance(bank, 10, c);
				break;
			case withdraw:cashWithdraw(bank, 10, c);
				break;
			case deposit:cashDeposit(bank, 10, c);
				break;
			case sumDeposit:c += 60;
				printTransaction(bank[0], sumDeposit, c);
				break;
			case sumWithdraw:c += 60;
				printTransaction(bank[0], sumWithdraw, c);

			}
			ac = menu();
		}
		return 0;
	}

catch (string s)
{
	cout <<  s << endl;
	
}
/*enter account number, code and email for 10 accounts:
11
1111
aa@aa.com
22
2222
bb@bb.com
33
3333
cc@cc.com
44
4444
dddd.com
ERROR: wrong email!
55
5555
dd@dd.com
66
6666
ee@ee.com
77
7777
oo@oo.com
88
8888
ll@ll.com
99
9999
ss@ss.com
23
2323
qw@qw.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 11
please enter the code: 1111
08:00:020
		account #: 11   balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number: 11
please enter the code: 1111
enter the amount of the check: 500
08:00:050
		account #: 11   new balance: 500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
3
please enter account number: 11
please enter the code: 1111
enter the amount of money to withdraw: 300
08:01:040
		account #: 11   new balance: 200
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
4
08:02:040
		sum of all deposits: 500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
5
08:03:040
		sum of all withdraws: 300
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
0

C:\Users\User\source\repos\targil4.11\Debug\targil4.11.exe (process 12796) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
