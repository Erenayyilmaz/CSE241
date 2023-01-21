
#include "AbstractTetris.h"
#include "TetrisAdapter.h"
#include "TetrisVector.h"
#include "TetrisArray1D.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "TetrisAdapter.cpp"

using namespace std;

using namespace tetris_adapter_nmspc;
using namespace tetris_vector_nmspc;

int main() {
    // Initialize the Tetris board
    
    string						 row_string;
	string						 column_string;
	int		row_size = 0,	column_size = 0, i = 0, control = 0;
    
    cout <<  "enter size of rows of the Tetris board" << endl;
	cin >> row_string;
	if (my_isdigit(row_string))
		row_size = my_atoi(row_string);
	else{
			cout <<"wrong";
			exit(1);
	}
	cout <<  "enter size of columns of the Tetris board" << endl;
	cin >> column_string;
	if (my_isdigit(column_string))
		column_size = my_atoi(column_string);
	else{
			cout <<"wrong";
			exit(1);
	}
    if (column_size < 4)
        column_size = 4;
    if (row_size < 4)
        row_size = 4;

    string  type_of_tc_str;
    cout << "type of the Tetris class (V for vector, 1 for array1D, A for adaptor)";
	cin >> type_of_tc_str;
    if (type_of_tc_str[0] != 'V' && type_of_tc_str[0] != '1' && type_of_tc_str[0] != 'A' )
        {
            cerr << "error";
            exit (1);
        }
                    TetrisVector tv(row_size, column_size);                    
                    tetris_array_1d_nmspc::TetrisArray1D ta(row_size, column_size);
                    tetris_adapter_nmspc::TetrisAdapter<vector<vector<char>>> tad(row_size, column_size);
    
    bool done = false;
    while (!done) {
        cout << "Enter type of Tetromino piece (i, j, l, o, s, t, r for random, or q to quit): ";
        string tetro_type_string;
        cin >> tetro_type_string;
        if (is_legal(tetro_type_string[0])) {
            if (tetro_type_string[0] == 'q') {
                done = true;
            }
            else {
                // Add the Tetromino to the game
                abstract_tetris_nmspc::Tetromino tetromino;
                if (tetro_type_string[0] == 'r') {
                    tetromino = random_tetromino();
                }
                else {
                    tetromino = tetromino_from_char(tetro_type_string[0]);
                }
                if (type_of_tc_str[0] == 'V')
                {
                    tv.operator+=(tetromino);
                    tv.writeToFile("save.txt");
                }
                else if (type_of_tc_str[0] == '1')
                {
                    ta.operator+=(tetromino);
                    ta.writeToFile("save.txt");
                }
                else if (type_of_tc_str[0] == 'A')
                {
                    tad.operator+=(tetromino);
                    tad.writeToFile("save.txt");
                }
            }
        }
        else {
            cout << "Invalid Tetromino type." << endl;
        }
    }

    cout << "\nsave game file: \n";
    if (type_of_tc_str[0] == 'V')
        tv.readFromFile("save.txt");
    else if (type_of_tc_str[0] == '1')
        ta.readFromFile("save.txt");
    else
        tad.readFromFile("save.txt");
cout << endl;
    return (0);
}

