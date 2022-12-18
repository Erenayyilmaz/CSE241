#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace	std;
namespace kea
{


#ifndef UTILS_H
#define UTILS_H



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
		Tetromino(e_typ obj);// This defination used in homework
		Tetromino();
		vector< vector <char> > 				get_coll_map();// To get collision map
		void								set_type(e_typ typ);// Not used in that code but in future, this function will help to me
		void											print();// Basic print map function
		char**										rotate (int rot);// Rotate map. 1 for clockwise -1 for anticlockwise
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
	void print_map(	char **map);
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

}
#endif