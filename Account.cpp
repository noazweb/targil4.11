/*noa zwebner 324989714*/
#include "Account.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
float Account::sumWithdraw = 0;
float  Account::sumDeposit = 0;
#pragma warning (disable:4996)
using namespace std;
Account::Account() {     //default constractor
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = "";
}
Account::Account(int a, int c, int b, string m) {      // constractor
	accountNumber = a;
	if ((code / 1000) == 0)      //wrong code
		code = 0;
	throw string("ERROR: wrong code!");
	code = c;
	balance = b;
	int x = m.find('@');
	if (x < 1)       //wrong email
		throw string("ERROR: wrong email!");
	x = m.find(' ');
	if (x != -1)     //wrong email
		throw string("ERROR: wrong email!");
	string y = ".com";
	int z = y.length();
	x = m.find(y);
	string r = ".co.il";
	int f = m.find(r);
	if (!(x = m.length() - y.length()) && (!(f = m.length() - r.length())))  //wrong email
		throw string("ERROR: wrong email!");
	mail = m;
}
int Account::getAccountNumber() {
	return accountNumber;
}
int Account::getCode() {
	return code;
}
int  Account::getBalance() {
	return balance;
}
string Account::getMail() {
	return mail;
}
void Account::setBalance(int b) {
	balance = b;
}
void Account::setMail(string m) {
	int x = m.find('@');
	if (x < 1)     //wrong email
		throw string("ERROR: wrong email!");
	x = m.find(' ');
	if (x != -1)    //wrong email
		throw string("ERROR: wrong email!");
	string y = ".com";
	int z = y.length();
	x = m.find(y);
	string r = ".co.il";
	int f = m.find(r);
	if (!(x = m.length() - y.length()) && (!(f = m.length() - r.length())))   //wrong email
		throw string("ERROR: wrong email!");
	mail = m;
}
void Account::withdraw(int nis) {
	balance -= nis;
	if (balance < -6000) {   //cannot have less than - 6000 NIS
		balance += nis;
		throw string("ERROR: cannot have less than - 6000 NIS!");
	}
	if (nis > 2500) {
		balance += nis;    //cannot withdraw more than 2500 NIS
		throw string("ERROR: cannot withdraw more than 2500 NIS!");
	}
	if ((nis < 2501) && (balance > -6001))
		sumWithdraw += nis;
}
void Account::deposit(int check) {
	if (check > 10000)   //cannot deposit more than 10000 NIS
		throw string("ERROR: cannot deposit more than 10000 NIS!");
	balance += check;
	sumDeposit += check;
}
int Account::getSumWithdraw() {
	return sumWithdraw;
}
int Account::getSumDeposit() {
	return sumDeposit;
}
/*double Account::SetNumbers(const string num, string msg)
{
	bool flag = true; int number; double sum = 0;
	for (int i = 0; unsigned(i) < num.length(); i++) {
		if (num[i] < '0' || num[i] > '9') {	//tav
			throw msg;
		}
	}
	//flag==true.
	for (int i = num.length() - 1, j = 0; (i >= 0) && (unsigned(j) < num.length()); i--, j++) {
		number = (num[j] - '0');
		sum += (number * pow(10, i));
	}
	return sum;
}*/
istream& operator>>(istream& is, Account& r)

	/*is >> r.accountNumber;
	is >> r.code;
	is >> r.mail;
	if ((r.code / 1000) == 0) {   //wrong code
		throw string("ERROR: code must be of 4 digits!");
	}
	if ((r.code / 10000) != 0) {   //wrong code
		throw string("ERROR: code must be of 4 digits!");
	}
	int x = r.mail.find('@');
	if (x < 1)     //wrong email
		throw string("ERROR: email must contain @!");
	string y = ".com";
	x = r.mail.find(y);
	string k = ".co.il";
	int f = r.mail.find(k);
	if ((x == -1) && (f == -1))    //wrong email
		throw string("ERROR: email must end at .com or .co.il!");

	return is;*/

	{
	string num; string code; double value;
	is >> num >> code >> r.mail;	// balance=0 by default.
	if (is.ignore(256, '\n').gcount() > 1)
		throw "Too many inputs insert into the software.\n";

	value = r.SetNumbers(num, "error in account number\n");
	r.AccountNumber = value;
	value = r.SetNumbers(code, "error in code number\n");
	r.code = value;
	}
/* 1 1111 aaa@gmail.com
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.com
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com*/
