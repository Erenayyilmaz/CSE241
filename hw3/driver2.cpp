
#include "a.h"
using namespace kea;
using namespace std;



kea::Tetromino::Tetromino()
{
	map = new char*[1];
	map[0] = new char[4];
	map[0][0] = 'i';
	map[0][1] = 'i';
	map[0][2] = 'i';
	map[0][3] = 'i';
	set_ty('i');
}

void kea::Tetris::operator+=(Tetromino &tetro)
{
	add_to_arr(tetro);
	arr[++index].tetro_id = index;
}

 int	kea::my_isdigit(string	s)
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

 int	kea::my_isalpha(string c)
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

 int			kea::my_atoi(string nptr)
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

 int	kea::is_legal(char c)
{
		// THIS FUNCTION CONTROLS IS GIVEN CHAR IS LEGAL FOR PROGRAM
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z' || c == 'q'|| c == 'r')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z'|| c == 'Q'|| c == 'R')
		return (1);
	return (0);
}

void kea::Tetris::add_to_arr(Tetromino &adding)
{
	arr_used++;
	if (arr_cap == 0)
	{
		arr_cap = 1;
		arr = new Tetromino[1];
	}
	if (arr_used > arr_cap)
	{
		Tetromino *tmp_arr;
		tmp_arr = new Tetromino[arr_cap * 2];
		for (int i = 0; i < arr_cap; i++)
		{
			tmp_arr[i] = arr[i];
		}
		delete []arr;
		arr = tmp_arr;
		arr_cap *= 2;
	}
	arr[arr_used - 1] = adding;
}

void kea::Tetris::enter_tetro_type()
{
	string						 tetro_type_string;
	cout <<  "enter type of Tetromino piece";

	//cin >> tetro_type_string;
    cout << "i"<< endl;
    tetro_type_string = "i";
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
				arr[++index] = temp;
				arr[index].tetro_id = index;
			}
			
		}
		else
		{
			cout << "finishged";
			exit(1);
			return;
		}
		
	}
	else
	{
		cout <<  "Try again";
		return(enter_tetro_type());
	}
}

kea::Tetromino::Tetromino(e_typ typ)
{

	switch (typ)
	{
	case e_typ::i :
		map = new char*[1];
		map[0] = new char[4];
		map[0][0] = 'i';
		map[0][1] = 'i';
		map[0][2] = 'i';
		map[0][3] = 'i';
		set_ty('i');
		col_size = 4;
		row_size = 1;
		break;

	case e_typ::j :
		map = new char*[3];
		for (int i = 0; i < 3;i++)
			map[i] = new char[2];
		map[0][0] = ' ';
		map[0][1] = 'j';
		map[1][0] = ' ';
		map[1][1] = 'j';
		map[2][0] = 'j';
		map[2][1] = 'j';
		set_ty('j');
		col_size = 2;
		row_size = 3;
		break;
	case e_typ::o :
		map = new char*[2];
		map[0] = new char[2];	
		map[1] = new char[2];
		map[0][0] = 'o';	
		map[1][0] = 'o';	
		map[0][1] = 'o';	
		map[1][1] = 'o';	
		col_size = 2;
		row_size = 2;

		set_ty('o');
		break;
		
	case e_typ::t :
		map = new char*[2];
		map[0] = new char[3];	
		map[1] = new char[3];
		map[0][0] = ' ';	
		map[0][1] = 't';	
		map[0][2] = ' ';	
		map[1][0] = 't';
		map[1][1] = 't';
		map[1][2] = 't';
		row_size = 2;
		col_size = 3;
		set_ty('t');

		break;


			
	case e_typ::l :
		set_ty('l');
		map = new char*[3];
		for (int i = 0; i < 3 ; i++)
			map[i] = new char[2];
		map[0][0] = 'l';	
		map[0][1] = 'l';	
		map[1][0] = 'l';
		map[1][1] = ' ';
		map[2][0] = 'l';
		map[2][1] = ' ';
		col_size = 3;
		row_size = 2;
		break;

			
	case e_typ::s :
		map = new char*[2];
		map[0] = new char[3];
		map[1] = new char[3];
		map[0][0] = 's';	
		map[0][1] = 's';	
		map[0][2] = ' ';	
		map[1][0] = ' ';
		map[1][1] = 's';
		map[1][2] = 's';
		col_size = 2;
		row_size = 3;
		set_ty('s');
		break;

			
	case e_typ::z :
		map = new char*[2];
		map[0] = new char[3];
		map[1] = new char[3];
		map[0][0] = ' ';	
		map[0][1] = 'z';	
		map[0][2] = 'z';	
		map[1][0] = 'z';
		map[1][1] = 'z';
		map[1][2] = ' ';
		set_ty('z');
		col_size = 2;
		row_size = 3;

		break;

	case e_typ::q:
		set_ty('q');
		break;

	default:
		set_ty('q');
		break;
	}
}

char **kea::Tetromino::rotate(int rot)
{
	if (rot == 1)
	{
		int	i, j, k;
		int ind = 0;

		char **tmp_map;
		tmp_map = new char*[col_size];
		for (; ind < col_size; ind++)
			tmp_map[ind] = new char[row_size];

		for (int i = 0; i < col_size; i++)
		{
			for (int j = 0; j < row_size; j++)
			{
				tmp_map[i][j] = map[j][i];
			}
			
		}
		

		for (int i = 0; i < row_size ;i++)
		{
			delete[]map[i];
		}
		delete[]map;
		map = tmp_map;

		int temp = row_size;
		row_size = col_size;
		col_size = temp;
		return (map);
		
	}

	/* ANTI CLOCK WISE = 3 * CLOCK WISE */

	else if (rot == -1)
	{
		map = rotate(1);
		map = rotate(1);
		map = rotate(1);
	}
	return (map);
}

void kea::Tetris::print_map(char **map)
{
	
	for (int i = 0; i < board_col; i++)
	{
		for (int k = 0; k < board_row; k++)
		{
			cout<<(map[i][k]);
		}
		cout<<('\n');
	}
	
}

kea::Tetris::Tetris()
{

		cout <<endl<< "Automatic:"<< endl;
        cout << "Border and collision check not finisheds so there may be overwrite";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));




	string						 row_string;
	string						 column_string;
	int		row_size = 0,	column_size = 0;
	
	cout <<  "enter size of rows of the Tetris board" << endl;
	//cin >> row_string;
    
    cout << "20"<< endl;
    row_string = "20";
	
	
	/*      INPUT   ERROR CHECKS AND ASSIGNS    */
	
	if (my_isdigit(row_string))
		row_size = my_atoi(row_string);
	else{
			cout <<"wrong";
			exit(1);
	}
	cout <<  "enter size of columns of the Tetris board" << endl;
    cout << "20"<< endl;
    column_string = "20";
	//cin >> column_string;
	if (my_isdigit(column_string))
		column_size = my_atoi(column_string);
	else{
			cout <<"wrong";
			exit(1);
	}

	board_col = column_size;
	board_row = row_size;
	board = new char*[column_size];
	for (int i = 0; i < column_size; i++)
		board[i] = new char[row_size];
	
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < row_size; j++)
			board[i][j] = ' ';
	


	
	string						 tetro_type_string;
	tetro_type_string = "q";
    int ctr = 0;
	do
	{
        ctr++;
        if(ctr == 1)
        	tetro_type_string = "t";
        if ( ctr == 3)
        	tetro_type_string = "q";
        else
            tetro_type_string = "i";
		cout <<  "enter type of Tetromino piece";

		//cin >> tetro_type_string;
        //cout << "i"<< endl;
        
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
					add_to_arr(temp);
					// arr.push_back(temp);
				}
				else
				{
				if (tetro_type_string[0] == 'i')
				{
					Tetromino temp(e_typ::i);
					add_to_arr(temp);
				}
				if (tetro_type_string[0] == 'j'){
					Tetromino temp(e_typ::j);
					add_to_arr(temp);
				}
				if (tetro_type_string[0] == 'l'){
					Tetromino temp(e_typ::l);
					add_to_arr(temp);
					//				arr.push_back(temp);
				}

				if (tetro_type_string[0] == 'o')
	{				Tetromino temp(e_typ::o);
									add_to_arr(temp);
					//arr.push_back(temp);

				}
				if (tetro_type_string[0] == 's')
	{				Tetromino temp(e_typ::s);
					add_to_arr(temp);
					//				arr.push_back(temp);

				}
				if (tetro_type_string[0] == 't')
	{				Tetromino temp(e_typ::t);
					add_to_arr(temp);
					//				arr.push_back(temp);

				}
				if (tetro_type_string[0] == 'z')
	{				Tetromino temp(e_typ::z);
					add_to_arr(temp);
					//				arr.push_back(temp);

				}
				}
				arr[++index].tetro_id = index;

				int	rot_dir = 0, rot_count = 0;
				cout << "enter rotation direction 1 for clock -1 for anti";
				//cin >> rot_dir;
                cout << "1";
                rot_dir = 1 ;
				cout << "enter rotation count";
				//cin >> rot_count;
                cout << "1 + ctr";
                rot_count = 1 + ctr;

				for (int i = 0; i < rot_count; i++)
					arr[index].map = arr[index].rotate(rot_dir);

				int	move_dir = 0, move_count = 0;
				cout << "enter move direction 1 for right -1 for left";
				//cin >> move_dir;
                move_dir = -1;
                cout << "-1";
				cout << "enter move count ";
				//cin >> move_count;
                cout << ctr;
                move_count = ctr;
				board = animate(move_dir * move_count, arr[arr_used - 1]);
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
			cout <<  "Wrong type";
			exit(0);
		}
		
	} while (ctr < 4);


}

char ** kea::Tetris::animate(int rl, Tetromino actual_tetromino) /*  ANIMATION FUNCTION  */
{

	char**  printing_map; // PRINTING MAP WILL PRINT AT THE END OF FUNCTION
	printing_map = new char*[board_row];
	for (int i = 0; i < board_row; i++)
		printing_map[i] = new char[board_col];


	for (int i = 0; i < board_row; i++)
	{
		for (int j = 0; j < board_col; j++)
		{
			printing_map[i][j] = board[i][j];
		}
		
	}

	int size_row, size_col;
	size_row = actual_tetromino.row_size ;
	size_col = actual_tetromino.col_size ;

	int	board_y_index = 4;
	int board_x_index = board_col / 2;

	if (rl < 0)
	{
		int rl_index;
		rl *= -1;
	/*  ILK FOR SOLA SAGA KAYDIRMA  */
		for ( rl_index = 0;rl_index < rl ; rl_index++)
		{
			for (int i = 0; i < board_row; i++)
				for (int j = 0; j < board_col; j++)
					printing_map[i][j] = board[i][j];
		
			//collision check
			for (int i = 0; i < actual_tetromino.row_size; i++)
			{
				//cout << "col check"<<endl;
				//cout <<"board[board_y_index][board_x_index - rl_index - 1] \"" << board[board_y_index][board_x_index - rl_index - 1]<<"\"";
				if (board_x_index - rl_index - 1 < 0 || board[board_y_index][board_x_index - rl_index - 1] != ' ' )
				{
					//cout << "col sola giderken";
					return (board);
				}	
				cout << endl;
			}
			
			if (!actual_tetromino.map)
			{
				cout << "!actual_tetromino.map"<<endl;
				exit(1);
			}
			for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
			{
				for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
				{
					//cout<<endl<<"board_y_index:"<<board_y_index<<endl<<"tetro_y_index"<<tetro_y_index<< endl<<"tetro_x_index"<<tetro_x_index<< endl<<"board_x_index:"<<board_x_index <<endl<< "rl_index:"<<rl_index <<endl;
					//cout<<endl<<"actual_tetromino.map[tetro_y_index][tetro_x_index]:"<<actual_tetromino.map/*[tetro_y_index]*/[0]/*[tetro_x_index]*/[0]<< endl<<"tetro_y_index:"<<tetro_y_index << "tetro_x_index:"<<tetro_x_index <<endl;
					//cout << actual_tetromino.map[tetro_x_index][0];
					//cout << actual_tetromino.map[0][tetro_y_index];
					
					printing_map[board_y_index + tetro_y_index  ][board_x_index - rl_index + tetro_x_index ] = actual_tetromino.map[tetro_y_index][tetro_x_index];
				}
				
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			print_map(printing_map);
			//delete printing_map;
		}
		/*  IKINCI FOR ASAGIYA KAYDIRMA  */
		for (int y = 0; y < board_row - board_y_index - size_row/*tetro boyu yap*/; y++)
		{
//			for (int i = 0; i < board_row; i++)
			for (int i = 0; i < board_row; i++)
				for (int j = 0; j < board_col; j++)
					printing_map[i][j] = board[i][j];

			//is collision ;
			for (int i = 0; i < actual_tetromino.col_size; i++)
			{
				// cout << "col check"<<endl;
				// cout <<"board[board_y_index][board_x_index - rl_index - 1] \"" << board[board_y_index][board_x_index - rl_index - 1]<<"\"";
				if (y + size_row  > board_row || board[y + actual_tetromino.row_size + 1][board_x_index - rl_index] != ' ' )
				{	
					//cout << "col asa giderken";
					return (board);
				}
				cout << endl;
			}

			for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
			{
				for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
				{
					printing_map[board_y_index+ y+ tetro_y_index][board_x_index  - rl + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
				}

			
			}
		 	system("clear");
			print_map(printing_map);	
		//	delete[]printing_map;
		}



	}
	

	else
	{
		int rl_index;
	/*  ILK FOR SOLA SAGA KAYDIRMA  */
		for ( rl_index = 0;rl_index < rl ; rl_index++)
		{
			for (int i = 0; i < board_row; i++)
				for (int j = 0; j < board_col; j++)
					printing_map[i][j] = board[i][j];
		
			//cout << endl <<"rl" <<rl<<endl;
			
			//collision check
			for (int i = 0; i < actual_tetromino.row_size; i++)
			{
				//cout << "col check"<<endl;
				//cout <<"board[board_y_index][board_x_index - rl_index - 1] \"" << board[board_y_index][board_x_index - rl_index - 1]<<"\"";
				if (board_x_index + rl_index - 1 < 0 || board[board_y_index][board_x_index + rl_index - 1] != ' ' )
				{
					//cout << "col sola giderken";
					return (board);
				}	
				cout << endl;
			}
			
			if (!actual_tetromino.map)
			{
				cout << "!actual_tetromino.map"<<endl;
				exit(1);
			}


			for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
			{
				for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
				{
					printing_map[board_y_index + tetro_y_index  ][board_x_index + rl_index + tetro_x_index ] = actual_tetromino.map[tetro_y_index][tetro_x_index];
				}
				
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			print_map(printing_map);
		}
		/*  IKINCI FOR ASAGIYA KAYDIRMA  */
		for (int y = 0; y < board_row - board_y_index - size_row/*tetro boyu yap*/; y++)
		{
			for (int i = 0; i < board_row; i++)
				for (int j = 0; j < board_col; j++)
					printing_map[i][j] = board[i][j];

			//is collision ;
			for (int i = 0; i < actual_tetromino.col_size; i++)
			{
				// cout << "col check"<<endl;
				if (y + size_row  > board_row || board[y + actual_tetromino.row_size + 1][board_x_index + rl_index] != ' ' )
				{	
					//cout << "col asa giderken";
					return (board);
				}
				cout << endl;
			}


			for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
			{
				for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
				{
//					printing_map[board_x_index+ y][board_y_index  - rl] = board[tetro_x_index][tetro_y_index];
//					cout <<"board_y_index+ y+ tetro_y_index: "<<board_y_index+ y+ tetro_y_index << "[board_x_index  - rl + tetro_x_index]: "<<board_x_index  - rl + tetro_x_index<< "actual_tetromino.map[tetro_y_index][tetro_x_index]: " << actual_tetromino.map[tetro_y_index][tetro_x_index]<<endl;
					printing_map[board_y_index+ y+ tetro_y_index][board_x_index  + rl + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
//					cout <<"board_y_index+ y+ tetro_y_index: "<<board_y_index+ y+ tetro_y_index << "[board_x_index  - rl + tetro_x_index]: "<<board_x_index  - rl + tetro_x_index<< "actual_tetromino.map[tetro_y_index][tetro_x_index]: " << actual_tetromino.map[tetro_y_index][tetro_x_index]<<endl;
				}

			
			}
		 	system("clear");
			print_map(printing_map);	
		}


	}
	
	return (printing_map);

}
