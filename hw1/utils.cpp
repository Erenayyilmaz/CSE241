#include "utils.h"

using namespace std;

long unsigned int	my_isdigit(string	s)
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

long unsigned int	is_legal(char c)
{
		// THIS FUNCTION CONTROLS IS GIVEN CHAR IS LEGAL FOR PROGRAM
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z')
		return (1);
	return (0);
}

long unsigned int	my_isalpha(string c)
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

long unsigned int			my_atoi(string nptr)
{
	// IMITATION OF ORIGINAL ATOI FUNCTION 
	// I TAKE ALL INPUTS AS STRING AFTER CONTROL I CHANGED THEIR TYPES
	long unsigned int	index;
	long unsigned int	sum;

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


void						get_info(vector <Tetromino> arr)
{
	// ALL INPUT ARE TAKEN IN HERE
	vector< vector <char> > last_map=
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};
	long unsigned int tet_num; // TETRO NUMBER
	//vector<char> arr;
	string	tmp;
	char in;
	int ctr = 1;
	do
	{
		cout << "How many tetrominos?" <<endl;
		cin >> tmp;
		if (!my_atoi(tmp) && !my_isalpha(tmp)) // CONTROL NUM
		{
			ctr = 0;
		}
		tet_num = my_atoi(tmp);
		//cout << endl << "tet_num = " <<int(tet_num) << "casted that is : " << (long unsigned int)tet_num;
		arr.resize(tet_num);
		cout << "What are their types?";
		cout << endl;
		for (long unsigned int i = 0; i < tet_num; i++)
		{
			cin >> in;
			if (!is_legal(in)) // CONTROL INPUT
				ctr = 1;
			else
			{
				//insert here!! tetrominos vectırune eklemeler yaoılacak tek tek
				//  e_typ	tt;
				//  tt = static_cast <e_typ>(in);
				//  arr[i] = Tetromino(tt);
				//static_cast <char>(in);
				if (in == 'i' || in == 'I')
				{
					Tetromino temporary(e_typ::i); // TEMP CLASS INITIALIZATION AND STORING IT IN TETROMINO VECTOR
					arr[i] = temporary;
					//last_map = merge_coll_maps(temporary, last_map);
					//print_map(temporary.get_map());
					//cout << "saszcxxca"<<endl;
					//print_map(last_map);
					//e_typ c = static_cast <e_typ>(in);
					//arr.push_back((Tetromino)c);
					//arr.push_back(temporary);
				}
				if (in == 'o' || in == 'O')
				{
					Tetromino temporary(e_typ::o);
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}				
				if (in == 't' || in == 'T')
				{
					Tetromino temporary(e_typ::t);
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}
				if (in == 'j' || in == 'J')
				{
					Tetromino temporary(e_typ::j);
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}
				if (in == 'l' || in == 'L')
				{
					Tetromino temporary(e_typ::l);
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}				
				if (in == 's' || in == 'S')
				{
					Tetromino temporary(e_typ::s);
					//temporary.print();
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}
				if (in == 'z' || in == 'Z')
				{
					Tetromino temporary(e_typ::z);
					arr[i] = temporary;
					//print_map(temporary.get_map());
				}
				//arr.push_back(Tetromino(tt));
				ctr = 0;// NO PROBLEM
//				last_map = merge_coll_maps(temporary, last_map);
			}
		}
		if(ctr == 1)
			cout << "wrong, try again!";
	} while (ctr == 1);
	Tetromino a;
	cout << "Your tetrominos ";
	for (int i = 0;i < tet_num;i++)
	{
		//cout << "asdsad";
		a = arr[i];
		//cout << "furkan";
		cout << endl;
		a.print();
		cout << endl;
		//cout << a.get_ty();
	}

	for (int i = 0;i < tet_num;i++)
	{
		//cout << "asdsad";
		a = arr[i];
		//cout << "furkan";
		cout << endl;
		cout << "rotated versions :"<<endl;
		//cout << endl;
		a.rotate(1);
		a.print();
		cout << endl;
		//cout << a.get_ty();
		a.rotate(1);
		a.print();
		cout << endl;
		a.rotate(1);
		a.print();
		cout << endl;
		a.rotate(1);
		a.print();
		cout << endl;
	}

	vector< vector <char> > merged_map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};

	merged_map = arr[0].get_coll_map();
	
	//cout << endl;
	//	print_map(merged_map);
	//cout <<endl;
	//merged_map = a.get_coll_map();
	//cout << "bura geld bb" << endl ;
	for (int p = 1; p < tet_num; p++)
		merged_map = merge_coll_maps(arr[p],merged_map);//arr[0] ile erişemiyorum..
	cout<<endl;
	print_map(merged_map);
}

vector< vector <char> > Tetromino::get_coll_map()
{
	return (collision_map);
}


Tetromino::Tetromino(e_typ typ)
{
	vector< vector<char> > temp_map
		{
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'}
		};

	switch (typ)
	{
	case e_typ::i :
		temp_map =
//		map =
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'i','i','i','i'}
			};
		map = temp_map;
		break;
	
	case e_typ::o :
		temp_map =
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'o','o','0','0'},
				{'o','o','0','0'}
			};
		map = temp_map;
		break;
		
	case e_typ::t :
		temp_map =
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','t','0','0'},
				{'t','t','t','0'}
			};
		map = temp_map;
		break;

	case e_typ::j :
		temp_map =
			{
				{'0','0','0','0'},
				{'0','j','0','0'},
				{'0','j','0','0'},
				{'j','j','0','0'}

			};
		map = temp_map;
		break;
			
	case e_typ::l :
		temp_map =
			{
				{'0','0','0','0'},
				{'l','0','0','0'},
				{'l','0','0','0'},
				{'l','l','0','0'}
			};
		map = temp_map;
		break;

			
	case e_typ::s :
		map =
//		temp_map =
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','s','s','0'},
				{'s','s','0','0'}
			};
		break;

			
	case e_typ::z :
		//temp_map =
		map =
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'z','z','0','0'},
				{'0','z','z','0'}
			};
		//map = temp_map;
		break;



	default:
		break;
	}
	init_collision_map();
	//print();
	//rotate(1);
	//print();
}

Tetromino::Tetromino()
{
	vector< vector<char> > map
	{
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'}
	};
}

void Tetromino::set_map(vector<vector<char>> map)
{
	long unsigned int i, j;
	for (i = 0; i < map.size(); i++) 
	{
		for (j = 0; j < map[i].size(); j++)
		{
			map[i][j] = 1;
			cout << map[i][j] << ' ';
		}    
		cout << endl;
	}
}

void Tetromino::init_collision_map()
{
	long unsigned int	i = 0, j= 0;
	long unsigned int	size_map = map.size();
	for (; i < size_map; i++)
	{
		j = 0;
		for (; j < (map[i]).size(); j++)
		{
			collision_map[i][j] = map[i][j];
		}
	}
}

void Tetromino::rotate(int rot)
{
	// 1 to clockwise -1 to anticlockwise
	long unsigned int	i, j;
	char temp = ' ';
	long unsigned int map_size = map.size();
	if (rot == 1)
	{
		for (i = 0; i < map_size / 2; i++)
		{
			for (j = i; j < map_size - i - 1; j++)
			{
				temp = map[i][j];
				map[i][j] = map[map_size - j - 1][i];
				map[map_size - j - 1][i] = map[map_size - i - 1][map_size - j - 1];
				map[map_size - i - 1][map_size - j - 1] = map[j][map_size - i - 1];
				map[j][map_size - i - 1] = temp;
			}
		}
	}

	else if (rot == -1)
	{	
		for (i = 0; i < map_size / 2; i++)
		{
			for (j = i; j < map_size - i - 1; j++)
			{
				temp = map[i][j];
				map[i][j] = map[j][map_size - i - 1];
				map[j][map_size - i - 1] = map[map_size - i - 1][map_size - j - 1];
				map[map_size - i - 1][map_size - j - 1] = map[map_size - j - 1][i];
				map[map_size - j - 1][i] = temp;
			}
		}
	}
}

void Tetromino::print()
{
	long unsigned int	i, j, r_size;
	long unsigned int map_size = map.size();

	for (i = 0; i < map_size; i++)
	{
		r_size = (map[i]).size();
		for (j = 0; j < r_size; j++)
		{
			if (map[i][j] != '0')
				cout << map[i][j];
			else
				cout << " ";
 		}
		cout << endl;
	}
}
int			is_collision(vector< vector <char> > merged_map)
{
	int coll_ctr = 0;
	long unsigned int mm_size = merged_map.size();
	long unsigned int mm_size2 = 0;
	for (int i = 0; i < mm_size; i++)
	{
		mm_size2 = merged_map[i].size();
		for (int j = 0; j < mm_size2; j++)
		{
			if (merged_map[i][j] != '0')
				coll_ctr++;
		}
	}
	return (coll_ctr);
}

vector< vector <char> > merge_coll_maps(Tetromino other, vector< vector<char> > merged_map)
{
	//cout << "zzzzzz";
	vector< vector<char> > temp_merge_map = merged_map;
	//cout << "gfd";
	vector< vector<char> > add_map = other.get_coll_map();
	//cout << "kkkkk";
	//long unsigned int	size1 = tet1.collision_map.size();
	long unsigned int	size1 = (other.get_coll_map()).size();
//	long unsigned int	size2 = other.collision_map.size();
	//cout << "pppp";
	long unsigned int	i = 0, j = 0,k = 0, collision_control = 0;
	for (i = 0; i < size1; i++)
	{
		//cout << endl << "sizeq: "<<size1 <<endl;
		//cout << "for iöine girdi size1den kucuk için doncudek index suanda " << i << endl;
		j = 0;
		//long unsigned int	size2 = add_map[i].size();
		long unsigned int	size2 = add_map[i].size();
		//j = size2 - 4 * i;
		//cout << endl << "size2: "<<size2 <<endl;
		merged_map[i].resize(size1 + size2);
		for (/*j = 0*/; j < size2; j++)
		{
			merged_map[i][j] = temp_merge_map[i][j];
			merged_map[i][j + size1] = add_map[i][j];
		}
	}
	/*cout << endl;
	for (int i = 0; i < merged_map.size(); i++)
	{
		k = 0;
		//cout <<"yutil ici for 1 " <<endl;
		for (k = 0; k < merged_map[i].size(); k++)
		{
			cout << merged_map[i][k];
		}
		cout <<endl;
	}*/
	return (merged_map);
}

int		most_surf(vector< vector <char> > merged_map)
{
	int	i = 0,k = 0,counter = 0;
	for (int i = 0; i < merged_map.size(); i++)
	{
		k = 0;
		for (k = 0; k < merged_map[i].size(); k++)
		{
			if (isalpha(merged_map[i][k]))
				counter++;
			if (i > 0 && isalpha(merged_map[i - 1][k]))
				counter++;
			// if (isalpha(merged_map[i][k + 1]))
			// 	counter++;
			// if (isalpha(merged_map[i][k - 1]))
			// 	counter++;
		}
	}
	//cout << "konteol son kufrkansın";
	return (counter);
}

void print_map(	vector< vector <char> > map)
{
	long unsigned int	i, j, r_size;
	long unsigned int map_size = map.size();

	for (i = 0; i < map_size; i++)
	{
		r_size = (map[i]).size();
		for (j = 0; j < r_size; j++)
		{
			//if (map[i][j] != '0')
				cout << map[i][j];
 		}
		cout << endl;
	}
}

vector< vector <char> > 	shift_coll_map(vector< vector <char> > merged_map, int indx)
{
	vector< vector <char> > tmp_coll_map = merged_map;
	vector< vector <char> > prev_coll_map = merged_map;
	int i;
	int size_column = merged_map[0].size();
	int size_row = merged_map.size();
	//cout << "col size : " << size_column <<"row size" << size_row;
	for (int i = 0; i < size_column; i++)
	{
		for (int k = 0; k < size_row; k++)
		{
			if(merged_map[k][merged_map[0].size() - 4] == '0')
			{
				cout<<endl<<"girdi"<<endl;
//				cout << endl << merged_map[k][(merged_map[0].end()) - 4]<<endl;
				//cout << endl << merged_map[i][k]<<endl;
				merged_map[i].erase((merged_map[k].end()) - 4);
			}
			else
				return (prev_coll_map);
		}
		prev_coll_map = merged_map;
	}
	
/*
	for (int k = 0;k < size_column; k++)
	{
	//	i = size_mm - (4 * (indx - 1));
		for ( i = size_row - (4 * (indx)); i > 0 ; i--)//checck that!!
		{
			if (isalpha(merged_map[i-2][k]))
				return (tmp_coll_map);
			merged_map[k].erase(merged_map[k].begin() + (i-1));
			//merged_map[k][i - 2] = merged_map[k][i - 1];//sadece 1 satır shift olur bunu komteol etmem gerek!!
			//merged_map[k][i - 1] = '0';
		}
		
	}*/
	return (merged_map);	
}


bool			Tetromino::canFit()
{
	// ALL COLLISION CONTROL AND MERGE FUNCTIONS WILL INSERT HERE !!
}
