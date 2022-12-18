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


int			is_collision(vector< vector <char> > merged_map)
{
	int coll_ctr = 0;
	 int mm_size = merged_map.size();
	 int mm_size2 = 0;
	for ( int i = 0; i < mm_size; i++)
	{
		mm_size2 = merged_map[i].size();
		for ( int j = 0; j < mm_size2; j++)
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
	 int	i, j, r_size;
	 int map_size = map.size();

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
		 int map_col_size = map.size();
		 int map_row_size = (map[0]).size();

		vector < vector <char> > tmp_map;
		tmp_map.resize(map_col_size);
		for (i = 0; i < map_col_size; i++)
		{
			tmp_map[i].resize(map_row_size);
		}
		for (j = 0; j < map_row_size; j++)
		{
			for (k = 0; k < map_col_size; k++)
			{
				tmp_map[k][j] = map[j][k];
			}
			
		}
		map = tmp_map;
	}
	else if (rot == -1)
	{
		rotate(1);
		rotate(1);
		rotate(1);
	}
	


}
/*
void Tetromino::rotate(int rot)

{

	// 1 to clockwise -1 to anticlockwise

	 int	i, j;

	char temp = ' ';

	 int map_size = map.size();

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
*/

Tetris::Tetris()
{

	//cout << "constr geldi";
		menu();
		/*	int	row_size, column_size;
		cout <<  "enter size of rows of the Tetris board" << endl;
		//cin >> row_size;
		//scanf("%d",&row_size);
		cout <<  "enter size of columns of the Tetris board" << endl;
		//cin >> column_size;
		//scanf("%d",&column_size);
		cout << "off";
		row_size = 10, column_size = 10;
		(board).resize(row_size);
		for (int i = 0; i < row_size; i++)
		{
			(board[i]).resize(column_size);
		}
		// map.resize(10);
		// for (int i = 0; i < 10; i++)
		// {
		// 	cout << "geldi2";
		// 	map[i].resize(10);
		// }
		// cout << "geldi3";*/
		int ctr = 0;
		//cout << "menu sonu tetris constr içi ";
		//Tetromino temp(e_typ::i);
		//add();
		//arr.push_back(temp);
		do
		{
			enter_tetro_type();
			//cout << "geldi";
			//Tetromino temp(e_typ::i);
			//arr.push_back(temp);
			//arr[0] = temp;
			add();
			ctr++;
		} while (/*ctr < 5*/arr[ctr].get_ty() != 'q' );  // DUZELT BURA SONRA*/
		//print_map(arr[0].get_coll_map());
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

void Tetris::enter_tetro_type()
{
	string						 tetro_type_string;
	//char						 tetro_type_string = 'i';
	//char c;
	cout <<  "enter type of Tetromino piece";

	cin >> tetro_type_string;
	//scanf("%c",tetro_type_string);
	//cout << "typegirdi";
	//cout << endl <<"type girdi";
	if (is_legal(tetro_type_string[0]))
	{
		if ( tetro_type_string[0] != 'q')
		{
			//cout << "1";
			//e_typ c = e_typ(tetro_type_string[0] - 48);
			//Tetromino temp(c);
			e_typ ran;
			if (tetro_type_string[0] == 'r')
			{
				int	random = rand();
				random %= 7;
				//ran = e_typ(random);
				ran = static_cast<e_typ> (random);
				//cout <<endl<< int(ran)<<endl;
				Tetromino temp(ran);//düzelt
				arr.push_back(temp);
			}
			else
			{
			//ran = static_cast<e_typ>(tetro_type_string);
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
			//ran = tetro_type_string[0];
			//cout << "2";
			//cout << "3";
			//return (tetro_type_string);
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

/*
void Tetris::enter_tetro_type()
{
	//string						 tetro_type_string;
	char						 tetro_type_string = 'i';
	//char c;
	cout <<  "enter type of Tetromino piece";

	//cin >> tetro_type_string;
	//scanf("%c",tetro_type_string);
	//cout << "typegirdi";
	//cout << endl <<"type girdi";
	if (/*is_legal(tetro_type_string[0])1)
	{
		if (/* tetro_type_string != 'q'1)
		{
			//cout << "1";
			e_typ ran;
			//e_typ c = e_typ(tetro_type_string[0] - 48);
			//Tetromino temp(c);
			Tetromino temp(e_typ::s);//düzelt
			if (tetro_type_string == 'r')
			{
				int	random = rand();
				random %= 7;
				ran = e_typ(random);
				//Tetromino temp(e_typ::ran);//düzelt
				//ran = static_cast<e_typ> (random);
			}
			//ran = tetro_type_string[0];
			//cout << "2";
			arr.push_back(temp);
			//cout << "3";
			//return (tetro_type_string);
		}
		else
		{
			exit(1);
			//return ('q');
		}
		
	}
	else
	{
		cout <<  "Try again";
		return(enter_tetro_type());
	}
}*/

void Tetris::menu()
{
	string						 row_string;
	string						 column_string;
	 int		row_size = 0,	column_size = 0, i = 0, control = 0;
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
	else{
			cout <<"wrong";
			exit(1);
	}
	cout <<  "enter size of columns of the Tetris board" << endl;
	cin >> column_string;
	//column_string = "10";
	//getchar();
	//scanf("%s",column_string);
	//cin >> str_dnm;
	//cin.clear();
	//cin.ignore(10000,'\n');
	//cout << "asdasdqweqwezxc";
	if (my_isdigit(column_string))
		column_size = my_atoi(column_string);
	else{
			cout <<"wrong";
			exit(1);
	}
	//cout << "asdasdqweqwezxc";
	board.resize(row_size);
	i = 0;
	for (; i < row_size; i++)
		((board)[i]).resize(column_size);
}


/*
void Tetris::menu()
{
	//cout << "menu girdi";
	int	row_size, column_size;
	row_size = 10, column_size = 10;
	cout <<  "enter size of rows of the Tetris board" << endl;
	//cin >> row_size;
	//scanf("%d",&row_size);
	cout <<  "enter size of columns of the Tetris board" << endl;
	//cin >> column_size;
	//scanf("%d",&column_size);
	cout << "off";
	(board).resize(row_size/*,vector <char> (column_size, ' '));
	for (int i = 0; i < row_size; i++)
	{
		(board[i]).resize(column_size);
	}
	//board[0][0] = 'p';
	//cout << endl<<"asfofakğapsdağpkfağpk"	<<"0:0"<< board[0][0]<<endl;
	//cout <<endl;

}*/

bool Tetris::canfit(/*vector< vector <char> > map, */Tetromino actual_tetromino,  int x,  int y)
{
	//cout << endl << "Canfit basi" << endl;
	vector< vector <char> > tetro_map;
	//cout << endl << "2 canfit" << endl;
	tetro_map = actual_tetromino.get_map();
	//cout << endl << "3 canfit" << endl;
	//int ctr = 0;
	//cout << endl  << endl;
	//print_map(board);
	//cout << endl  << endl;

	int k, l, size_of_l;
	k = tetro_map.size() - 1;
	size_of_l = int(tetro_map[0].size());
	//size_t a = 0;
	//int b = 0;
	//cout << endl<< endl << "a-b: "<<a - b << endl<< endl ;
	//cout << endl <<"k : "<< k <<endl ;
	for ( int i = y /*k = int(tetro_map.size()) - 1*/ ; k >= 0 , i >= 0; i-- , k--)
	{
		//cout << endl << "i :" << i << "k :" << k << "l :" << l << " x:"<< x << " y:"<< y << "sizeofl: "<< size_of_l<< x<< " y:"<< y<< "tetro_map[k].size(): "<< tetro_map[k].size()<< endl;
		for ( int j = x , l = 0; l <  size_of_l, j < (board[i].size()); l++ ,j++)
		{
			//cout << endl << "i :" << i << "k :" << k << "l :" << l << "j :" << j << endl<< "tetro_map[k].size(): "<< tetro_map[k].size()<< "char tetro_map[k][l]: " << tetro_map[k][l]<<endl;
			//cout << endl;
			//print_map(tetro_map);
			//cout << endl;
			//cout << 	"k:l"<< tetro_map[k][l]<<endl;
			//cout << endl;
			if (tetro_map[k][l] != ' ')
			{
			 //cout << "\nasdasd";
				//cout<< endl << "now k:"<<k<<"l:"<<l;
			// 	cout<< endl << "now i:"<<i<<"j:"<<j;
			// 	cout<< "board.size()"<< board.size()<<"board[i].size()"<<board[i].size() ;
			// 	cout<< "board.size()"<< board.size()<<"board[i].size()"<<(board)[i].size() ;
			// 	print_map(board);
			// 	board[0][0] = 'u';
			 	//cout << 	"i:j"<< board[i][j]<<endl;
				//cout << endl;
			// 	cout<< endl <<endl;
			// 	cout << "czocxz\n";
				//(this->board[i][j] != ' ')
				if (/*board[i][j] != ' 'this->board[i][j]*/ (board)[i][j] != ' ') 
				{
					//cout<< endl << "before ret i:"<<i<<"j:"<<j;
					//cout << "asdsad";
					return (false);
				}
				
			}
		//	cout << endl <<"ife giremedi ";
		}
		
	}
	return (true);
}

/*
bool Tetris::canfit(/*vector< vector <char> > map, Tetromino actual_tetromino,  int x,  int y)
{
	cout << endl << "Canfit basi" << endl;
	vector< vector <char> > tetro_map;
	cout << endl << "2 canfit" << endl;
	tetro_map = actual_tetromino.get_map();
	cout << endl << "3 canfit" << endl;
	//int ctr = 0;
	cout << endl  << endl;
	print_map(map);
	cout << endl  << endl;

	int k, l, size_of_l;
	k = tetro_map.size() - 1;
	size_of_l = int(tetro_map[0].size());
	//size_t a = 0;
	//int b = 0;
	//cout << endl<< endl << "a-b: "<<a - b << endl<< endl ;
	cout << endl <<"k : "<< k <<endl ;
	for ( int i = y /*k = int(tetro_map.size()) - 1 ; k >= 0 , i >= 0; i-- , k--)
	{
		cout << endl << "i :" << i << "k :" << k << "l :" << l << " x:"<< "sizeofl: "<< size_of_l<< x<< " y:"<< y<< "tetro_map[k].size(): "<< tetro_map[k].size()<< endl;
		for ( int j = x , l = 0; l <  size_of_l, j < (map[i].size()); l++ ,j++)
		{
			cout << endl << "i :" << i << "k :" << k << "l :" << l << "j :" << j << endl;
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
}*/

loc Tetris::best_opt_loc()
{
	tetro_index++;
	//cout << endl <<"bestoptlocbasi"<< endl;
	//print_map(arr[tetro_index].get_map());
	//cout << endl;
	Tetromino 	actual_tetromino = arr[tetro_index];;
	//cout << endl <<"act"<< endl;
	//print_map(actual_tetromino.map);
	//actual_tetromino = arr[tetro_index];
	//cout << endl <<"1"<< endl;
//	vector < vector <char> >  temp_map = this->get_map();
	vector < vector <char> >  temp_map = board;
	
//	cout << endl  << endl;
	//print_map(temp_map);
	//cout << endl  << endl;


	//cout << endl  << endl;
	//print_map(board);
	//cout << endl  << endl;


	//cout << endl <<"2"<< endl;
	loc ret;
	//cout << endl <<"3"<< endl;
	ret.x = 0, ret.y = 0;
	//cout << endl <<"4"<< endl;
	 int size_row = 0, size_col = 0;
	size_row = temp_map.size();
	size_col = temp_map[0].size();

	for ( int i = size_row; i > 0; i--)
	{
		//cout << endl<< "ilk fora girdi"<<endl;
		for ( int j = 0; j < size_col; j++)
		{
			for (int r = 0; r < 4; r++)//actual tetrominonun kac kere donmesi gerektigi
			{

				//cout << endl << "i :" << i << "j :" << j << endl;
				if (canfit(/*temp_map, */actual_tetromino, i, j))
				{
					//cout<<endl<< "canfit if basi"<<endl;
					//ret.x = i;
					ret.x = j;
					ret.y = i;
					//ret.y = j;
					return (ret);
				}
				actual_tetromino.rotate(1);
			}
			
		}
		
	}
	exit(-1);
	//return (ret);
}

void Tetris::animate(loc best_loc, Tetromino actual_tetromino)
{
	vector < vector <char> >  printing_map;
	printing_map = board;

	//cout << endl << endl;
	//cout << "asdık";
	//print_map(board); 
	//cout << endl << endl;

	 int k = best_loc.x;
//	int	index = board.size() /*- best_loc.y*/;
	int	index =  best_loc.y;
	//cout << endl << endl;
	//cout << "index:"<< index;
	//cout << endl;
	int size_row, size_col;
	size_row = actual_tetromino.get_map().size();
	size_col =((actual_tetromino.get_map())[0]).size();
	//cout <<"size_row: "<<size_row<<"size_col: "<<size_col<< "loc.x"<<best_loc.x<< "loc.y"<<best_loc.y;
	while (index >= 0)
	{
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < size_col; j++)
			{
				if ((actual_tetromino.get_map())[i][j] != ' ' )
					printing_map[i+k][j + index ] = (actual_tetromino.get_map())[i][j];
			}
			//	cout << endl;
			
		}
	//	cout << endl<<"asdsad"<< endl;
		system("clear");
		cout << endl;
		print_map(printing_map);
		printing_map = board;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		index--;//every step

	}
		//cout << endl;
		//print_map(printing_map);
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));

	

}
/*
void Tetris::animate(loc best_loc, Tetromino actual_tetromino)
{
	vector < vector <char> >  printing_map;
	printing_map = board;

	cout << endl << endl;
	cout << "asdık";
	//print_map(board); 
	cout << endl << endl;

	 int k = best_loc.x;
//	int	index = board.size() /*- best_loc.y;
	int	index =  best_loc.y;
	cout << endl << endl;
	cout << "index:"<< index;
	cout << endl;
	int size_row, size_col;
	size_row = actual_tetromino.get_map().size();
	size_col =((actual_tetromino.get_map())[0]).size();
	cout <<"size_row: "<<size_row<<"size_col: "<<size_col<< "loc.x"<<best_loc.x<< "loc.y"<<best_loc.y;
	while (index >= 0)
	{
		for (int i = 0; i < size_row; i++)
		{
			for (int j = 0; j < size_col; j++)
			{
				cout<<"actual_tetromino.get_map())[i][j]"<<"i: "<<i <<"j: "<< j <<(actual_tetromino.get_map())[i][j]<<endl;
				if ((actual_tetromino.get_map())[i][j] != ' ' )
				{	

					cout <<endl<< "if ici girdi"<<endl;
					//cout << "actual_tetromino.get_map()[k][j]:"<<actual_tetromino.get_map()[k][j]<< k<< j << endl;
//					printing_map[i][j+index] = (actual_tetromino.get_map())[k][j];
					printing_map[i][j+index] = (actual_tetromino.get_map())[i][j];
					//cout <<endl<< "if ici girdi"<<endl;
				}
			}
			//	cout << endl;
			
		}
		cout << endl<<"asdsad"<< endl;
		//system("clear");
		//cout << endl;
//		print_map(printing_map);
//		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		index--;//every step

	}
		cout << endl;
		print_map(printing_map);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	

}*/
/*
void Tetris::animate(loc best_loc, Tetromino actual_tetromino)
{
	vector < vector <char> >  printing_map;
	printing_map = board;

	

	 int k = best_loc.x;
	int	index = board.size() - best_loc.y;
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
		print_map(board);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		index--;//every step
	}
	

	

}*/

void Tetris::add()
{
	//cout << "\naddbasi";
	loc best_loc = best_opt_loc();
	//cout << "bestoptloc bitti add da ";
	cout << endl << "first char of arrtetroindasd"<<(arr[tetro_index].map[0][0]);
	cout <<endl<<endl;
	Tetromino actual_tetromino = arr[tetro_index];
	//cout << "burda";
	//cout <<"bestlocx: "<< best_loc.x << "bestlocy: "<< best_loc.y;
	//cout <<endl<<endl;
	animate(best_loc, actual_tetromino);
}


Tetris::~Tetris()
{
	cout << "Game Finished";
}
