// It is known that 1900/1/1 is a Monday
#include <iostream>
#include <iomanip>
#include <string>
#define DAYS_IN_A_YEAR 365
using namespace std;

const int days[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const string nameOfMonth[13] = {
	"", "January", "February", "March", "April", "May", "June", "July", "August", "Sepetember", "October", "November", "December"
};

const string nameOfDay[8] = {
	"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

bool isLeapYear(int year){
	if(year % 400 == 0)
		return true;
	if(year % 100 == 0)
		return false;
	if(year % 4 == 0)
		return true;
	return false;
}

int printMonth(int month, int start, bool isLeapYear){
	int day = 0;

	cout << nameOfMonth[month] << endl
		<< endl
		<< "Mon Tue Wed Thu Fri Sat Sun" << endl;

	for(int i = 1; i < start; ++i)
		cout << "    ";
	if(month != 2 || !isLeapYear)
		while(day != days[month]){
			cout << setw(3) << ++day << " ";
			++start;
			if(start > 7){
				start = 1;
				if(day != days[month])
					cout << endl;
			}
		}
	else{
		while(day != 29){
			cout << setw(3) << ++day << " ";
			++start;
			if(start > 7){
				start = 1;
				if(day != 29)
					cout << endl;
			}
		}
	}

	cout << "\n-----------------------------"
		<< endl;
	return start;
}

void printYear(int year){
	system("reset");
	int start = 0;
	for(int i = 1900; i < year; ++i){
		start += (365 + isLeapYear(i));
	}
	start %= 7;
	start += 1;
	cout << "Year: " << year << endl
		<< "-----------------------------\n";
	bool temp = isLeapYear(year);
	for(int i = 1; i < 13; ++i){
		start = printMonth(i, start, temp);
	}
	cout << "Press enter to continue:\n>";
	getchar();
}

void getYear(){
	int year;
	while(1){
		system("reset");
		cout << "Type in the year you want to print: (no earlier than 1900)\n>";
		cin >> year;
		getchar();
		if(year < 1900){
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			continue;
		}
		printYear(year);
		break;
	}
}

bool cmpDate(int year, int year2, int month, int month2, int day, int day2){
	if(year != year2){
		return year < year2;
	}
	if(month != month2){
		return month < month2;
	}
	return day < day2;
}

bool isValidDate(int year, int month, int day){
	if(year < 1900){
		return false;
	}
	if(month < 1 || month > 12){
		return false;
	}
	if(day > days[month] && (month != 2 || !isLeapYear(year) || day != 29)){
		return false;
	}
	return true;
}

void getDate(){
	int year, month, day;
	while(1){
		system("reset");
		cout << "Type in the date you want to check:\n(Format: [year] [month] [day])\n>";
		cin >> year >> month >> day;
		getchar();
		if(!isValidDate(year, month, day)){
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			continue;
		}
		int start = 0, tempM = 1, tempD = 1;
		for(int i = 1900; i < year; ++i){
			start += (365 + isLeapYear(i));
		}
		while(tempM != month || tempD != day){
			start += 1;
			++tempD;
			if(tempD > days[tempM]){
				if(month == 2 && tempD == 29 && isLeapYear(year)){
					continue;
				}
				tempD = 1;
				++tempM;
			}
		}
		cout << "The day of the date is: " 
			<< nameOfDay[start % 7 + 1] << endl;
		cout << "Press enter to continue:\n>";
		getchar();
		break;
	}
}

void getDate2(){
	int year, month, day;
	int year2, month2, day2;
	int res = 0;

	while(1){
		system("reset");
		cout << "Type in the first date you want to compare:\n(Format: [year] [month] [day])\n>";
		cin >> year >> month >> day;
		getchar();
		if(!isValidDate(year, month, day)){
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			continue;
		}
		break;
	}

	while(1){
		system("reset");
		cout << "First date you type in is: " << year << "-" << month << "-" << day << endl
			<< "Type in the second date you want to compare:\n(Format: [year] [month] [day])\n>";
		cin >> year2 >> month2 >> day2;
		getchar();
		if(!isValidDate(year2, month2, day2)){
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			continue;
		}
		break;
	}

	if(cmpDate(year, year2, month, month2, day, day2)){
		while(year != year2 || month != month2 || day != day2){
			++res;
			++day;
			if(day > days[month]){
				if(month == 2 && isLeapYear(year) && day == 29){
					continue;
				}
				day = 1;
				++month;
				if(month > 12){
					++year;
					month = 1;
				}
			}
		}
	} 
	else{
		while(year != year2 || month != month2 || day != day2){
			++res;
			++day2;
			if(day2 > days[month2]){
				if(month2 == 2 && isLeapYear(year2) && day2 == 29){
					continue;
				}
				day2 = 1;
				++month2;
				if(month2 > 12){
					++year2;
					month2 = 1;
				}
			}
		}
	}
	cout << "Number of days between those two dates: " << res << endl
		<< "Press enter to continue:\n>";
	getchar();
}

void interface(){
	string input;
	while(1){
		system("reset");
		cout << "Choose the function that you want to use:\n"
		<< "a. Print the calendar of current year.\n"
		<< "b. Print the calendar of a specific year.\n"
		<< "c. To find the day of week of a specific date.\n"
		<< "d. To calculate the number of days between two dates.\n"
		<< "q. Quit\n>";
		cin >> input;
		getchar();
		if(input.size() != 1){
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			continue;
		}
		switch(input[0]){
		case 'a':
			printYear(2017);
			break;
		case 'b':
			getYear();
			break;
		case 'c':
			getDate();
			break;
		case 'd':
			getDate2();
			break;
		case 'q':
			cout << "Thanks for your using.\n";
			return;
			break;
		default:
			cout << "Invalid input!\n";
			cout << "Press enter to continue:\n>";
			getchar();
			break;
		}
	}
}


int main(){
	interface();
	return 0;
}


