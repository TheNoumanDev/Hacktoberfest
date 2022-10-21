#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:
	int GetDay(int dy)
	{
		if (dy >= 31 || dy <= 0)
		{
			cout << "Error: Invalid Day Entered\n";
			cout << "Enter Again \n";
			return 1;
		}

		else
		{
			day = dy;
			return 0;
		}
		
	}
	int GetMonth(int mon)
	{
		if (mon > 12 || mon <= 0)
		{
			cout << "Error: Invalid Month Entered\n";
			cout << "Enter Again \n";
			return 1;
		}
		else
		{
			month = mon;
			cout << mon << endl;
			return 0;
		}
	}
	int GetYear(int ye)
	{
		if (ye >= 2023 &&ye>=1000)
		{
			cout << "Error: Year should be less than 2022(current Year)\n";
			cout << "Enter Again \n";
			return 1;
		}
		else
		{
			year = ye;
			return 0;
		}		
	}

	void PrintDate()
	{
		cout << month << "/" << day << "/" << year << endl;
		switch (month)
		{
		case 1:
			cout << "January " << day << ", " << year << endl;
			cout << day << " Januray " << year << endl;
			break;

		case 2:
			cout << "February " << day << ", " << year << endl;
			cout << day << " February " << year << endl;
			break;

		case 3:
			cout << "March " << day << ", " << year << endl;
			cout << day << " March " << year << endl;
			break;

		case 4:
			cout << "April " << day << ", " << year << endl;
			cout << day << " April " << year << endl;
			break;

		case 5:
			cout << "May " << day << ", " << year << endl;
			cout << day << " May " << year << endl;
			break;

		case 6:
			cout << "June " << day << ", " << year << endl;
			cout << day << " June " << year << endl;
			break;

		case 7:
			cout << "July " << day << ", " << year << endl;
			cout << day << " July " << year << endl;
			break;

		case 8:
			cout << "August " << day << ", " << year << endl;
			cout << day << " August " << year << endl;
			break;

		case 9:
			cout << "September " << day << ", " << year << endl;
			cout << day << " September " << year << endl;
			break;

		case 10:
			cout << "October " << day << ", " << year << endl;
			cout << day << " October " << year << endl;
			break;

		case 11:
			cout << "November " << day << ", " << year << endl;
			cout << day << " November " << year << endl;
			break;

		case 12:
			cout << "December " << day << ", " << year << endl;
			cout << day << " December " << year << endl;
			break;
		}

	}
};


int main()
{
	cout << "   --------------------------------------" << endl;
	cout << "\tEnter  Date (dd/mm/yy Format)" << endl;
	cout << "   --------------------------------------" << endl;
	int day, month, year;
	Date date;
	cout<<left<<setw(15) << "Enter Day : ";
	cin >> day;
	while (date.GetDay(day))
	{
		cin >> day;
	}

	cout << left << setw(15) << "Enter Month : ";
	cin >> month;
	while (date.GetMonth(month))
	{
		cin >> month;
	}

	cout << left << setw(15) << "Enter Year : ";
	cin >> year;
	while (date.GetYear(year))
	{
		cin >> year;
	}
	cout << "    -----------------------" << endl;
	cout << "\tExpected Output" << endl;
	cout << "    -----------------------" << endl;
	date.PrintDate();
}