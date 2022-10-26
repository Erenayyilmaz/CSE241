#include <vector>
#include <iostream>

#ifndef UTILS_H
#define UTILS_H

using namespace	std;

enum class e_typ {i = 0, o, t, j, l, s, z};

long unsigned int					my_atoi(string nptr);
long unsigned int				my_isdigit(string	s);
long unsigned int						is_legal(char c);
long unsigned int					my_isalpha(string c);

class Tetromino
{
private:
	//vector< vector <char> > merged_map;
	int 							dir;
	vector< vector<char> >			 map;
	vector <vector<char> > collision_map;
	char							 ty;
public:

	//Tetromino(int	typ, int dir);(
	Tetromino(e_typ obj);
	Tetromino();
	bool	canFit();
	vector< vector <char> > 				get_coll_map();
	void								set_type(e_typ typ);
	void											print();
	int										rotate (int rot);
	void					set_map(vector<vector<char>> map);
	void 								init_collision_map();
	inline void 					set_ty(char c){ ty = c; };
	inline char 					get_ty(){ return (ty); };
	inline vector< vector<char> > get_map() { return (map);};
};

void					get_info(vector<Tetromino> arr);
vector< vector <char> > merge_coll_maps(Tetromino other, vector< vector<char> > merged_map);
vector< vector <char> > 					shift_coll_map();
int		most_surf(vector< vector <char> > merged_map);
int										is_collision(vector< vector <char> > merged_map);


#endif