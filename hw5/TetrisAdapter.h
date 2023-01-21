#include "AbstractTetris.h"

#if !defined(TETRISADAPTER_H)
#define TETRISADAPTER_H

using namespace abstract_tetris_nmspc;


namespace tetris_adapter_nmspc
{
    template <typename T>
    class TetrisAdapter:public AbstractTetris
    {
    private:
        T _board;
        int board_row;
		int board_col;
        Tetromino actual_tetromino;
    public:
        TetrisAdapter();
        TetrisAdapter(int board_row, int board_col);
        ~TetrisAdapter();
        void draw() override;
        void readFromFile(const string file_name) override;
        void writeToFile(const string file_name) override;
        void animate(Tetromino actual_tetromino) override;
        char lastMove() const override;
        int numberOfMoves() const override;
 		Tetromino& operator+=(Tetromino &other)override;

    };
    
template class TetrisAdapter < vector<vector <char>> >;    
template class TetrisAdapter < deque<vector <char>> >;    
template class TetrisAdapter < vector<deque <char>> >;    
template class TetrisAdapter < deque<deque <char>> >;    

} // namespace tetris_adapter_nmspc

#endif // TETRISADAPTER_H
