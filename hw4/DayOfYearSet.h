
#ifndef DAYOFYEARSET_H
# define DAYOFYEARSET_H

//# define DRIVER_MODE 0

# include <iostream>
# include "DayOfYear.h"
# include <vector>

using namespace day_of_year_namspc;
using namespace std;

/*		INPUT CONTROL FUNCTIONS		*/
/*
int					my_atoi(string nptr);
int				my_isdigit(string	s);
int						is_legal(char c);
int					my_isalpha(string c);
*/

namespace day_of_year_set_namspc
{

class DayOfYearSet
{
private:
	DayOfYear * elems;
	int			_size;
	//list <DayOfYear> elems;
public:
	int		size();
	void	remove(DayOfYear &day);
	DayOfYearSet(vector <DayOfYear> l);
	DayOfYearSet(DayOfYear *tmp, int size_of_list);
	DayOfYearSet();
	~DayOfYearSet();

	DayOfYearSet	operator+(DayOfYearSet &other);
	void		operator+(DayOfYear &day);

	DayOfYearSet operator-(DayOfYearSet &other);
	void	operator-(DayOfYear &day);

	DayOfYearSet  operator^(DayOfYearSet &other);
	DayOfYearSet  operator!();

	bool operator!=(DayOfYearSet &other);
	bool operator==(DayOfYearSet &other);

	DayOfYear & operator[](int index);

	bool is_in_set(DayOfYear &day);

	friend ostream & operator << (ostream &out, const DayOfYear &day)
	{
		out << endl << "Day :" << day.get_day() << "." << day.get_month() << endl;
		return (out);
	}
	friend ostream & operator << (ostream &out, const DayOfYearSet &set)
	{
		int ind = set._size;
		for (int i = 0; i < ind; i++)
		{
			out << endl << "Day :" << set.elems[i].get_day() << "." << set.elems[i].get_month() << endl;
		}
		return (out);
	}

};
}
#endif
