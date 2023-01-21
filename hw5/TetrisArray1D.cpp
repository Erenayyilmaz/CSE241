
#include "AbstractTetris.h"
#include "TetrisArray1D.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace abstract_tetris_nmspc;
//using namespace std;
//using namespace tetris_array_1d_nmspc;
/*
char** tetris_array_1d_nmspc::animate(int rot, Tetromino actual_tetromino)
//char** TetrisArray1D::animate(int rot, Tetromino actual_tetromino)
{
    // Create a 2D char array to hold the current state of the board
    char** printing_map = new char*[board_row];
    for (int i = 0; i < board_row; i++)
        printing_map[i] = new char[board_col];

    // Initialize the printing map with the current state of the board
    for (int i = 0; i < board_row; i++)
    {
        for (int j = 0; j < board_col; j++)
        {
            printing_map[i][j] = board[i][j];
        }
    }

    // Get the size of the actual tetromino
    int size_row = actual_tetromino.row_size;
    int size_col = actual_tetromino.col_size;

    // Initialize the indexes of the board and tetromino to their starting positions
    int board_y_index = 4;
    int board_x_index = board_col / 2;

    // Perform the requested number of rotations on the actual tetromino
    for (int i = 0; i < rot; i++)
        actual_tetromino.rotate(1);

    // Loop through the animation until the tetromino hits the bottom of the board
    bool reached_bottom = false;
    while (!reached_bottom)
    {
        // Update the printing map with the current state of the board and tetromino
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                printing_map[i][j] = board[i][j];
            }
        }

        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
            {
                printing_map[board_y_index + tetro_y_index][board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
            }
        }

        // Print the current state of the board
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        print_map(printing_map);

        // Update the indexes and check if the tetromino has reached the bottom
        board_y_index++;
        reached_bottom = (board_y_index + size_row >= board_row);

        // Clear the console and repeat the loop
        system("clear");
    }

    // Return the final state of the board
    return printing
}

*/

tetris_array_1d_nmspc::TetrisArray1D::TetrisArray1D(int size)
{
    board = new char[size];
    _size = size;
    for (int i = 0; i < _size; i++)
    {
        board[i] = ' ';
    }
    
}

tetris_array_1d_nmspc::TetrisArray1D::~TetrisArray1D()
{
    delete [] board;
}



void tetris_array_1d_nmspc::TetrisArray1D::draw()
{
	for (int i = 0; i < board_row ; i++)
	{
		for (int j = 0; j < board_col; j++)
			cout << board[i * board_col + j];
		cout << endl;
	}
}

tetris_array_1d_nmspc::TetrisArray1D::TetrisArray1D()
{
    board_col = 20;
    board_row = 20;
    _size = 400;
    board = new char[_size];
    for (int i = 0; i < _size; i++)
    {
        board[i] = ' ';
    }
}

tetris_array_1d_nmspc::TetrisArray1D::TetrisArray1D(int col, int row)
{
    board_col = col;
    board_row = row;
    _size = col * row;
    board = new char[_size];
    for (int i = 0; i < _size; i++)
    {
        board[i] = ' ';
    }
}
/*
void tetris_array_1d_nmspc::TetrisArray1D::animate(Tetromino actual_tetromino)
{
    char* printing_map = new char[board_row * board_col];

    for (int i = 0; i < board_row; i++)
    {
        for (int j = 0; j < board_col; j++)
        {
            printing_map[i * board_col + j] = board[i][j];
        }
    }

    int size_row = actual_tetromino.row_size;
    int size_col = actual_tetromino.col_size;

    int board_y_index = 4;
    int board_x_index = board_col / 2;

//    for (int i = 0; i < rot; i++)
//        actual_tetromino.rotate(1);

    bool reached_bottom = false;
    while (!reached_bottom)
    {
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                printing_map[i * board_col + j] = board[i][j];
            }
        }

        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
            {
                printing_map[(board_y_index + tetro_y_index) * board_col + board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        print_map(printing_map);

        board_y_index++;
        reached_bottom = (board_y_index + size_row >= board_row);

        system("clear");
    }

    return (printing_map);
}
*/


void tetris_array_1d_nmspc::TetrisArray1D::add_tetro_auto(Tetromino &other)
{

    // Initialize variables for the game loop
    char *printing_board = new char[board_row * board_col];
    int board_y_index = 4;
    int board_x_index = board_col / 2;
    bool reached_bottom = false;

    // Get user input for rotation and movement
    int rot_dir = 0, rot_count = 0;
    cout << "Enter rotation direction (1 for clockwise, -1 for counterclockwise): ";
	if(rand() / 2)
		rot_dir = 1;
	else
		rot_dir = -1;
	cout << rot_dir <<"\n";
    cout << "Enter rotation count: ";
	rot_count = rand()%5;
	cout << rot_count <<"\n";
    for (int i = 0; i < rot_count; i++)
        actual_tetromino.rotate(rot_dir);

    move_ctr += rot_count;
    int move_dir = 0, move_count = 0;
    cout << "Enter move direction (1 for right, -1 for left): ";
	if(rand() / 2)
		move_dir = 1;
	else
		move_dir = -1;
	cout << move_dir<<endl;
    cout << "Enter move count: ";
	move_count = rand() % 6;
	cout << move_count<< endl;
    move_ctr += move_count;
    board_x_index += move_dir * move_count;
	if ( move_dir * move_count < 0)
		lst_move_ctr = 'a';
	else if (move_dir * move_count == 0)
		lst_move_ctr = 's';
	else
		lst_move_ctr = 'd';

    // Game loop
    while (!reached_bottom)
    {
        // Copy the current board to the printing board
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                printing_board[i * board_col + j] = board[i * board_col + j];
            }
        }

        // Add the actual Tetromino to the printing board
        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
            {
                if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ')
                {
                    printing_board[(board_y_index + tetro_y_index) * board_col + board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
                }
            }
        }
        lst_move_ctr = 's';

        // Print the printing board
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                cout << printing_board[i * board_col + j];
            }
            cout << endl;
        }

        // Check if the Tetromino has reached the bottom or a collision has occurred
        reached_bottom = (board_y_index + actual_tetromino.row_size >= board_row);
        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size && !reached_bottom; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size && !reached_bottom; tetro_x_index++)
            {
                if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ' && board[(board_y_index + tetro_y_index) * board_col + (board_x_index + tetro_x_index)] != ' ')
                {
                    reached_bottom = true;
                }
            }
        }

        // Update the game state
        if (!reached_bottom)
        {
            board_y_index++;
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }
      /*
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                board[i * board_col + j] = printing_board[i * board_col + j];
            }
        }*/
        //draw();


/*
    // Add the actual Tetromino to the board
    for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
    {
        for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
        {
            if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ')
            {
            _board[board_y_index + tetro_y_index][board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
            }
        }
    }
*/

    for (int i = 0; i < board_row; i++)
    {
        for (int j = 0; j < board_col; j++)
        {
            //cout << printing_board[i * board_col + j];
            board[i * board_col + j] = printing_board[i * board_col + j];
        }
        //cout << endl;
    }

    // Clean up
    delete[] printing_board;


}

void tetris_array_1d_nmspc::TetrisArray1D::animate(Tetromino actual_tetromino)
{
    // Initialize variables for the game loop
    char *printing_board = new char[board_row * board_col];
    int board_y_index = 4;
    int board_x_index = board_col / 2;
    bool reached_bottom = false;

    // Get user input for rotation and movement
    int rot_dir = 0, rot_count = 0;
    cout << "Enter rotation direction (1 for clockwise, -1 for counterclockwise): ";
    cin >> rot_dir;
    cout << "Enter rotation count: ";
    cin >> rot_count;
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

    // Game loop
    while (!reached_bottom)
    {
        // Copy the current board to the printing board
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                printing_board[i * board_col + j] = board[i * board_col + j];
            }
        }

        // Add the actual Tetromino to the printing board
        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
            {
                if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ')
                {
                    printing_board[(board_y_index + tetro_y_index) * board_col + board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
                }
            }
        }

        // Print the printing board
        for (int i = 0; i < board_row; i++)
        {
            for (int j = 0; j < board_col; j++)
            {
                cout << printing_board[i * board_col + j];
            }
            cout << endl;
        }

        // Check if the Tetromino has reached the bottom or a collision has occurred
        reached_bottom = (board_y_index + actual_tetromino.row_size >= board_row);
        for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size && !reached_bottom; tetro_y_index++)
        {
            for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size && !reached_bottom; tetro_x_index++)
            {
                if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ' && board[(board_y_index + tetro_y_index) * board_col + (board_x_index + tetro_x_index)] != ' ')
                {
                    reached_bottom = true;
                }
            }
        }

        // Update the game state
        if (!reached_bottom)
        {
            board_y_index++;
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }

/*
    // Add the actual Tetromino to the board
    for (int tetro_y_index = 0; tetro_y_index < actual_tetromino.row_size; tetro_y_index++)
    {
        for (int tetro_x_index = 0; tetro_x_index < actual_tetromino.col_size; tetro_x_index++)
        {
            if (actual_tetromino.map[tetro_y_index][tetro_x_index] != ' ')
            {
            _board[board_y_index + tetro_y_index][board_x_index + tetro_x_index] = actual_tetromino.map[tetro_y_index][tetro_x_index];
            }
        }
    }
*/
    // Print the board
    for (int i = 0; i < board_row; i++)
    {
        for (int j = 0; j < board_col; j++)
        {
            //cout << printing_board[i * board_col + j];
            board[i * board_col + j] = printing_board[i * board_col + j];
        }
        //cout << endl;
    }

    // Clean up
    delete[] printing_board;
}


void tetris_array_1d_nmspc::TetrisArray1D::readFromFile(const string file_name)
{
    ifstream read;
    read.open(file_name);

    int rows = 0;
    int cols = 0;
    string line;
    while (getline(read, line))
    {
        rows++;
        cols = max(cols, (int)line.length());
    }

    char* ret_arr = new char[rows * cols];

    read.clear();
    read.seekg(0, ios::beg);
    int row_index = 0;
    while (getline(read, line))
    {
        for (int col_index = 0; col_index < cols; col_index++)
        {
            if (col_index < line.length())
                ret_arr[row_index * cols + col_index] = line[col_index];
            else
                ret_arr[row_index * cols + col_index] = ' ';
        }
        row_index++;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ret_arr[i * cols + j];
        }
        cout <<endl;
    }
    
    read.close();
}


void tetris_array_1d_nmspc::TetrisArray1D::writeToFile(const string file_name)
{
    ofstream write_file;
    write_file.open(file_name);

    for (int i = 0; i < board_row; i++)
    {
        for (int j = 0; j < board_col; j++)
        {
            write_file << board[i * board_col + j];
        }
        write_file << endl;
    }

    write_file.close();
}

char tetris_array_1d_nmspc::TetrisArray1D::lastMove() const
{
    return (lst_move_ctr);
}

int tetris_array_1d_nmspc::TetrisArray1D::numberOfMoves() const
{
    return (move_ctr);
}

Tetromino & tetris_array_1d_nmspc::TetrisArray1D::operator+=(Tetromino &other)
{
	actual_tetromino = other;
	animate(actual_tetromino);
	return (actual_tetromino);
}

/*

abstract_tetris_nmspc::Tetromino abstract_tetris_nmspc::random_tetromino() {
	int random = rand();
	random %= 7;
	e_typ ran = static_cast<e_typ> (random);
	return Tetromino(ran);
}

abstract_tetris_nmspc::Tetromino abstract_tetris_nmspc::tetromino_from_char(char c) {
	switch (c) {
		case 'i':
			return Tetromino(e_typ::i);
		case 'j':
			return Tetromino(e_typ::j);
		case 'l':
			return Tetromino(e_typ::l);
		case 'o':
			return Tetromino(e_typ::o);
		case 's':
			return Tetromino(e_typ::s);
		case 't':
			return Tetromino(e_typ::t);
		case 'z':
			return Tetromino(e_typ::z);
		default:
			return Tetromino();
	}
}
*/

