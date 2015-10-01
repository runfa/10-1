//运算符重载、分散编译、命名空间
#ifndef MONEY_H
#define MONEY_H
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
namespace Space1
{
class Money
{
public:
	Money();
	Money(double amount);
	Money(int theDollars,int theCents);
	double getAmount() const;
	int getDollars()const;
	int getCents()const;
	void input();
	void output() const;
	void operator=(const Money& amount2);
private:
	int dollars;
	int cents;
	int dollarsPart(double amount)const;
	int centsPart(double amount)const;
	int round(double number)const;
};
const Money operator +(const Money& amount1,const Money& amount2);
const Money operator -(const Money& amount1,const Money& amount2);
bool operator ==(const Money& amount1,const Money& amount2);
const Money operator -(const Money& amount1);
//const Money operator=(const Money& amount1,const Money& amount2);
}
#endif