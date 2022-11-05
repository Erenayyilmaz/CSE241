#include <vector>
#include <iostream>

#ifndef UTILS_H
#define UTILS_H

using namespace	std;

/*STRONG ENUM*/
enum class e_typ {i = 0, o, t, j, l, s, z};

/*		INPUT CONTROL FUNCTIONS		*/

long unsigned int					my_atoi(string nptr);
long unsigned int				my_isdigit(string	s);
long unsigned int						is_legal(char c);
long unsigned int					my_isalpha(string c);

class Tetromino
{
private:
	int 							dir;
	vector< vector<char> > map
		{
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'}
		};	
	vector <vector<char> > collision_map
		{
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'},
			{'0','0','0','0'}
		};
	char							 ty;
public:

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

/*			To make short main.cpp, above functions has written in utils.cpp and here			*/

void														get_info(vector<Tetromino> arr);
vector< vector <char> > merge_coll_maps(Tetromino other, vector< vector<char> > merged_map);
vector< vector <char> > 					shift_coll_map(vector< vector <char> >, int indx);
int		most_surf(vector< vector <char> > merged_map);
int										is_collision(vector< vector <char> > merged_map);
void print_map(	vector< vector <char> > map);//for debug delete


#endif