#include "std_lib_facilities.h"

struct Date{
	int year, month, day;

	Date(int y, int m, int d); // konstruktor hat meg egyegy objektum hogyan készíthető el
	void add_day(int n);
};

Date::Date(int y, int m, int d){
	if (y > 0)
		year = y;
	else
		error("invalid year");

	if(m <= 12 && m > 0)
		month = m;
	else
		error("invalid month");

	if(d <= 31 && d > 0)
		day = d;
	else
		error("invalid day");
}

void Date::add_day(int n){
	day += n;

	if (day > 31){
		month++;
		day -= 31;
		if(month > 12){
			year++;
			month -=12;
		}
	}
}

int main(){
try{
	Date today {2021, 10, 28};

	cout << "Date: " << today.year << '.' << today.month << '.' << today.day << endl;

	today.add_day(1);
		cout << "Date: " << today.year << '.' << today.month << '.' << today.day << endl;

    //Date today {12,24,2007}; // oops! run-time error
    Date last {2000,12,31}; // OK (colloquial style)
    Date next = {2014,2,14}; // also OK (slightly verbose)
    Date christmas = Date{1976,12,24}; // also OK (verbose style)

    //cout << "Date today: " << today.year << '.' << today.month << '.' << today.day << endl;
    cout << "Date last: " << last.year << '.' << last.month << '.' << last.day << endl;
    cout << "Date next: " << next.year << '.' << next.month << '.' << next.day << endl;
    cout << "Date christmas: " << christmas.year << '.' << christmas.month << '.' << christmas.day << endl;
    last.add_day(1);
    cout << "Date last next day: " << last.year << '.' << last.month << '.' << last.day << endl;
    //add_day(2);

	return 0;
}catch(exception& e){
	cout << e.what() << endl;
	return 1;
}
}	