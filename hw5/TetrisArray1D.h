#include "AbstractTetris.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#if !defined(TETRISARRAY1D_H)
# define TETRISARRAY1D_H

using namespace abstract_tetris_nmspc;

namespace tetris_array_1d_nmspc
{
    class TetrisArray1D : public AbstractTetris
    {
    private:
        char *board;
        int _size;
        int board_row;
        int board_col;
        Tetromino actual_tetromino;
    public:
        TetrisArray1D(int size);
        TetrisArray1D(int row, int col);
        TetrisArray1D();        
        ~TetrisArray1D();


        void draw() override;
        void  readFromFile(const string file_name) override;
        void writeToFile(const string file_name) override;
        void animate(Tetromino actual_tetromino) override;
        char lastMove() const override;
        int numberOfMoves() const  override;
        void add_tetro_auto(Tetromino &other);
        Tetromino& operator+=(Tetromino &other) override;
    };
    
} // namespace tetris_array_1d_nmspc


#endif // TETRISARRAY1D_H
