#include "AbstractTetris.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#if !defined(TETRISVECTOR_H)
#define TETRISVECTOR_H

using namespace abstract_tetris_nmspc;

//vector <vector <char>> str_to_vvc(vector <string> str);

namespace tetris_vector_nmspc
{
	class TetrisVector : public AbstractTetris
	{
	private:
		int board_row;
		int board_col;
		vector <vector <char>> _board;
		Tetromino actual_tetromino;

	public:
		TetrisVector();
		TetrisVector(int row, int col);
		~TetrisVector();

		void draw() override;
		void  readFromFile(const string file_name) override;
		void writeToFile(const string file_name) override;
		void animate(Tetromino actual_tetromino) override;
		char lastMove() const override;
		int numberOfMoves() const  override;
		//void sleep();
		void add_tetro_auto(Tetromino &other);
		void print_map(vector <vector <char>>);
		Tetromino& operator+=(Tetromino &other) /*override*/;
	};
	
	
} // namespace tetris_vector_nmspc


#endif // TETRISVECTOR_H

