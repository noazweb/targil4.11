/*noa zwebner 324989714*/
#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
class Account
{
	int accountNumber;
	int code;
	int balance;
	string mail;
	double AccountNumber;
public:
	Account();
	Account(int, int, int, string);
	int getAccountNumber();
	int getCode();
	int getBalance();
	string getMail();
	void setBalance(int);
	void setMail(string);
	void withdraw(int nis);
	void deposit(int);
	static float sumWithdraw;
	static float sumDeposit;
	static int getSumWithdraw();
	static int getSumDeposit();
	double SetNumbers(const string num,  const string msg);
	friend istream& operator>>(istream& is, Account& num);
};

