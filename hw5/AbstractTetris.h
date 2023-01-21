
#if !defined(ABSTRACTTETRIS_H)
# define ABSTRACTTETRIS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <chrono>
#include <thread>
#include <deque>

namespace abstract_tetris_nmspc
{

/*STRONG ENUM*/
enum class e_typ {i = 0, o, t, j, l, s, z, r, q};

struct loc
{
	int x;
	int y;
};


using namespace std;
//using namespace tetris_vector_nmspc;

//using namespace tetris_array_1d_nmspc;

/*		INPUT CONTROL FUNCTIONS		*/

int					my_atoi(string nptr);
int				my_isdigit(string	s);
int						is_legal(char c);
int					my_isalpha(string c);



		class Tetromino
		{
		private:
			int 					dir;
		public:
//			char		**map;
			vector< vector<char> > map
			{
				{' ',' ',' ',' '},
				{' ',' ',' ',' '},
				{' ',' ',' ',' '},
				{' ',' ',' ',' '}
			};				//int			tetro_id = -1;
			int				row_size;
			int 			col_size;
			Tetromino(e_typ obj);// This defination used in homework
			Tetromino();
			//~Tetromino();
			vector< vector<char> >										rotate (int rot);// Rotate map. 1 for clockwise -1 for anticlockwise
			void	draw_map();
			inline vector< vector<char> >get_map() 				    { return (map);};//Getting map of Tetromino piece
		};


		class AbstractTetris
		{
			protected:
				int board_row;
				int board_col;
				int move_ctr = 0;
				char lst_move_ctr = 's';
			public:
				//virtual AbstractTetris() = 0;
				//virtual ~AbstractTetris() = 0;
				virtual void draw() = 0;
				virtual void  readFromFile(const string file_name) = 0;
				virtual void writeToFile(const string file_name) = 0;
				virtual void animate(Tetromino actual_tetromino) = 0;
				virtual char lastMove() const = 0;
				virtual int numberOfMoves() const = 0;
			    virtual Tetromino& operator+=(Tetromino &other) = 0;
		};

		Tetromino random_tetromino();
		Tetromino tetromino_from_char(char c);

} // namespace abstract_tetris_nmspc

#endif // ABSTRACTTETRIS_H
