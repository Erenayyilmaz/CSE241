
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
    cout << endl <<"AUTO" << endl;
    Tetromino tet_i(e_typ::i);
    Tetromino tet_j(e_typ::j);
    Tetromino tet_l(e_typ::l);
    Tetromino tet_o(e_typ::o);
    Tetromino tet_s(e_typ::s);
    Tetromino tet_t(e_typ::t);
    Tetromino tet_z(e_typ::z);
    Tetromino tet_r(e_typ::r);

    cout << endl <<" tet_i "<<endl;
    tet_i.draw_map();
    tet_i.rotate(1);
    tet_i.draw_map();
    tet_i.rotate(1);
    tet_i.draw_map();
    tet_i.rotate(1);
    tet_i.draw_map();
    cout << endl <<" tet_j "<<endl;
    tet_j.draw_map();
    tet_j.rotate(1);
    tet_j.draw_map();
    tet_j.rotate(1);
    tet_j.draw_map();
    tet_j.rotate(1);
    tet_j.draw_map();
    cout << endl <<" tet_l "<<endl;
    tet_l.draw_map();
    tet_l.rotate(1);
    tet_l.draw_map();
    tet_l.rotate(1);
    tet_l.draw_map();
    tet_l.rotate(1);
    tet_l.draw_map();
    cout << endl <<" tet_o "<<endl;
    tet_o.draw_map();
    tet_o.rotate(1);
    tet_o.draw_map();
    tet_o.rotate(1);
    tet_o.draw_map();
    tet_o.rotate(1);
    tet_o.draw_map();
    cout << endl <<" tet_s "<<endl;
    tet_s.draw_map();
    tet_s.rotate(1);
    tet_s.draw_map();
    tet_s.rotate(1);
    tet_s.draw_map();
    tet_s.rotate(1);
    tet_s.draw_map();
    cout << endl <<" tet_t "<<endl;
    tet_t.draw_map();
    tet_t.rotate(1);
    tet_t.draw_map();
    tet_t.rotate(1);
    tet_t.draw_map();
    tet_t.rotate(1);
    tet_t.draw_map();
    cout << endl <<" tet_z "<<endl;
    tet_z.draw_map();
    tet_z.rotate(1);
    tet_z.draw_map();
    tet_z.rotate(1);
    tet_z.draw_map();
    tet_z.rotate(1);
    tet_z.draw_map();

    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << endl<< endl<< endl;

    cout <<"Program will take row 's and column 's size from user."<<endl;
    cout <<"Then it will check whether inputs are legal or not ."<<endl;
    cout <<"You have to enter type of tetris class (Vector or 1d array or adaptor) ."<<endl;
    cout << "Then while you enter q, tetrominos will added to board with operator += "<<endl;
    cout << "void  readFromFile(const string file_name) : This function reads board save from file that i type"<<endl;
    cout << "For each 3 classes, it reads in itself's format(Vector or 1D array etc.)"<<endl;
    cout << "void writeToFile(const string file_name): This functşon writes board into file"<<endl;
    cout << "void animate(Tetromino actual_tetromino): It takes a tetromino and print it on it's temporary board when there is no collision and border touch."<<endl;
    cout << "numberOfMoves() can return number of movement of Tetromino "<<endl;
    cout << "lastMove() return last movement of tetromino in board "<<endl;
    cout << endl<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(8000));
    string						 row_string;
	string						 column_string;
	int		row_size = 0,	column_size = 0, i = 0, control = 0;
    
    cout <<  "enter size of rows of the Tetris board" << endl;
	//cin >> row_string;
    cout << "20"<<endl;
    row_string = "20";
	if (my_isdigit(row_string))
		row_size = my_atoi(row_string);
	else{
			cout <<"wrong";
			exit(1);
	}
	cout <<  "enter size of columns of the Tetris board" << endl;
	//cin >> column_string;
    column_string = "20";
    cout << "20"<<endl;
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
    cout << "type of the Tetris class (V for vector, 1 for array1D, A for adaptor)"<< endl;

	//cin >> type_of_tc_str;
    cout << "V";
    type_of_tc_str = "V";
                    TetrisVector tv(row_size, column_size);                    
                    tetris_array_1d_nmspc::TetrisArray1D ta(row_size, column_size);
                    tetris_adapter_nmspc::TetrisAdapter<vector<vector<char>>> tad(row_size, column_size);
    
    bool done = false;
    int index = -1;
    while (!done ) {
        cout << "Enter type of Tetromino piece (i, j, l, o, s, t, r for random, or q to quit): "<<endl;
        index++;
            switch (index + 1)
            {
            case 1:
                cout << endl<<"i"<<endl;
                break;

            case 2:
                cout << endl<<"r"<<endl;
                break;

            case 3:
                cout << endl<<"o"<<endl;
                break;      
            case 4:
                cout << endl<<"r"<<endl;
            default:
                break;
            }
        string tetro_type_string = "r";
        //cin >> tetro_type_string;
        if (index == 0)
            tetro_type_string = "i";
        else if (index == 1)        
            tetro_type_string = "r";
        else if (index == 2)        
            tetro_type_string = "o";
        else if (index == 3)        
            tetro_type_string = "r";       
        if (is_legal(tetro_type_string[0])) {
            if (tetro_type_string[0] == 'q') {
                done = true;
            }
            else {
                // Add the Tetromino to the game
                abstract_tetris_nmspc::Tetromino tetromino;
                if (tetro_type_string[0] == 'r') {
                    cout << "ilke gridi"<<endl;
                    tetromino = random_tetromino();
                }
                else {
                    cout << "ikinciye gridi"<<endl;
                    tetromino = tetromino_from_char(tetro_type_string[0]);
                    cout <<endl ;
                    
                }
                if (type_of_tc_str[0] == 'V')
                {
                    //tv.operator+=(tetromino);
                    tv.add_tetro_auto(tetromino);
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
            if(index == 4)
                done = true;
        }
        else {
            cout << "Invalid Tetromino type." << endl;
        }
    }

    cout << "\nsave game file: \n";
    tv.readFromFile("save.txt");
    cout << endl;

    return (0);
}

