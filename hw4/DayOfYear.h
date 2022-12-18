
#ifndef DAYOFYEAR_H
# define DAYOFYEAR_H

# include <iostream>

namespace day_of_year_namspc{

class DayOfYear
{
private:
	int _day;
	int	_month;
	int _spec_day;
public:
	int		get_day() const;
	void		set_day(const int day);
	int				get_month() const;
	void	set_month(const int month);
	int		get_spec_day()const;
	void	set_spec_day(const int spec_day);

	bool operator==(DayOfYear other);
	bool operator!=(DayOfYear other);

	DayOfYear();
	DayOfYear(int a_day);
	DayOfYear(int day, int month);

	DayOfYear operator!();
	DayOfYear(DayOfYear &other);

	int	day_of_spec_day(DayOfYear day);


	~ DayOfYear();
};
}
#endif 