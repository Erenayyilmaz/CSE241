# include "DayOfYearSet.h"
# include <vector>
# include <iostream>

using namespace day_of_year_set_namspc;
//using namespace std;
//using namespace day_of_year_namspc;


 int	my_isdigit(char*	s)
{
	// THIS FUNCTION CONTROLS IS GIVEN STRING HAS ONLY DIGITS
	int index = 0;
	while (s[index])
	{
		if (s[index] >= '0' && s[index] <= '9')
		{
			return (1);
		}
		index++;
	}
	return (0);	
}

 int	my_isalpha(char* c)
{
		// THIS FUNCTION CONTROLS IS GIVEN STRING HAS ONLY ALPHABETICAL CHARS
	int ind = 0;
	while (c[ind])
	{
		if (c[ind] >= 65 && c[ind] <= 90)
			return (1);

		else if (c[ind] <= 122 && c[ind] >= 97)
			return (1);

		ind++;
	}	
	return (0);
}

 int	my_atoi(char* nptr)
{
	// IMITATION OF ORIGINAL ATOI FUNCTION 
	// I TAKE ALL INPUTS AS STRING AFTER CONTROL I CHANGED THEIR TYPES
	 int	index;
	 int	sum;

	sum = 0;
	index = 0;
	while ((nptr[index]) < '0' && (nptr[index]) > '9')
		index++;
	while ((nptr[index]) >= '0' && (nptr[index]) <= '9')
	{
		sum *= 10;
		sum += (nptr[index] - '0');
		index++;
	}
	return (sum);

}



day_of_year_set_namspc::DayOfYearSet::DayOfYearSet(vector <DayOfYear> l)
{
	//cout << "DayOfYearSet construtor2 called";
}

day_of_year_set_namspc::DayOfYearSet::DayOfYearSet()
{
	_size = 0;
	//cout << endl << "DayOfYearSet construtor called";
}



day_of_year_set_namspc::DayOfYearSet::~DayOfYearSet()
{
	//cout << "DayOfYearSet destructor called";
}

bool day_of_year_set_namspc::DayOfYearSet::is_in_set(DayOfYear &day)
{
	int	index = 0;
	while (index < _size)
	{
		if (elems[index].get_spec_day() == day.get_spec_day())
			return (true);
		index++;
	}
	return (false);
}

day_of_year_set_namspc::DayOfYearSet day_of_year_set_namspc::DayOfYearSet::operator+(DayOfYearSet &other)
{
	int	new_size, ctr = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < other._size; j++)
		{
			if ((other.elems[j]).get_spec_day() == elems[i].get_spec_day())
				ctr++;
		}
	}
	new_size = other._size + _size;
	new_size -= ctr;
	DayOfYear *tmp = new DayOfYear[new_size];
	int i = 0;
	for (; i < _size; i++)
	{
		tmp[i] = elems[i];
	}
	int k = 0;
	for (int j = 0; j < other._size; j++)
	{
		if (other.elems[j] != elems[j])
		{
			tmp[j + k] = other.elems[j];
			k++;
		}
	}
	return (DayOfYearSet(tmp, new_size));
}

void DayOfYearSet::operator+(DayOfYear &day)
{
	if (!is_in_set(day))
	{
		_size++;
		DayOfYear *tmp = new DayOfYear[_size];
		int i = 0;
		for (; i < _size - 1; i++)
			tmp[i] = elems[i];
		tmp[i] = day;
		delete[] elems;
		elems = tmp;
	}
	else
	{
		cout << endl << "already in list" << endl;
	}
	
}

void day_of_year_set_namspc::DayOfYearSet::operator-(DayOfYear &day)
{
	if (is_in_set(day))
	{
		_size--;
		DayOfYear *tmp = new DayOfYear[_size];
		int i = 0, j = 0;
		for (; i < _size; i++, j++)
		{
			if (elems[j].get_spec_day() == day.get_spec_day())
				j++;
			tmp[i] = elems[j];
		}
		delete[] elems;
		elems = tmp;
	}
	else
	{
		cout << endl << "no param in list" << endl;
	}
}


day_of_year_set_namspc::DayOfYearSet  day_of_year_set_namspc::DayOfYearSet::operator-(DayOfYearSet &other)
{
	int	ctr = 0;
	for (int i = 0; i < other._size; i++)
	{
		if (!is_in_set(other.elems[i]))
			ctr++;
	}
	cout << "Difference: " <<ctr<<endl;
	int index = 0;
	DayOfYear *tmp = new DayOfYear[ctr];
	for (int i = 0; i < other._size; i++)
	{
		if (!is_in_set(other.elems[i]))
		{
			tmp[index] = other.elems[i];
			index++;
		}
	}
	return (DayOfYearSet(tmp, ctr));
}

bool day_of_year_set_namspc::DayOfYearSet::operator==(DayOfYearSet &other)
{
	int index = 0;
	while (index < _size )
	{
		if ((elems[index].get_spec_day() != other.elems[index].get_spec_day()) )
		{
			return (false);
		}
		index++;
	}
	if (_size == other._size)
		return (true);
	return (false);
}

bool day_of_year_set_namspc::DayOfYearSet::operator!=(DayOfYearSet &other)
{
	return (!(*this == other));
}

day_of_year_namspc::DayOfYear & day_of_year_set_namspc::DayOfYearSet::operator[](int index)
{
	if (index >= _size)
	{
		cout << "out of bound";
		exit (1);
	}
	return (elems[index]);
}

int day_of_year_set_namspc::DayOfYearSet::size()
{
	return (_size);
}

void day_of_year_set_namspc::DayOfYearSet::remove(DayOfYear &day)
{
	int	index = 0, diff_ctr = 0;
	
	while (index < _size)
	{
		if (elems[index].get_spec_day() != day.get_spec_day())
		{
			diff_ctr++;
		}
		index++;
	}
	DayOfYear *tmp = new DayOfYear[diff_ctr];
	index = 0;
	while (index < diff_ctr)
	{
		if (elems[index].get_spec_day() != day.get_spec_day())
			tmp[index] = elems[index];
		index++;
	}
	delete [] elems;
	elems = tmp;
}

// ostream & operator<<(ostream &out, const DayOfYear &day)
// {
// 	out << "Day :" << day.get_day() << "." << day.get_month() << endl;
// }

day_of_year_set_namspc::DayOfYearSet  day_of_year_set_namspc::DayOfYearSet::operator^(DayOfYearSet &other)
{
	int	index = 0;
	for (int i = 0; i < other._size; i++)
	{
		if (is_in_set(other.elems[i]))
			index++;
	}
	//cout << endl << "index: " << index<<endl<<endl;
	DayOfYear *tmp = new DayOfYear[index];
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < other._size; j++)
		{
			if (is_in_set(other.elems[j]))
				tmp[i] = other.elems[j];
			else
				j++;
		}
	}
	cout <<endl<<endl; // BUNU sılme
	return (DayOfYearSet(tmp, index));
}

day_of_year_set_namspc::DayOfYearSet day_of_year_set_namspc::DayOfYearSet::operator!()
{
	int new_size = 365 - _size;
	if (new_size <= 0)
		return (DayOfYearSet(nullptr, 0));
	DayOfYear *tmp = new DayOfYear[new_size];
	for (int i = 0; i < 365; i++)
	{
		if (i != elems[i].get_spec_day())
		{
			tmp[i] = DayOfYear(i + 1);
		}
	}
	return (DayOfYearSet(tmp, new_size));
}

day_of_year_set_namspc::DayOfYearSet::DayOfYearSet(DayOfYear *tmp, int size_of_list)
{
	_size = size_of_list;
	elems = tmp;
}
