#include "DayOfYearSet.h"
//#include "DayOfYear.h"
#include <fstream>

using namespace std;

void	add_day_to_file(ofstream &new_file, DayOfYear &day)
{
	new_file << '\n' << day.get_spec_day() << " -> " << "day: "  << day.get_day() << "month: " <<	day.get_month() ;
}

int main(int argc, char const *argv[])
{
	ofstream new_file;
	new_file.open("save.txt",ios::out);



	if (DRIVER_MODE == 0)
		cout << endl <<"mode 0" << endl;
	if (DRIVER_MODE == 1)
		cout << endl <<"mode 1" << endl;
	


	if (DRIVER_MODE == 0)
	{
		cout << endl << "new day object x(365) created" << endl;
		DayOfYear x(365);
		add_day_to_file(new_file, x);
		cout << endl  <<"x day: " << x.get_day()<<"xmonth: " << x.get_month() <<endl;
		
		DayOfYear *tmp;
		tmp = new DayOfYear[1];
		tmp[0] = x;
		cout << endl << "new day object y(33) created" << endl;
		DayOfYear y(33);
		//tmp[0] = y;
		DayOfYear *tmp2;
		tmp2 = new DayOfYear[1];
		tmp2[0] = x;
		
		cout << endl << "new day_of_year_set test_set created with day x" << endl;
		day_of_year_set_namspc::DayOfYearSet test_set(tmp, 1);
		cout << endl << "new day_of_year_set test_set2 created with day y" << endl;
		day_of_year_set_namspc::DayOfYearSet test_set2(tmp2, 1);
		cout << endl << "new day_of_year_set test_set3 created with day x" << endl;
		day_of_year_set_namspc::DayOfYearSet test_set3(tmp, 1);
		//test_set.operator+(x);

		//day_of_year_set_namspc::DayOfYearSet test_set4{x,y};
		cout << endl << " operator+ " << endl;
		cout << "(test_set + x) :";
		test_set + x;
		cout << endl;
		cout << "(test_set + y) :";
		test_set + y;
		cout << endl;
		cout <<"size of test_set:"<< test_set.size()<<endl;
		cout <<"size of test_set2 :"<< test_set2.size()<<endl;
		//test_set2 + x;
		cout << endl << "new day object z(240) created" << endl;
		DayOfYear z(240);
		cout << "test_set + z"<<endl;
		test_set + z;
	//	test_set.operator+(y);
		//test_set.operator-(x);
		cout << endl <<"size of test_set:"<< test_set.size()<<endl;

		cout << endl << " operator<< " << endl;
		cout <<"testset1:";
		cout <<test_set;
		cout <<endl<<"testset2:";
		cout <<test_set2;

	//	test_set3 = test_set.operator^(test_set2);
		cout << endl << " operator!= " << endl;
		if (test_set!=test_set2)
			cout <<endl<<"!= work for test_set != test_set2 "<<endl;

		cout << endl << " operator == " << endl;
		if (test_set == test_set2)
			cout <<endl<<"== work for test_set == test_set2 "<<endl;

		cout << endl << " operator- " << endl;
		test_set3 = test_set2.operator-(test_set);
		cout <<endl<<" test_set3 = test_set2.operator-(test_set)"<<endl;
		cout <<"size of set3: " << test_set3.size() <<endl;
		//test_set3 = test_set - test_set2;
		
		cout << endl << "test_set3 = test_set.operator!()" << endl;
		test_set3 = test_set.operator!();
		cout <<"size of 3:"<< test_set3.size()<<endl;
		cout << test_set3;

	}
	if (DRIVER_MODE == 1)
	{
		
	}

	new_file.close();
	return 0;
}

