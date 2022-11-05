#include "new_game.h"

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


long unsigned int	is_legal(char c)
{
		// THIS FUNCTION CONTROLS IS GIVEN CHAR IS LEGAL FOR PROGRAM
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z' || c == 'q'|| c == 'r')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z'|| c == 'Q'|| c == 'R')
		return (1);
	return (0);
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

vector< vector <char> > Tetromino::get_coll_map()
{
	return (collision_map);
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

Tetromino::Tetromino(e_typ typ)
{
	vector< vector<char> > temp_map;

	switch (typ)
	{
	case e_typ::i :
		temp_map =
			{
				{'i','i','i','i'}
			};
		map = temp_map;
		break;
	
	case e_typ::o :
		temp_map =
			{
				{'o','o'},
				{'o','o'}
			};
		map = temp_map;
		break;
		
	case e_typ::t :
		temp_map =
			{
				{' ','t',' '},
				{'t','t','t'}
			};
		map = temp_map;
		break;

	case e_typ::j :
		temp_map =
			{
				{' ','j'},
				{' ','j'},
				{'j','j'}

			};
		map = temp_map;
		break;
			
	case e_typ::l :
		temp_map =
			{
				{'l',' '},
				{'l',' '},
				{'l','l'}
			};
		map = temp_map;
		break;

			
	case e_typ::s :
		map =
			{
				{' ','s','s'},
				{'s','s',' '}
			};
		break;

			
	case e_typ::z :
		map =
			{
				{'z','z',' '},
				{' ','z','z'}
			};
		break;

	default:
		break;
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


Tetris::Tetris()
{
	menu();
	// cout << "geldi";
	// map.resize(10);
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << "geldi2";
	// 	map[i].resize(10);
	// }
	// cout << "geldi3";
	
	cout << "menu sonu tetris constr içi ";
	char    c;
	do
	{
		//c = enter_tetro_type();
		//cout << "geldi";
		Tetromino temp(e_typ::i);
		//arr.push_back(temp);
		arr[0] = temp;
		add();
	} while (c != 'q');
	print_map(arr[0].get_coll_map());
}

/*
char Tetris::enter_tetro_type()
{
	string						 tetro_type_string;
	cout <<  "enter type of Tetromino piece";
	cin >> tetro_type_string;
	//cout << endl <<"type girdi";
	if (tetro_type_string.size() == 1 && is_legal(tetro_type_string[0]))
	{
		if ( tetro_type_string[0] != 'q')
		{
			e_typ ran;
			//e_typ c = e_typ(tetro_type_string[0] - '48');
			//Tetromino temp(c);
			Tetromino temp(e_typ::i);//düzelt
			if (tetro_type_string[0] == 'r')
			{
				int	random = rand();
				random %= 7;
				ran = e_typ(random);
				//Tetromino temp(e_typ::ran);//düzelt
				//ran = static_cast<e_typ> (random);
			}
			//ran = tetro_type_string[0];
			arr.push_back(temp);
			return (tetro_type_string[0]);
		}
		else
		{
			return ('q');
		}
		
	}
	else
	{
		cout <<  "Try again";
		return(enter_tetro_type());
	}
}
*/

char Tetris::enter_tetro_type()
{
	//string						 tetro_type_string;
	char						 tetro_type_string;
	//char c;
	cout <<  "enter type of Tetromino piece";
	cin >> tetro_type_string;
	//scanf("%c",tetro_type_string);
	cout << "typegirdi";
	//cout << endl <<"type girdi";
	if (/*is_legal(tetro_type_string[0])*/1)
	{
		if ( tetro_type_string != 'q')
		{
			cout << "1";
			e_typ ran;
			//e_typ c = e_typ(tetro_type_string[0] - '48');
			//Tetromino temp(c);
			Tetromino temp(e_typ::i);//düzelt
			if (tetro_type_string == 'r')
			{
				int	random = rand();
				random %= 7;
				ran = e_typ(random);
				//Tetromino temp(e_typ::ran);//düzelt
				//ran = static_cast<e_typ> (random);
			}
			//ran = tetro_type_string[0];
			cout << "2";
			arr.push_back(temp);
			cout << "3";
			return (tetro_type_string);
		}
		else
		{
			return ('q');
		}
		
	}
	else
	{
		cout <<  "Try again";
		return(enter_tetro_type());
	}
}

/*
void Tetris::menu()
{
	string						 row_string;
	string						 column_string;
	long unsigned int		row_size = 0,	column_size = 0, i = 0, control = 0;
	cout <<  "enter size of rows of the Tetris board" << endl;
	//cin.clear();
	//cin.ignore(10000,'\n');
	cin >> row_string;
	//getchar();
	//scanf("%s",row_string);
	//cin.clear();
	//cin.ignore(10000,'\n');
	if (my_isdigit(row_string))
		row_size = my_atoi(row_string);
	cout <<  "enter size of columns of the Tetris board" << endl;
	cin >> column_string;
	//column_string = "10";
	//getchar();
	//scanf("%s",column_string);
	//cin >> str_dnm;
	//cin.clear();
	//cin.ignore(10000,'\n');
	cout << "asdasdqweqwezxc";
	if (my_isdigit(column_string))
		column_size = my_atoi(column_string);
	//cout << "asdasdqweqwezxc";
	get_map().resize(row_size);
	i = 0;
	for (; i < row_size; i++)
		((get_map())[i]).resize(column_size);
}

*/

void Tetris::menu()
{
	//cout << "menu girdi";
	int	row_size, column_size;
	// cout <<  "enter size of rows of the Tetris board" << endl;
	// cin >> row_size;
	// cout <<  "enter size of columns of the Tetris board" << endl;
	// cin >> column_size;
	cout << "off";
	row_size = 10, column_size = 10;
	(map).resize(row_size);
	for (int i = 0; i < row_size; i++)
	{
		(map[i]).resize(column_size);
	}
	
	
}

bool Tetris::canfit(vector< vector <char> > map, Tetromino actual_tetromino, int x, int y)
{
	vector< vector <char> > tetro_map;
	tetro_map = actual_tetromino.get_map();
	int ctr = 0;

	long unsigned int k, l;
	for (long unsigned int i = y ,k = tetro_map.size() - 1 ; k >= 0 , i >= 0; i-- , k--)
	{
		for (long unsigned int j = x , l = 0; l < tetro_map[k].size() , j < map[i].size(); l++ ,j++)
		{
			if (tetro_map[k][l] != ' ')
			{
				if (map[i][j] != ' ')
				{
					return (false);
				}
				
			}
		}
		
	}
	return (true);
}

loc Tetris::best_opt_loc()
{
	tetro_index++;
	Tetromino actual_tetromino = arr[tetro_index];
	vector < vector <char> >  temp_map = this->get_map();
	loc ret;
	ret.x = 0, ret.y = 0;
	long unsigned int size_row = 0, size_col = 0;
	size_row = temp_map.size();
	size_col = temp_map[0].size();

	for (long unsigned int i = size_row; i > 0; i--)
	{
		for (long unsigned int j = 0; j < size_col; j++)
		{
			for (int r = 0; r < 4; r++)//actual tetrominonun kac kere donmesi gerektigi
			{
				if (canfit(temp_map, actual_tetromino, i, j))
				{
					ret.x = i;
					ret.y = j;
					return (ret);
				}
				actual_tetromino.rotate(1);
			}
			
		}
		
	}
	return (ret);
}

void Tetris::animate(loc best_loc, Tetromino actual_tetromino)
{
	vector < vector <char> >  printing_map;
	printing_map = this->map;


	long unsigned int k = best_loc.x;
	int	index = map.size() - best_loc.y;
	int size_row, size_col;
	size_row = actual_tetromino.get_map().size();
	size_col =((actual_tetromino.get_map())[0]).size();
	while (index > 0)
	{
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < size_col; j++)
			{
				if ((actual_tetromino.get_map())[i][j] != ' ')
					printing_map[k][j+index] = (actual_tetromino.get_map())[k][j];
			}
			
		}
		system("clear");
		print_map(map);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		index--;//every step
	}
	

	

}

void Tetris::add()
{
	loc best_loc = best_opt_loc();
	Tetromino actual_tetromino = arr[tetro_index];
	animate(best_loc, actual_tetromino);
}


Tetris::~Tetris()
{
	cout << "Game Finished";
}
