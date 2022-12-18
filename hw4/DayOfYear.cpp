#include "DayOfYear.h"

using namespace std;

day_of_year_namspc::DayOfYear::DayOfYear():_day(1),_month(1)
{
	//cout << "DayOfYear construtor called";
}

day_of_year_namspc::DayOfYear::~DayOfYear()
{
	//cout << "DayOfYear destructor called";
}

int day_of_year_namspc::DayOfYear::get_day() const
{
	return (_day);
}

int day_of_year_namspc::DayOfYear::get_month() const
{
	return (_month);
}

int	day_of_year_namspc::DayOfYear::get_spec_day() const
{
	return (_spec_day);
}

void day_of_year_namspc::DayOfYear::set_spec_day(const int spec_day)
{
	_spec_day = spec_day;
}

void day_of_year_namspc::DayOfYear::set_day( int day)
{
	if (_month == 1 || _month == 3 ||_month == 5 ||_month == 7 ||_month == 8 ||_month == 10 ||_month == 12)
	{
		day = day % 31;
	}
	else if ( _month == 4 ||_month == 6 ||_month == 9 ||_month == 11)
	{
		day = day % 30;
	}
	else
	{
		day = day % 28;
	}
	_day = day;
}

void day_of_year_namspc::DayOfYear::set_month(const int month)
{
	if (month > 12 || month < 0)
		_month = month % 12;
	else
		_month = month;
}

bool day_of_year_namspc::DayOfYear::operator!=(DayOfYear other)
{
	return (!(get_day() == other.get_day() && get_month() == other.get_month()));
}

bool day_of_year_namspc::DayOfYear::operator==(DayOfYear other)
{
	return (get_day() == other.get_day() && get_month() == other.get_month());
}

int	 day_of_year_namspc::DayOfYear::day_of_spec_day(day_of_year_namspc::DayOfYear day)
{
	cout << "day_of_spec_day basi"<<endl;
	cout <<"day.get_month(): "<<day.get_month()<<endl;
	int	day_counter = 0;
	for (int i = 0; i < day.get_month(); i++)
	{
		switch (i)
		{
		case 1:
			day_counter += 31;
			break;
		case 2:
			day_counter += 28;
			break;
		case 3:
			day_counter += 31;
			break;
		case 4:
			day_counter += 30;
			break;			
		case 5:
			day_counter += 31;
			break;
		case 6:
			day_counter += 30;
			break;			
		case 7:
			day_counter += 31;
			break;
		case 8:
			day_counter += 31;
			break;
		case 9:
			day_counter += 30;
			break;			
		case 10:
			day_counter += 31;
			break;
		case 11:
			day_counter += 30;
			break;
		case 12:
			day_counter += 31;
			break;
		default:
			break;
		}
		//cout << "(day_counter_Each):" <<  (day_counter)<<endl; 
	}
	day_counter += day.get_day();
	cout << "(day_counter end):" <<  (day_counter)<<endl; 
	return (day_counter);
}

day_of_year_namspc::DayOfYear day_of_year_namspc::DayOfYear::operator!()
{
	int	now_day = day_of_spec_day(*this);
	int	compl_day = 365 - now_day;
	DayOfYear ret(compl_day);
	return (ret);
}

day_of_year_namspc::DayOfYear::DayOfYear(int day, int month)
{
	set_day(day);
	set_month(month);
}

day_of_year_namspc::DayOfYear::DayOfYear(int a_day)
{
	set_spec_day(a_day);
	int i, day_counter = a_day;
	int old_day;
	for (i = 1; i <= 12; i++)
	{
		old_day = day_counter;
		switch (i)
		{
		case 1:
			day_counter -= 31;
			break;
		case 2:
			day_counter -= 28;
			break;
		case 3:
			day_counter -= 31;
			break;
		case 4:
			day_counter -= 30;
			break;			
		case 5:
			day_counter -= 31;
			break;
		case 6:
			day_counter -= 30;
			break;			
		case 7:
			day_counter -= 31;
			break;
		case 8:
			day_counter -= 31;
			break;
		case 9:
			day_counter -= 30;
			break;			
		case 10:
			day_counter -= 31;
			break;
		case 11:
			day_counter -= 30;
			break;
		case 12:
			day_counter -= 31;
			break;
		default:
			break;
		}
		if (day_counter <= 0)
		{
			set_month (i);
			set_day(old_day);
			break; // break kontrol et
		}
	}
}
day_of_year_namspc::DayOfYear::DayOfYear(DayOfYear &other)
{
	//cout <<endl<<"copyconst called"<<endl;
	//cout <<endl<<"copyconst for :"<<other.get_day() <<"."<<other.get_month()<<endl;
	set_month(other.get_month());
	set_day(other.get_day());
	set_spec_day(other.day_of_spec_day(other));
}