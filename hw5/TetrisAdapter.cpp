#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "AbstractTetris.h"
#include "TetrisAdapter.h"

using namespace tetris_adapter_nmspc;


template <typename T>
tetris_adapter_nmspc::TetrisAdapter<T>::TetrisAdapter()
{
    // Initialize the board using the default constructor of the T class
    board_col = 0;
    board_row = 0;
    _board = T();
}

// template <typename T>
// tetris_adapter_nmspc::TetrisAdapter<T>::TetrisAdapter(int board_row, int board_col)
// {
//     this->board_col = board_col;
//     this->board_row = board_row;
//     _board = T(board_row, board_col);
    
// }

template <typename T>
TetrisAdapter<T>::TetrisAdapter(int board_row, int board_col)
{
    _board.resize(board_row);
    for (auto& row : _board)
    {
        row.resize(board_col);
    }
	
	for (int i = 0; i < board_row ; i++)
		for (int j = 0; j < board_col; j++)
			_board[i][j] = ' ';

    this->board_row = board_row;
    this->board_col = board_col;
}


template <typename T>
tetris_adapter_nmspc::TetrisAdapter<T>::~TetrisAdapter()
{
}


template <typename T>
Tetromino& tetris_adapter_nmspc::TetrisAdapter<T>::operator+=(Tetromino &other)
{
	actual_tetromino = other;
	animate(actual_tetromino);
	return (actual_tetromino);
}


template <typename T>
char tetris_adapter_nmspc::TetrisAdapter<T>::lastMove() const
{
   	return (lst_move_ctr);
}

//tetris_adapter_nmspc::tetris_adapter_nmspc::TetrisAdapter<T>::numberOfMoves

template <typename T>
int tetris_adapter_nmspc::TetrisAdapter<T>::numberOfMoves()const
{
    return (move_ctr);
}


template <typename T> 
void tetris_adapter_nmspc::TetrisAdapter<T>::writeToFile(const string file_name)
{
	ofstream write_file;
	write_file.open(file_name);

	for (const auto& row : _board) {
		for (const auto& c : row) {
			write_file << c;
		}
		write_file << endl;
	}

	write_file.close();
}

template <typename T> 
void tetris_adapter_nmspc::TetrisAdapter<T>::readFromFile(const string file_name)
{
	vector<vector<char>> vect;

	ifstream read;
	read.open(file_name);

	string line;
	while(getline(read,line)){
		vector<char> temp;
		for(char c: line){
			temp.push_back(c);
		}
		vect.push_back(temp);
	}

	read.close();
	cout << endl;
	cout << endl;
}

template <typename T> 
void tetris_adapter_nmspc::TetrisAdapter<T>::draw()
{
	for (int i = 0; i < board_row ; i++)
	{
		for (int j = 0; j < board_col; j++)
			cout << _board[i][j];
		cout << endl;
	}
}

template <typename T>
void tetris_adapter_nmspc::TetrisAdapter<T>::animate(Tetromino actual_tetromino)
{
	//cout << "animate basi"<<endl;
	T printing_map;
	//	cout << "0" <<"tet sizes"<< actual_tetromino.row_size <<"tet col"<< actual_tetromino.col_size<< endl;
	//cout << "board_row" << board_row<<endl;
	printing_map.resize(board_row);
	//	cout << "++" << endl;
	for (int i = 0; i < board_row; i++)
		printing_map[i].resize(board_col);

	//cout << "1" << endl;

	int board_y_index = 4;
	int board_x_index = board_col / 2;

	//cout << "_board.size() " << _board.size() << endl;
	int rot_dir = 0, rot_count = 0;
	cout << "Enter rotation direction (1 for clockwise, -1 for counterclockwise): ";
	cin >> rot_dir;
	cout << "Enter rotation count: ";
	cin >> rot_count; /*|| board[board_y_index + actual_tetromino.row_size][board_x_index + tetro_x_index] == ' '*/
	for (int i = 0; i < rot_count; i++)
		actual_tetromino.rotate(rot_dir);

	move_ctr += rot_count;
	int move_dir = 0, move_count = 0;
	cout << "Enter move direction (1 for right, -1 for left): ";
	cin >> move_dir;
	cout << "Enter move count: ";
	cin >> move_count;
	move_ctr += move_count;
	board_x_index += move_dir * move_count;
	if ( move_dir * move_count < 0)
		lst_move_ctr = 'a';
	else if (move_dir * move_count == 0)
		lst_move_ctr = 's';
	else
		lst_move_ctr = 'd';
	bool reached_bottom = false;
	while (!reached_bottom)
	{
		for (int i = 0; i < board_row ; i++)
			for (int j = 0; j < board_col; j++)
				printing_map[i][j] = _board[i][j];

    // Check for collision
    bool collision = false;
	lst_move_ctr = 's';

    for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
    {
        for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
        {
            if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ' && printing_map[board_y_index + tetro_y_index][board_x_index + tetro_x_index] != ' ' && _board[board_y_index + tetro_y_index][board_x_index + tetro_x_index] != ' ')
            {
                collision = true;
                break;
            }
        }
        if (collision)
        {
            break;
        }
    }
    if (collision)
    {
        // Add Tetromino to _board and break out of loop
        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
            {
                if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ')
                {
                    printing_map[board_y_index + tetro_y_index][board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
                }
            }
        }
		for (int i = 0; i < board_row ; i++)
			for (int j = 0; j < board_col; j++)
				_board[i][j] = printing_map[i][j];
        //break;
		draw();
		return ;
    }
	else
	{
		for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
			{
				for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
				{
						printing_map[board_y_index + tetro_y_index][board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
				}
			}
	}
	
	//	cout << "4" << endl;
		//print_map(printing_map);
		//draw();
		this_thread::sleep_for(chrono::milliseconds(50));

		board_y_index++;
		//cout << "		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row)); " << endl << "board_y_index: " << board_y_index;
		//cout << "actual_tetromino.row_size:" << actual_tetromino.row_size << "board_row" << board_row <<endl;
		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row));
	//	cout << "5" << endl;
		//system("clear");
		
		if(reached_bottom)
		{
		//	cout << "reached_bottom"<<endl;
			//system("clear");
			//print_map(printing_map);
			cout << endl;
			for (int i = 0; i < board_row ; i++)
				for (int j = 0; j < board_col; j++)
					_board[i][j] = printing_map[i][j];
			
			draw();		
		}
		if (!reached_bottom)
			move_ctr++;

	}

}
  
