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


class Tetromino
	{
	private:
		int 							dir;
		/*vector <vector<char> > collision_map
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'}
			};*/
		char							 ty;
	public:
		vector< vector<char> > map
			{
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'},
				{'0','0','0','0'}
			};	
		vector <vector<char> > collision_map;
		Tetromino(e_typ obj);// This defination used in homework
		Tetromino();
		bool	canFit();
		vector< vector <char> > 				get_coll_map();// To get collision map
		void								set_type(e_typ typ);// Not used in that code but in future, this function will help to me
		void											print();// Basic print map function
		void										rotate (int rot);// Rotate map. 1 for clockwise -1 for anticlockwise
		void					set_map(vector<vector<char>> map);// Setting map
		void 								init_collision_map();// Initialization of collision map
		inline void 					set_ty(char c){ ty = c; };// Setting type of Tetromino piece
		inline char 					get_ty(){ return (ty); };// Getting type of Tetromino piece
		inline vector< vector<char> > get_map() { return (map);};//Getting map of Tetromino piece
	};


void print_map(	vector< vector <char> > map);//for debug delete



class Tetris
{
public:
	int	tetro_index = -1;
	Tetris();
	//friend	Tetromino::Tetromino(e_typ obj);
	void	menu();
	void	enter_tetro_type();
	friend class Tetromino;
	friend Tetromino::Tetromino(e_typ typ);

	void	add();
	//inline vector< vector <char> >	get_map(){return (board);};
	loc best_opt_loc();
	bool canfit(/*vector< vector <char> > map,*/ Tetromino actual_tetromino, int x, int y);
	void animate(loc best_loc, Tetromino actual_tetromino);
	~Tetris();
	vector< Tetromino > arr;
private:
};




#endif