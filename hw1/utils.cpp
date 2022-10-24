#include "utils.h"

using namespace std;

long unsigned int	my_isdigit(string	s)
{
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
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z')
		return (1);
	return (0);
}

long unsigned int	my_isalpha(string c)
{
	int ind = 0;
	while (c[ind])
	{
		if (c[ind] >= 65 && c[ind] <= 90)

		{

			return (1);

		}

		else if (c[ind] <= 122 && c[ind] >= 97)

		{

			return (1);

		}

		ind++;
	}	
	return (0);
}

long unsigned int			my_atoi(string nptr)
{
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
	long unsigned int tet_num;
	//vector<char> arr;
	string	tmp;
	char in;
	int ctr = 1;
	do
	{
		cout << "How many tetrominos?";
		cin >> tmp;
		if (!my_atoi(tmp) && !my_isalpha(tmp))
		{
			ctr = 0;
		}
		tet_num = my_atoi(tmp);
		cout << endl << "tet_num = " <<tet_num;
		arr.resize(tet_num);
		cout << "What are their types?";
		for (long unsigned int i = 0; i < tet_num; i++)
		{
			cin >> in;
			if (!is_legal(in))
				ctr = 1;
			else
			{
				//insert here!! tetrominos vectırune eklemeler yaoılacak tek tek
				e_typ	tt;
				tt = (e_typ)in;
				arr[i] = Tetromino(tt);
				ctr = 0;
			}
			
		}
		if(ctr == 1)
			cout << "wrong, try again!";
	} while (ctr == 1);
	

}

Tetromino::Tetromino(e_typ typ)
{
	vector< vector<char> > temp_map
		{
			{'0','0','0'},
			{'0','0','0'},
			{'0','0','0'}
		};

	switch (typ)
	{
	case e_typ::i :
		temp_map =
			{
				{'i','i','i','i'},
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'}
			};
		map = temp_map;
		break;
	
	case e_typ::o :
		temp_map =
			{
				{'o','o','0'},
				{'o','o','0'},
				{'0','0','0'}
			};
		map = temp_map;
		break;
		
	case e_typ::t :
		temp_map =
			{
				{'t','t','t'},
				{'0','t','0'},
				{'0','0','0'}
			};
		map = temp_map;
		break;

	case e_typ::j :
		temp_map =
			{
				{'0','j','0'},
				{'0','j','0'},
				{'j','j','0'}
			};
		map = temp_map;
		break;
			
	case e_typ::l :
		temp_map =
			{
				{'l','0','0'},
				{'l','0','0'},
				{'l','l','0'}
			};
		map = temp_map;
		break;

			
	case e_typ::s :
		temp_map =
			{
				{'0','s','s'},
				{'s','s','0'},
				{'0','0','0'}
			};
		map = temp_map;
		break;

			
	case e_typ::z :
		temp_map =
			{
				{'z','z','0'},
				{'0','z','z'},
				{'0','0','0'}
			};
		map = temp_map;
		break;



	default:
		break;
	}
	print();
	rotate(1);
	print();
}

Tetromino::Tetromino()
{
	vector< vector<char> > map
	{
		{0,0,0},
		{0,0,0},
		{0,0,0}
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

int Tetromino::rotate(int rot)
{
	// 1 to clockwise -1 to anticlockwise
	long unsigned int	i, j, temp = 0;
	long unsigned int map_size = map.size();
	if (rot == 1)
	{
		for (i = 0; i < map_size / 2; i++)
		{
			for (j = 0; j < map_size - i - 1; j++)
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
			for (j = 0; j < map_size - i - 1; j++)
			{
				temp = map[i][j];
				map[i][j] = map[j][map_size - i - 1];
				map[j][map_size - i - 1] = map[map_size - i - 1][map_size - j - 1];
				map[map_size - i - 1][map_size - j - 1] = map[map_size - j - 1][i];
				map[map_size - j - 1][i] = temp;
			}
		}
	}
	return (0);
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
			cout << map[i][j];
 		}
		cout << endl;
	}
}

bool					canFit(Tetromino other)
{

}