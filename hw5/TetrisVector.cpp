#include "AbstractTetris.h"
#include "TetrisVector.h"
/*
using namespace tetris_vector_nmspc;
using namespace tetromino_nmspc;
*/

//using namespace std;

tetris_vector_nmspc::TetrisVector::~TetrisVector()
{
	
}


tetris_vector_nmspc::TetrisVector::TetrisVector()
{
	board_row = 0;
	board_col = 0;
	//_board = nullptr;
}

tetris_vector_nmspc::TetrisVector::TetrisVector(int row, int col)
{
	//cout << "\ncame here";
	board_row = row;
	board_col = col;
	_board.resize(board_row);
	for (int i = 0; i < board_row ; i++)
		_board[i].resize(board_col);
	
	for (int i = 0; i < board_row ; i++)
		for (int j = 0; j < board_col; j++)
			_board[i][j] = ' ';
}

void tetris_vector_nmspc::TetrisVector::draw()
{
	for (int i = 0; i < board_row ; i++)
	{
		for (int j = 0; j < board_col; j++)
			cout << _board[i][j];
		cout << endl;
	}
}

void tetris_vector_nmspc::TetrisVector::readFromFile(const string file_name)
{
	vector<vector<char>> vect;

	ifstream read;

	//try
	//{
		//read.open(file_name);	
	//}
	//catch(const std::exception& e)
	//{
	//	cerr << e.what() << '\n';
	//}
	//read.exceptions(ifstream::failbit);
    //try
    //{
        read.open(file_name);
    //}
    // catch (ifstream::failure& e)
    // {
    //     cerr << "Error opening file: " << e.what() << endl;
    //     return;
    // }
	

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
	print_map(vect);
	cout << endl;
	//return (vect);
}

void abstract_tetris_nmspc::Tetromino::draw_map()
{
	int r_s = map.size();
	int c_s = map[0].size();
	
	cout << endl<<endl;
	for (int i = 0; i < r_s; i++)
	{
		for (int j = 0; j < c_s; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl<<endl;
	
}

void tetris_vector_nmspc::TetrisVector::writeToFile(const string file_name)
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

char tetris_vector_nmspc::TetrisVector::lastMove() const
{
	return (lst_move_ctr);
}


void tetris_vector_nmspc::TetrisVector::print_map(vector <vector <char>> vect)
{
	int size_row_of_map = vect.size();
	int size_col_of_map = vect[0].size();

	for (int i = 0; i < size_row_of_map ; i++)
	{
		for (int j = 0; j < size_col_of_map; j++)
			cout << vect[i][j];
		cout << endl;
	}

}

void tetris_vector_nmspc::TetrisVector::add_tetro_auto(Tetromino &other)
{
	actual_tetromino = other;

	//cout << "animate basi"<<endl;
	vector <vector <char>> printing_map;
	//	cout << "0" <<"tet sizes"<< actual_tetromino.row_size <<"tet col"<< actual_tetromino.col_size<< endl;
	//cout << "board_row" << board_row<<endl;
	printing_map.resize(board_row);
	cout <<endl<< "board_row "<< board_row <<endl;
	//	cout << "++" << endl;
	for (int i = 0; i < board_row; i++)
		printing_map[i].resize(board_col);

	//cout << "1" << endl;

	int board_y_index = 4;
	int board_x_index = board_col / 2;

	//cout << "_board.size() " << _board.size() << endl;
	int rot_dir = 0, rot_count = 0;
	cout << "Enter rotation direction (1 for clockwise, -1 for counterclockwise): ";
	if(rand() / 2)
		rot_dir = 1;
	else
		rot_dir = -1;
	cout << rot_dir <<"\n";
	//cin >> rot_dir;
	cout << "Enter rotation count: ";
	rot_count = rand()%5;
	cout << rot_count <<"\n";
	//cin >> rot_count; /*|| board[board_y_index + actual_tetromino.row_size][board_x_index + tetro_x_index] == ' '*/
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
	//cin >> move_dir;
	cout << "Enter move count: ";
	move_count = rand() % 6;
	cout << move_count<< endl;
	//cin >> move_count;
	move_ctr += move_count;
	board_x_index += move_dir * move_count;

	bool reached_bottom = false;
	while (!reached_bottom)
	{
		for (int i = 0; i < board_row ; i++)
			for (int j = 0; j < board_col; j++)
				printing_map[i][j] = _board[i][j];

    // Check for collision
    bool collision = false;
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
	//cout << "col ustu" << endl;
    if (collision)
    {
	//	cout << "coll" << endl;
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
	
		//cout << "geldi:"<< "pmsşze" << printing_map.size() <<endl;
	//	cout << "4" << endl;
		print_map(printing_map);
		//draw();
		this_thread::sleep_for(chrono::milliseconds(50));

		board_y_index++;
		//cout << "		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row)); " << endl << "board_y_index: " << board_y_index;
		//cout << "actual_tetromino.row_size:" << actual_tetromino.row_size << "board_row" << board_row <<endl;
		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row));
	//	cout << "5" << endl;
		//system("clear");
		//cout << "\033[2J\033[1;1H";
		
		if(reached_bottom)
		{
		//	cout << "reached_bottom"<<endl;
			//system("clear");
			//print_map(printing_map);
			//cout <<"before swap" <<endl;
			//draw();
			//cout << endl;
			for (int i = 0; i < board_row ; i++)
				for (int j = 0; j < board_col; j++)
					_board[i][j] = printing_map[i][j];
			
			//cout <<"after swap" <<endl;
			draw();		
		}
		if (!reached_bottom)
			move_ctr++;

	}


}

int	tetris_vector_nmspc::TetrisVector::numberOfMoves() const
{
	return (move_ctr);
}

void tetris_vector_nmspc::TetrisVector::animate(Tetromino actual_tetromino)
{
	//cout << "animate basi"<<endl;
	vector <vector <char>> printing_map;
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

	lst_move_ctr = 's';
    // Check for collision
    bool collision = false;
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
	
		//cout << "geldi:"<< "pmsşze" << printing_map.size() <<endl;
	//	cout << "4" << endl;
		print_map(printing_map);
		//draw();
		this_thread::sleep_for(chrono::milliseconds(50));

		board_y_index++;
		//cout << "		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row)); " << endl << "board_y_index: " << board_y_index;
		//cout << "actual_tetromino.row_size:" << actual_tetromino.row_size << "board_row" << board_row <<endl;
		reached_bottom = ((board_y_index + actual_tetromino.row_size >= board_row));
	//	cout << "5" << endl;
		system("clear");
		//cout << "\033[2J\033[1;1H";
		
		if(reached_bottom)
		{
		//	cout << "reached_bottom"<<endl;
			//system("clear");
			//print_map(printing_map);
			//cout <<"before swap" <<endl;
			//draw();
			//cout << endl;
			for (int i = 0; i < board_row ; i++)
				for (int j = 0; j < board_col; j++)
					_board[i][j] = printing_map[i][j];
			
			//cout <<"after swap" <<endl;
			draw();		
		}
		if (!reached_bottom)
			move_ctr++;

	}

}

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
Tetromino& tetris_vector_nmspc::TetrisVector::operator+=(Tetromino &other)
{
	actual_tetromino = other;
	animate(actual_tetromino);
	return (actual_tetromino);
}
