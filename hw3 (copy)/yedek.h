#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>


#ifndef UTILS_H
#define UTILS_H

using namespace	std;

/*STRONG ENUM*/
enum class e_typ {i = 0, o, t, j, l, s, z, r, q};

struct loc
{
	int x;
	int y;
};


/*		INPUT CONTROL FUNCTIONS		*/

 int					my_atoi(string nptr);
 int				my_isdigit(string	s);
 int						is_legal(char c);
 int					my_isalpha(string c);




//void print_map(	vector< vector <char> > map);//for debug delete

class Tetromino
	{
	private:
		int 					dir;
		char					ty;
		char		**collision_map;
	public:
		char		**map;
		int			tetro_id = -1;
		int				row_size;
		int 			col_size;
		// vector< vector<char> > map
		// 	{
		// 		{'0','0','0','0'},
		// 		{'0','0','0','0'},
		// 		{'0','0','0','0'},
		// 		{'0','0','0','0'}
		// 	};	
		// vector <vector<char> > collision_map;
		Tetromino(e_typ obj);// This defination used in homework
		Tetromino();
		//bool	canFit();
		vector< vector <char> > 				get_coll_map();// To get collision map
		void								set_type(e_typ typ);// Not used in that code but in future, this function will help to me
		void											print();// Basic print map function
		char**										rotate (int rot);// Rotate map. 1 for clockwise -1 for anticlockwise
		//void					set_map(vector<vector<char>> map);// Setting map
		void 								init_collision_map();// Initialization of collision map
		inline void 					set_ty(char c){ ty = c; };// Setting type of Tetromino piece
		inline char 					get_ty(){ return (ty); };// Getting type of Tetromino piece
		inline char **get_map() { return (map);};//Getting map of Tetromino piece
	};


class Tetris
{
private:
	char		**board;
	Tetromino	*arr;

public:
	void print_map(	char **map);//for debug delete
	void operator+=(Tetromino &tetro);
	int	board_col = 0;
	int	board_row = 0;	
	int	arr_cap = 0;
	int	arr_used = 0;
	void	add_to_arr(Tetromino &adding);
	int	index = -1;
	void	enter_tetro_type();
	Tetris();
	char ** animate(int rl, Tetromino actual_tetromino);
};


Tetromino::Tetromino()
{
	map = new char*[1];
	map[0] = new char[4];
	map[0][0] = 'i';
	map[0][1] = 'i';
	map[0][2] = 'i';
	map[0][3] = 'i';
	set_ty('i');
	cout <<endl<< map[0][3]<<endl;
}

void Tetris::operator+=(Tetromino &tetro)
{
	add_to_arr(tetro);
	arr[++index].tetro_id = index;
}


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


void Tetris::add_to_arr(Tetromino &adding)
{
	arr_used++;
	if (arr_cap == 0)
	{
		//cout << endl<<"add to arr içinde arr_cap=0 a grşdşgirdi"<<endl;
		arr_cap = 1;
		arr = new Tetromino[1];
	}
//		arr = new Tetromino[1];
	//cout << "arr_used: "<<arr_used<<"arr_cap: "<<arr_cap<<endl;
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

void Tetris::enter_tetro_type()
{
	string						 tetro_type_string;
	cout <<  "enter type of Tetromino piece";

	cin >> tetro_type_string;
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
				//arr.push_back(temp);
			}
			
		}
		// else if(tetro_type_string[0] != '')
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


Tetromino::Tetromino(e_typ typ)
{

	switch (typ)
	{
	case e_typ::i :
		// temp_map =
		// 	{
		// 		{'i','i','i','i'}
		// 	};
		//cout << 	"i olsuturmaya calısıtoer"<<endl;
		map = new char*[1];
		map[0] = new char[4];
		//map = temp_map;
		map[0][0] = 'i';
		map[0][1] = 'i';
		map[0][2] = 'i';
		map[0][3] = 'i';
		set_ty('i');
		col_size = 4;
		row_size = 1;
		//cout <<endl<< map[0][3]<<endl;
		break;

	case e_typ::j :
		// temp_map =
		// 	{
		// 		{'i','i','i','i'}
		// 	};
		//cout << 	"i olsuturmaya calısıtoer"<<endl;
		map = new char*[3];
		for (int i = 0; i < 3;i++)
			map[i] = new char[2];
		//map = temp_map;
		map[0][0] = ' ';
		map[0][1] = 'j';
		//map[0][2] = 'j';
		map[1][0] = ' ';
		map[1][1] = 'j';
		//map[1][2] = 'j';
		map[2][0] = 'j';
		map[2][1] = 'j';
		set_ty('j');
		col_size = 2;
		row_size = 3;
		//cout <<endl<< map[0][3]<<endl;
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


char **Tetromino::rotate(int rot)
{
	if (rot == 1)
	{
		int	i, j, k;
		int ind = 0;
		//int map_col_size  = map.size() ;
		//int map_row_size  = (map[0]).size() ;
	//	cout << endl << "burayabak:"<< map[0][0]<< endl;
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				cout<<map[i][j];
			}
			cout << endl;
		}
		

		char **tmp_map;
		//cout << "1"<<endl;
//		tmp_map = new char*[col_size];
		
		tmp_map = new char*[col_size];
		//cout << "col size : "<< col_size<< "row size : "<< row_size<<endl;
		//cout << "1-1"<<endl;
		for (; ind < col_size; ind++)
			tmp_map[ind] = new char[row_size];
		//cout << "2";
		/*  GETTING SIZES   */
		//vector < vector <char> > tmp_map;
		//tmp_map.resize(map_row_size);
		//for (i = 0; i < map_row_size; i++)
		//{
		//	tmp_map[i].resize(map_col_size);
		//}
		/* ASSIGNING WITH ORIGINAL CHARS  */
	// for (k = 0; k < row_size ; k++)
	// {
	// 	for (j = 0; j < col_size ; j++)
	// 	{
	// 		cout<<"map[j][k]"<< map[k][j]<<endl;
	// 	}
		
	// }
		//if (!map)
		//	cout << "olusmadi map";

		cout << "ilki delete sonrası" << endl;
		for (int i = 0; i < row_size ;i++)
		{
			delete[]map[i];
		}
		cout << "ikinci delete sonrası" << endl;
		delete[]map;
		map = tmp_map;

		int temp = row_size;
		row_size = col_size;
		col_size = temp;
		//delete []map[0];
		//map = nullptr;
		//map = tmp_map;
		// for (int i = 0; i < 4; i++)
		// {
		// 	cout <<endl<<"tmp_map[i][0] after rotate"<< tmp_map[i][0];
		// }
		//cout << "asddsa";
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

void Tetris::print_map(char **map)
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

Tetris::Tetris()
{
	string						 row_string;
	string						 column_string;
	int		row_size = 0,	column_size = 0;
	
	cout <<  "enter size of rows of the Tetris board" << endl;
	cin >> row_string;
	
	
	/*      INPUT   ERROR CHECKS AND ASSIGNS    */
	
	if (my_isdigit(row_string))
		row_size = my_atoi(row_string);
	else{
			cout <<"wrong";
			exit(1);
	}
	cout <<  "enter size of columns of the Tetris board" << endl;
	cin >> column_string;
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
	do
	{
		cout <<  "enter type of Tetromino piece";

		cin >> tetro_type_string;
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
					//				arr.push_back(temp);
				}
				if (tetro_type_string[0] == 'j'){
					Tetromino temp(e_typ::j);
					add_to_arr(temp);
					//				arr.push_back(temp);
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
				cin >> rot_dir;
				cout << "enter rotation count";
				cin >> rot_count;
				cout << "arr_used:"<<arr_used<<endl;

				for (int i = 0; i < rot_count; i++)
					arr[index].map = arr[index].rotate(rot_dir);

				int	move_dir = 0, move_count = 0;
				cout << "enter move direction 1 for right -1 for left";
				cin >> move_dir;
				cout << "enter move count ";
				cin >> move_count;

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
		
	} while (tetro_type_string[0] != 'q');

	//Tetromino actual_tetro;
	//enter_tetro_type();
	//arr[++index] = Tetromino(e_typ::i);
//	Tetromino tmp_ttr = Tetromino(e_typ::i);
	//cout <<endl<<"tmp_ttr.get_ty();"<< tmp_ttr.get_ty()<<endl;
//	add_to_arr(tmp_ttr);
//	arr[index].tetro_id = index;
	


	//char ctr_char;
	
	/*

	int	rot_dir = 0, rot_count = 0;
	cout << "enter rotation direction 1 for clock -1 for anti";
	cin >> rot_dir;
	cout << "enter rotation count";
	cin >> rot_count;
	cout << "arr_used:"<<arr_used<<endl;
	for (int i = 0; i < rot_count; i++)
		arr[arr_used-1].map = arr[arr_used-1].rotate(rot_dir);

	int	move_dir = 0, move_count = 0;
	cout << "enter move direction 1 for right -1 for left";
	cin >> move_dir;

	cout << "enter move count ";
	cin >> move_count;
//	board = animate(move_count * move_dir, tmp_ttr);
	cout << "ilki bitti"<<endl;


	Tetromino sec_ttr = Tetromino(e_typ::j);
	add_to_arr(sec_ttr);
	++index;
	arr[index].tetro_id = index;
	
	*/



	int k,j;
//	board = animate(move_count * move_dir, tmp_ttr);
	/*cout << "burabak"<<endl;
	
	cout <<endl<<"arr[arr_used - 1].col_size:" <<arr[arr_used-1].col_size<<	"arr[arr_used - 1].row_size"<<arr[arr_used-1].row_size<<endl;
	
	for (k = 0; k < arr[arr_used-1].col_size; k++)
	{
		for (j = 0; j < arr[arr_used-1].row_size; j++)
		{
			cout << (arr[arr_used - 1].map)[j][k];
		}
		cout << endl;
	}*/
}


char ** Tetris::animate(int rl, Tetromino actual_tetromino) /*  ANIMATION FUNCTION  */
{
//	vector < vector <char> >  printing_map; // PRINTING MAP WILL PRINT AT THE END OF FUNCTION


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
	cout << endl<<"printingmap:"<<endl;
	print_map(printing_map);
	cout << endl;

	int size_row, size_col;
	size_row = actual_tetromino.row_size ;
	size_col = actual_tetromino.col_size ;

	int	board_y_index = 4;
	int board_x_index = board_col / 2;
	cout <<	"asdqwezxc"<<endl;

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
		
			cout << endl <<"rl" <<rl<<endl;
			
			//collision check
			/*for (int i = 0; i < actual_tetromino.row_size; i++)
			{
				cout << "col check"<<endl;
				cout <<"board[board_y_index][board_x_index - rl_index - 1] \"" << board[board_y_index][board_x_index - rl_index - 1]<<"\"";
				if (board[board_y_index][board_x_index - rl_index - 1] != ' ' || board_x_index - rl_index - 1 < 0)
					return (board);
				cout << endl;
			}*/
			
			if (!actual_tetromino.map)
				cout << "!actual_tetromino.map"<<endl;


/*
			cout <<"actual_tetromino.row_size"<<actual_tetromino.row_size<<endl;
			cout <<"actual_tetromino.col"<<actual_tetromino.col_size<<endl;

			for (int i = 0; i < actual_tetromino.col_size; i++)
			{
				for (int j = 0; j < actual_tetromino.row_size; j++)
				{
					cout << actual_tetromino.map[i][j];
				}
				cout << endl;
			}
*/

			cout << "bastımra onesic"<<endl;

			for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
			{
				for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
				{
					cout<<endl<<"board_y_index:"<<board_y_index<<endl<<"tetro_y_index"<<tetro_y_index<< endl<<"tetro_x_index"<<tetro_x_index<< endl<<"board_x_index:"<<board_x_index <<endl<< "rl_index:"<<rl_index <<endl;
					//cout<<endl<<"actual_tetromino.map[tetro_y_index][tetro_x_index]:"<<actual_tetromino.map/*[tetro_y_index]*/[0]/*[tetro_x_index]*/[0]<< endl<<"tetro_y_index:"<<tetro_y_index << "tetro_x_index:"<<tetro_x_index <<endl;
					//cout << actual_tetromino.map[tetro_x_index][0];
					//cout << actual_tetromino.map[0][tetro_y_index];
					
					printing_map[board_y_index + tetro_y_index  ][board_x_index - rl_index + tetro_x_index ] = actual_tetromino.map[tetro_y_index][tetro_x_index];
				}
				
			}
			cout << endl<<	"print_map(printing_map);"<<endl<<'x';
			//std::this_thread::sleep_for(std::chrono::milliseconds(50));
			print_map(printing_map);
			cout << endl<< endl<<'x';
			//delete printing_map;
		}
		cout <<	"qqqqqqqqqq"<<endl;
		/*printing_map = new char*[board_row];
		for (int i = 0; i < board_row; i++)
			printing_map[i] = new char[board_col];
		*/
		/*  IKINCI FOR ASAGIYA KAYDIRMA  */
		cout <<	"uuuuuuuuuuu"<<endl;
		for (int y = 0; y < board_row - board_y_index - size_row/*tetro boyu yap*/; y++)
		{
//			for (int i = 0; i < board_row; i++)
			for (int i = 0; i < board_row; i++)
				for (int j = 0; j < board_col; j++)
					printing_map[i][j] = board[i][j];

			//is collision ;




			//collision check
/*
			for (int i = 0; i < actual_tetromino.col_size; i++)
			{
				cout << "col check"<<endl;
				//cout <<"board[board_y_index][board_x_index - rl_index - 1] \"" << board[board_y_index][board_x_index - rl_index - 1]<<"\"";
				if (board[board_y_index + y - 1][board_x_index - rl_index] != ' ')
					return (board);
				cout << endl;
			}*/




			for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size ; tetro_x_index++)
			{
				for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size ; tetro_y_index++)
				{
//					printing_map[board_x_index+ y][board_y_index  - rl] = board[tetro_x_index][tetro_y_index];
					cout <<"board_y_index+ y+ tetro_y_index: "<<board_y_index+ y+ tetro_y_index << "[board_x_index  - rl + tetro_x_index]: "<<board_x_index  - rl + tetro_x_index<< "actual_tetromino.map[tetro_y_index][tetro_x_index]: " << actual_tetromino.map[tetro_y_index][tetro_x_index]<<endl;
					printing_map[board_y_index+ y+ tetro_y_index][board_x_index  - rl + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
					cout <<"board_y_index+ y+ tetro_y_index: "<<board_y_index+ y+ tetro_y_index << "[board_x_index  - rl + tetro_x_index]: "<<board_x_index  - rl + tetro_x_index<< "actual_tetromino.map[tetro_y_index][tetro_x_index]: " << actual_tetromino.map[tetro_y_index][tetro_x_index]<<endl;
				}

			
			}
//			cout << "asd"<<endl;
			cout <<endl <<"prm again"<<endl;
			print_map(printing_map);	
		//	delete[]printing_map;
		}



	}
	

	else
	{
		
	}
	
	return (printing_map);




	// /*   THAT FOR LOOPS LOOKS FOR RANGES OF TETROMINO AND MAP BORDERS TO NOT GET SEGMENTATION FAULTS    */

	// while (index < best_loc.y - 2/*&& index < actual_tetromino.get_map().size()-1*/)
	// {
	// 	for (int i = 0; i < size_row; i++)
	// 	{
	// 		for (int j = 0; j < size_col; j++)		
	// 		{
	// 			//if (i == best_loc.y && j == best_loc.x)
	// 				//if ((actual_tetromino.get_map())[i][j] != ' ' )
	// 				//	{
	// 						printing_map[i + index][j+k] = (actual_tetromino.get_map())[i][j]; 
	// 						//return;
	// 				//	}
	// 		}

	// 	cout << endl;
			
	// 	}
	// 	system("clear");
	// 	//print_map(printing_map);
	// 	printing_map = board;
	// 	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	// 	index++;//every step

	// }
	//board = printing_map;

}


#endif