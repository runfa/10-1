#include"8-1.h"
#include<cmath>
#include<cstdlib>
using namespace Space1;
namespace Space1
{
Money::Money():dollars(0),cents(0)
{}
Money::Money(double amount):dollars(dollarsPart(amount)),cents(centsPart(amount))
{}
Money::Money(int theDollars,int theCents)//:dollars(theDollars),cents(theCents)
{
	if(((theDollars<0)&&(theCents>0))||((theDollars>0)&&(theCents<0)))
	{cout<<"error\n";exit(1);}
	dollars=theDollars;cents=theCents;
}
double Money::getAmount()const
{
	return (dollars+0.01*cents);
}
int Money::getDollars()const
{
	return dollars;
}
int Money::getCents()const
{
	return cents;
}
void Money::input()
{
	/*cout<<"please enter your amount of dollars as an integer\n";
	cin>>dollars;
	cout<<"please enter your amount of cents as an integer\n";
	cin>>cents;
	if(((dollars<0)&&(cents>0))||((dollars>0)&&(cents<0)))
		{cout<<"error\n";exit(1);}*/
	char dollarSign;
	cin>>dollarSign;
	if(dollarSign!='$')
	{
		cout<<"No dollar sign in Money input.\n";
		exit(1);
	}
	double amountAsDouble;
	cin>>amountAsDouble;
	dollars=dollarsPart(amountAsDouble);
	cents=centsPart(amountAsDouble);
}
void Money::output()const
{
	//cout<<(dollars+0.01*cents);
	int absDollars=abs(dollars);
	int absCents=abs(cents);
	if(dollars<0||cents<0)
		cout<<"$-";
	else
		cout<<'$';
	cout<<absDollars;
	if(absCents>=10)
		cout<<'.'<<absCents;
	else
		cout<<'.'<<'0'<<absCents;
}

int Money::dollarsPart(double amount)const
{
	return static_cast<int>(amount);
}
int Money::centsPart(double amount)const
{
	//return ((static_cast<int>(amount*100))%100);
	double doubleCents=amount*100;
	int intCents=(round(fabs(doubleCents)))%100;
	if(amount<0)
	intCents=-intCents;
	return intCents;
}
int Money::round(double number)const
{
	return static_cast<int>(floor(number+0.5));
}

const Money operator +(const Money& amount1,const Money& amount2)
{
	int allCents1=amount1.getCents()+amount2.getDollars()*100;
	int allCents2=amount2.getCents()+amount2.getDollars()*100;
	int allCents=allCents1+allCents2;
	int absCents=abs(allCents);
	int finalDollars=absCents/100;
	int finalCents=absCents%100;
	if(allCents<0)
	{
		finalDollars=-finalDollars;
		finalCents=-finalCents;
	}
	return Money(finalDollars,finalCents);
}
const Money operator -(const Money& amount1,const Money& amount2)
{
	int allCents1=amount1.getCents()+amount2.getDollars()*100;
	int allCents2=amount2.getCents()+amount2.getDollars()*100;
	int diffCents=allCents1-allCents2;
	int absCents=abs(diffCents);
	int finalDollars=absCents/100;
	int finalCents=absCents%100;
	if(diffCents<0)
	{
		finalDollars=-finalDollars;
		finalCents=-finalCents;
	}
	return Money(finalDollars,finalCents);
}
bool operator ==(const Money& amount1,const Money& amount2)
{
	return((amount1.getDollars()==amount2.getDollars())&&(amount1.getCents()==amount2.getCents()));
}
const Money operator -(const Money& amount1)
{
	int newDollars=-amount1.getDollars();
	int newCents=-amount1.getCents();
	return Money(newDollars,newCents);
}
void Money::operator =(const Money& amount2)
{
	dollars=amount2.getDollars();
	cents=amount2.getCents();
}
}