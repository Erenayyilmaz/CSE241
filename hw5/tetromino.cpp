
#include "AbstractTetris.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
//using namespace tetromino_nmspc;
using namespace std;

/*
abstract_tetris_nmspc::Tetromino::~Tetromino()
{
	for (int i = 0; i < row_size; i++)
	{
			delete [] map[i];
	}
	delete [] map;
}
*/
abstract_tetris_nmspc::Tetromino::Tetromino()
{
	map.resize(1);
	map[0].resize(4);
	map[0][0] = 'i';
	map[0][1] = 'i';
	map[0][2] = 'i';
	map[0][3] = 'i';
}
/*
abstract_tetris_nmspc::Tetromino::Tetromino()
{
	map = new char*[1];
	map[0] = new char[4];
	map[0][0] = 'i';
	map[0][1] = 'i';
	map[0][2] = 'i';
	map[0][3] = 'i';
	////set_ty('i');
}
*/

/*
void abstract_tetris_nmspc::Tetris::operator+=(Tetromino &tetro)
{
	add_to_arr(tetro);
	arr[++index].tetro_id = index;
}
*/

 int	abstract_tetris_nmspc::my_isdigit(string	s)
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

 int	abstract_tetris_nmspc::my_isalpha(string c)
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

 int			abstract_tetris_nmspc::my_atoi(string nptr)
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

 int	abstract_tetris_nmspc::is_legal(char c)
{
		// THIS FUNCTION CONTROLS IS GIVEN CHAR IS LEGAL FOR PROGRAM
	if (c == 'i' ||c == 'o' ||c == 't' ||c == 'j' ||c == 'l' ||c == 's' || c == 'z' || c == 'q'|| c == 'r')
		return (1);
	if (c == 'I' ||c == 'O' ||c == 'T' ||c == 'J' ||c == 'L' ||c == 'S' || c == 'Z'|| c == 'Q'|| c == 'R')
		return (1);
	return (0);
}


/*
void abstract_tetris_nmspc::Tetris::add_to_arr(Tetromino &adding)
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
*/

// void abstract_tetris_nmspc::Tetris::enter_tetro_type()
// {
// 	string						 tetro_type_string;
// 	cout <<  "enter type of Tetromino piece";

// 	cin >> tetro_type_string;
// 	if (is_legal(tetro_type_string[0]))
// 	{
// 		if ( tetro_type_string[0] != 'q')
// 		{
// 			e_typ ran;
// 			if (tetro_type_string[0] == 'r')
// 			{
// 				int	random = rand();
// 				random %= 7;
// 				ran = static_cast<e_typ> (random);
// 				Tetromino temp(ran);
// 				arr[++index] = temp;
// 				arr[index].tetro_id = index;
// 			}
			
// 		}
// 		else
// 		{
// 			cout << "finished";
// 			exit(1);
// 			return;
// 		}
		
// 	}
// 	else
// 	{
// 		cout <<  "Try again";
// 		return(enter_tetro_type());
// 	}
// }

abstract_tetris_nmspc::Tetromino::Tetromino(e_typ typ)
{

	switch (typ)
	{
	case e_typ::i :
		//map = new char*[1];
		//map[0] = new char[4];
		map.resize(1);
		map[0].resize(4);
		map[0][0] = 'i';
		map[0][1] = 'i';
		map[0][2] = 'i';
		map[0][3] = 'i';
		//set_ty('i');
		col_size = 4;
		row_size = 1;
		break;

	case e_typ::j :
		//map = new char*[3];
		map.resize(3);
		for (int i = 0; i < 3;i++)
			map[i].resize(2);
		map[0][0] = ' ';
		map[0][1] = 'j';
		map[1][0] = ' ';
		map[1][1] = 'j';
		map[2][0] = 'j';
		map[2][1] = 'j';
		col_size = 2;
		row_size = 3;
		break;
	case e_typ::o :
		map.resize(2);
		map[0].resize(2);
		map[1].resize(2);
		//map = new char*[2];
		//map[0] = new char[2];	
		//map[1] = new char[2];
		map[0][0] = 'o';	
		map[1][0] = 'o';	
		map[0][1] = 'o';	
		map[1][1] = 'o';	
		col_size = 2;
		row_size = 2;

		//set_ty('o');
		break;
		
	case e_typ::t :
		map.resize(2);
		map[0].resize(3);
		map[1].resize(3);
		//map = new char*[2];
		//map[0] = new char[3];	
		//map[1] = new char[3];
		map[0][0] = ' ';	
		map[0][1] = 't';	
		map[0][2] = ' ';	
		map[1][0] = 't';
		map[1][1] = 't';
		map[1][2] = 't';
		row_size = 2;
		col_size = 3;
		//set_ty('t');

		break;


			
	case e_typ::l :
		map.resize(3);
		//map = new char*[3];
		for (int i = 0; i < 3 ; i++)
			map[i].resize(2);
		map[0][0] = 'l';	
		map[0][1] = 'l';	
		map[1][0] = 'l';
		map[1][1] = ' ';
		map[2][0] = 'l';
		map[2][1] = ' ';
		col_size = 2;
		row_size = 3;
		break;

			
	case e_typ::s :
		map.resize(2);
		map[0].resize(3);
		map[1].resize(3);
		map[0][0] = ' ';	
		map[0][1] = 's';	
		map[0][2] = 's';	
		map[1][0] = 's';
		map[1][1] = 's';
		map[1][2] = ' ';
		col_size = 3;
		row_size = 2;
		//set_ty('s');
		break;

			
	case e_typ::z :
		map.resize(2);
		map[0].resize(3);
		map[1].resize(3);
		map[0][0] = 'z';	
		map[0][1] = 'z';	
		map[0][2] = ' ';	
		map[1][0] = ' ';
		map[1][1] = 'z';
		map[1][2] = 'z';
		//set_ty('z');
		col_size = 3;
		row_size = 2;
		break;

	case e_typ::q:
		//set_ty('q');
		break;

	default:
		//set_ty('q');
		break;
	}
}

vector< vector<char> >abstract_tetris_nmspc::Tetromino::rotate(int rot)
{
		if (rot == 1)
	{
		 int	i, j, k;
		 int map_col_size = map.size();
		 int map_row_size = (map[0]).size();

		vector < vector <char> > tmp_map;
		tmp_map.resize(map_row_size);
		for (i = 0; i < map_row_size; i++)
		{
			tmp_map[i].resize(map_col_size);
		}
		for (j = 0; j < map_row_size; j++)
		{
			for (k = 0; k < map_col_size; k++)
			{
				tmp_map[j][k] = map[k][j];
			}
			
		}
		map = tmp_map;
		int temp = row_size;
		row_size = col_size;
		col_size = temp;
	}
	else if (rot == -1)
	{
		map =rotate(1);
		map =rotate(1);
		map =rotate(1);
	}
	return (map);
}

