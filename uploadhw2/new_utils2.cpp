#include "new_game.h"

using namespace std;

vector< vector <char> > board;


 int	my_isdigit(string	s)
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

 int	my_isalpha(string c)
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

 int			my_atoi(string nptr)
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

 int	is_legal(char c)
{
		// THIS FUNCTION CONTROLS IS GIVEN CHAR IS LEGAL FOR PROGRAM
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z' || c == 'q'|| c == 'r')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z'|| c == 'Q'|| c == 'R')
		return (1);
	return (0);
}

vector< vector <char> > Tetromino::get_coll_map()
{
	return (collision_map);
}

void print_map(	vector< vector <char> > map)
{
	 int	i, j, r_size;
	 int map_size = map.size();

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
		set_ty('i');
		break;
	
	case e_typ::o :
		temp_map =
			{
				{'o','o'},
				{'o','o'}
			};
		set_ty('o');
		map = temp_map;
		break;
		
	case e_typ::t :
		temp_map =
			{
				{' ','t',' '},
				{'t','t','t'}
			};
		set_ty('t');
		map = temp_map;
		break;

	case e_typ::j :
		temp_map =
			{
				{' ','j'},
				{' ','j'},
				{'j','j'}

			};
		set_ty('j');
		map = temp_map;
		break;
			
	case e_typ::l :
		temp_map =
			{
				{'l',' '},
				{'l',' '},
				{'l','l'}
			};
		set_ty('l');
		map = temp_map;
		break;

			
	case e_typ::s :
		map =
			{
				{' ','s','s'},
				{'s','s',' '}
			};
		set_ty('s');
		break;

			
	case e_typ::z :
		map =
			{
				{'z','z',' '},
				{' ','z','z'}
			};
		set_ty('z');
		break;

	case e_typ::q:
		cout<<"q asfdas";
		set_ty('q');
		break;

	default:
		cout<<"q asfdas";
		set_ty('q');
		break;
	}
}

void Tetromino::rotate(int rot)
{
	if (rot == 1)
	{
		int	i, j, k;
		int map_col_size  = map.size() ;
		int map_row_size  = (map[0]).size() ;


		/*  GETTING SIZES   */
		vector < vector <char> > tmp_map;
		tmp_map.resize(map_row_size);
		for (i = 0; i < map_row_size; i++)
		{
			tmp_map[i].resize(map_col_size);
		}
		/* ASSIGNING WITH ORIGINAL CHARS  */
		for (k = 0; k < map_col_size; k++)
		{
			for (j = 0; j < map_row_size; j++)
			{
				tmp_map[j][k] = map[k][j];
			}
			
		}
		map = tmp_map;
	}

	/* ANTI CLOCK WISE = 3 * CLOCK WISE */

	else if (rot == -1)
	{
		rotate(1);
		rotate(1);
		rotate(1);
	}

}

Tetris::Tetris()
{ /*  CONSTRUCTER WILL CALLED AND WORKED WHEN GAME STARTED  */
		cout <<endl<< "Automatic:"<< endl;
		cout << "Rotated versions:"<< endl;
		Tetromino first(e_typ::i);
		print_map(first.get_map());
		cout << endl;
		first.rotate(1);
		print_map(first.get_map());
		cout << endl;
		first.rotate(1);
		print_map(first.get_map());
		cout << endl;
		first.rotate(1);
		print_map(first.get_map());
		cout << endl;
		cout << "Other functions are related with background of program"<<endl;
		cout << "Canfit function doesn't work as i wanted so my program cannot detect best location to locate tetromino piece and overwrite on other tetromino."<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		menu();
		
		int ctr = 0;
		do
		{
			enter_tetro_type();
			add();
			ctr++;
		} while (ctr < 5); 
}

void Tetris::enter_tetro_type()
{
	string						 tetro_type_string;
	cout <<  "enter type of Tetromino piece";

//	cin >> tetro_type_string;
    tetro_type_string = "r";

	if (is_legal(tetro_type_string[0]))
	{
		if ( tetro_type_string[0] != 'q')
		{
			e_typ ran;
			if (tetro_type_string[0] == 'r')
			{
				int	random = rand();
				random %= 7;
				ran = static_cast<e_typ> (random);
				Tetromino temp(ran);
				arr.push_back(temp);
			}
			else
			{
			if (tetro_type_string[0] == 'i')
			{
				Tetromino temp(e_typ::i);
				arr.push_back(temp);
			}
			if (tetro_type_string[0] == 'j'){
				Tetromino temp(e_typ::j);
				arr.push_back(temp);
			}
			if (tetro_type_string[0] == 'l'){
				Tetromino temp(e_typ::l);
				arr.push_back(temp);
			}

			if (tetro_type_string[0] == 'o')
{				Tetromino temp(e_typ::o);
				arr.push_back(temp);

			}
			if (tetro_type_string[0] == 's')
{				Tetromino temp(e_typ::s);
				arr.push_back(temp);

			}
			if (tetro_type_string[0] == 't')
{				Tetromino temp(e_typ::t);
				arr.push_back(temp);

			}
			if (tetro_type_string[0] == 'z')
{				Tetromino temp(e_typ::z);
				arr.push_back(temp);

			}
			}
		}
		else
		{
			cout << "finishged";
			exit(1);
			return;
			//return ('q');
		}
		
	}
	else
	{
		cout <<  "Try again";
		return(enter_tetro_type());
	}
}

void Tetris::menu()
{
	string						 row_string;
	string						 column_string;
	 int		row_size = 0,	column_size = 0, i = 0, control = 0;
	cout <<  "enter size of rows of the Tetris board" << endl;
	row_size = 20;
	cout <<  "enter size of columns of the Tetris board" << endl;
	column_size = 20;
    if (column_size < row_size)
        column_size = row_size;
    else
        row_size = column_size;
	board.resize(row_size);
	i = 0;
	for (; i < row_size; i++)
		((board)[i]).resize(column_size);

}

bool Tetris::canfit(/*vector< vector <char> > map, */Tetromino &actual_tetromino,  int x,  int y)
{
	vector< vector <char> > tetro_map;
	tetro_map = actual_tetromino.get_map();

	int k, l, size_of_l;
	k = tetro_map.size() - 1;
	size_of_l = (actual_tetromino.get_map().size() - 1);

	/*   TETRO PIECE COME WITH BOARD INDEX SO IT WILL LOOK IS FIT IN SPECIFIED LOCATION    */

	for ( int i = y/* k = int(tetro_map.size()) - 1*/ ; k >= 0 && i > 0; i-- , k--)
	{
		for ( int j = x , l = 0;l <  size_of_l && j <= (board[i].size()); l++ ,j++)
		{
			if (tetro_map[k][l] != ' ')
			{
				if ((board)[i-1][j] != ' ') 
				{
					return (false);
				}
				
			}
		}
		
	}
	return (true);
}

loc Tetris::best_opt_loc() // BEFORE CANFIT THAT FUNCTION WILL FIND BEST LOCATION OF TETROMINO
{
	tetro_index++; // TETROMINO ARRAY INDEX
	Tetromino 	actual_tetromino = arr[tetro_index];
	vector < vector <char> >  temp_map = board;
	loc ret;
	ret.x = 0, ret.y = 0; // THAT WILL RETURN FROM THAT FUNCTION
	int size_row = 0, size_col = 0;
	size_row = temp_map.size();
	size_col = temp_map[0].size();


/*   THESE 3 FOR LOOPS WILL LOOK INTO BOARD AND THEY WILL SAY WHETHER TETRO CANFIT IN THAT LOCATION OR NOT   */

	for ( int i = size_row; i > 0; i--)
	{
		for ( int j = 0; j < size_col; j++)
		{
			for (int r = 0; r < 4; r++)//actual tetrominonun kac kere donmesi gerektigi
			{
				//if (canfit(/*temp_map, */actual_tetromino, j, i))
				//{
					ret.x = j;
					ret.y = i;
					return (ret);
				//}
				actual_tetromino.rotate(1);
			}
			
		}
		
	}
	exit(-1);
}

void Tetris::animate(loc best_loc, Tetromino actual_tetromino) /*  ANIMATION FUNCTION  */
{
	vector < vector <char> >  printing_map; // PRINTING MAP WILL PRINT AT THE END OF FUNCTION
	printing_map = board;// INITALLY BOARD WILL ASSIGN TO printing_map

	int k = best_loc.x;
	int	index =  0;
	int size_row, size_col;
	size_row = actual_tetromino.get_map().size() ;
	size_col =((actual_tetromino.get_map())[0]).size() ;

	/*   THAT FOR LOOPS LOOKS FOR RANGES OF TETROMINO AND MAP BORDERS TO NOT GET SEGMENTATION FAULTS    */

	while (index < best_loc.y - 2/*&& index < actual_tetromino.get_map().size()-1*/)
	{
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < size_col; j++)		
			{
				//if (i == best_loc.y && j == best_loc.x)
					//if ((actual_tetromino.get_map())[i][j] != ' ' )
					//	{
							printing_map[i + index][j+k] = (actual_tetromino.get_map())[i][j]; 
							//return;
					//	}
			}

		cout << endl;
			
		}
		system("clear");
		print_map(printing_map);
		printing_map = board;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		index++;//every step

	}
	board = printing_map;

}


void Tetris::add() // ADDING TETRO INTO BOARD: ANIMATE THEN LOCATE 
{
	loc best_loc = best_opt_loc();// FINDING BEST LOCATION FOR PER TETRO PIECE
	Tetromino actual_tetromino = arr[tetro_index];
	animate(best_loc, actual_tetromino);
}


Tetris::~Tetris()
{
	cout << "Game Finished";
}
