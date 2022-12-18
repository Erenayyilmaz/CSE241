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
	new_file.open("save.txt",ios::app);



	if (DRIVER_MODE == 0)
		cout << endl <<"mode auto(0)" << endl;
	if (DRIVER_MODE == 1)
		cout << endl <<"mode 1" << endl;
	


	if (DRIVER_MODE == 0)
	{
		cout << endl << "new day object x(360) created" << endl;
		DayOfYear x(360);
		add_day_to_file(new_file, x);
		//add_day_to_file(new_file, x);		
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
		cout << endl << endl << "----------------"<< " operator+ " << endl;
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
		cout << endl << "----------------"<<endl<<" operator- " << endl;
		cout << endl <<"DayOfYear t(210) initialized and added into set1;"<<endl;
		DayOfYear t(210);
		test_set.operator+(t);
		cout << endl <<"size of test_set:"<< test_set.size()<<endl;

		cout << endl <<"size of test_set:"<< test_set.size()<<endl;
		cout << "test_set.operator-(t)"<<endl;
		test_set.operator-(t);
		cout << endl <<"size of test_set:"<< test_set.size()<<endl;

		cout << endl<< endl << "----------------" << " operator<< " << endl;
		cout <<"testset1:";
		cout <<test_set;
		cout <<endl<<"testset2:";
		cout <<test_set2;

	//	test_set3 = test_set.operator^(test_set2);
		cout << endl<< endl << "----------------" << " operator!= " << endl;
		if (test_set!=test_set2)
			cout <<endl<<"!= work for test_set != test_set2 "<<endl;
		if (test_set!=test_set3)
			cout <<endl<<"!= work for test_set != test_set3 "<<endl;

		cout << endl<< endl << "----------------" << " operator == " << endl;
		if (test_set == test_set2)
			cout <<endl<<"== work for test_set == test_set2 "<<endl;
		if (test_set == test_set3)
			cout <<endl<<"== work for test_set == test_set3 "<<endl;

		cout << endl<< endl << "----------------" << " operator- " << endl;
		test_set3 = test_set2.operator-(test_set);
		cout <<endl<<" test_set3 = test_set2.operator-(test_set)"<<endl;
		cout <<"size of set3: " << test_set3.size() <<endl;
		//test_set3 = test_set - test_set2;

		

		cout << endl<< endl << "----------------" << "test_set3 = test_set.operator!()" << endl;
		test_set3 = test_set.operator!();
		cout <<"size of 3:"<< test_set3.size()<<endl;
		cout << test_set3;

		cout << endl << endl << "----------------"<< " operator^ " << endl;
		cout <<endl<<" test_set3 = test_set2.operator^(test_set)"<<endl;
		test_set3 = test_set2.operator^(test_set);
		cout <<"size of set3: " << test_set3.size() <<endl;

		cout << "test_set: ";
		cout << test_set;
		cout << endl;
		cout << "test_set2: ";
		cout << test_set2;
		cout << endl;
		cout << "test_set3: ";

		cout << test_set3;
		cout << endl << endl << "----------------"<< " operator[] " << endl;
		cout << "(test_set.operator[](1) :" << endl;
		cout << "day: " << (test_set.operator[](1)).get_day() << "." << (test_set.operator[](1)).get_month()<<endl;
	}/*
	if (DRIVER_MODE == 1)
	{
		int ctr = 0, ch = 0;
		char tp[20], tp2[20];
		cout << endl <<"You have a dayofyearset"<<endl;
		do
		{
			int tp_to_day = 0, tp_to_month = 0;
			DayOfYear day1(1, 1);
			DayOfYear day2(1, 2);
			DayOfYear day3(1, 3);
			DayOfYear day4(1, 4);
			DayOfYear day5(1, 5);
			day_of_year_set_namspc::DayOfYearSet new_set(nullptr, 0);
			new_set.operator+(day1);
			new_set.operator+(day2);
			new_set.operator+(day3);
			new_set.operator+(day4);
			new_set.operator+(day5);
			cout << "\n1- Check DayOfYear (==) ";
			cout << "\n2- Delete DayOfYear ";
			cout << "enter number";
			cin >> tp;
			if(my_isdigit(tp))
			{
				ch = my_atoi(tp);
				ctr = 1;


				switch (ch)
				{
				case 1:
					cout << endl <<"enter day :"<<endl;
					cin >> tp2;
					if(my_isdigit(tp2))
					{
						tp_to_day = my_atoi(tp2);
					}
					else
					{
						cout<<"\nwrong\n";
						exit(1);
					}

					cout << endl <<"enter month :"<<endl;
					cin >> tp2;
					if(my_isdigit(tp2))
					{
						tp_to_month = my_atoi(tp2);
					}
					else
					{
						cout<<"\nwrong\n";
						exit(1);
					}			
					DayOfYear tmp_day(tp_to_day, tp_to_month);
					for (int x = 0; x < new_set.size(); x++ )
					{
						if (new_set.elems[x].get_spec_day() == tmp_day.get_spec_day())
							cout << tmp_day;
					}
					
					//new_set.operator+(new_day);
					//cout << "new_set: "<<endl;
					//cout << new_set;
					break;

				case 2:
					/*tp_to_day = 0, tp_to_month = 0;
					cout << endl <<"enter day :"<<endl;
					cin >> tp2;
					if(my_isdigit(tp2))
					{
						tp_to_day = my_atoi(tp2);
					}
					else
					{
						cout<<"\nwrong\n";
						exit(1);
					}

					cout << endl <<"enter month :"<<endl;
					cin >> tp2;
					if(my_isdigit(tp2))
					{
						tp_to_month = my_atoi(tp2);
					}
					else
					{
						cout<<"\nwrong\n";
						exit(1);
					}			
					
					//DayOfYear new_del_day(tp_to_day, tp_to_month);
					//new_set.operator-(new_day);
					cout << "new_set: "<<endl;
					cout << new_set;
					break;

				//default:
				//	break;
				}


			}
			else
			{
				cout << "\nentered wrong. exitting\n";
				ctr = 0;
			}
			
		} while (ctr == 1);
		
	}
*/
	new_file.close();
	return 0;
}

