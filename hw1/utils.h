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
	int dir;
	vector<vector<char>> map;
public:

	//Tetromino(int	typ, int dir);(
	Tetromino(e_typ obj);
	Tetromino();
	bool					canFit();
	void					set_type(e_typ typ);
	void								print();
	int							rotate (int rot);
	void		set_map(vector<vector<char>> map);

	vector< vector<char> > get_map() { return (map);};
};

void					get_info(vector<Tetromino> arr);

#endif