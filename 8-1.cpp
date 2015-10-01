//ÔËËã·ûÖØÔØ
#include "8-1.h"
using namespace Space1;
int main()
{
	Money yourAmount,myAmount(10,9);
	cout<<"enter an amount of moeny: ";
	yourAmount.input();
	cout<<"your amount is: ";
	yourAmount.output();
	cout<<endl;
	cout<<"my amount is ";
	myAmount.output();
	cout<<endl;

	cout<<yourAmount.getDollars()<<endl
		<<yourAmount.getCents()<<endl
		<<yourAmount.getAmount()<<endl<<endl;

	if(yourAmount==myAmount)
		cout<<"we have the same amounts.\n";
	else
		cout<<"one of us is richer.\n";
	Money ourAmount=yourAmount+myAmount;

	cout<<ourAmount.getDollars()<<endl
		<<ourAmount.getCents()<<endl
		<<ourAmount.getAmount()<<endl<<endl;

	yourAmount.output();cout<<"+";myAmount.output();
	cout<<" equals ";ourAmount.output();cout<<endl;

	Money diffAmount=yourAmount-myAmount;
	yourAmount.output();cout<<"-";myAmount.output();
	cout<<" equals ";diffAmount.output();cout<<endl;

	cin.get();cin.get();
	return 0;
}
