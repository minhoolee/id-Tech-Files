#include <iostream>

using namespace std;

int main()
{
	int userSelect;
	cout << "Enter what you would like to eat" << endl;
	cout << "1) Pancakes" << endl << "2) Burgers" << endl << "3) French Fries" << endl;

	cin >> userSelect;

	switch (userSelect)
	{
	case (1) :
		cout << "Pancakes" << endl;
		break;

	case (2) :
		cout << "Burgers" << endl;
		break;

	case (3) :
		cout << "French Fries" << endl;
		break;

	default : 
		cout << "Invalid Input" << endl;
	}


	return 0;
}