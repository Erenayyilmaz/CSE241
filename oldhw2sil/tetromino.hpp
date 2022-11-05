#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

#ifndef _TETROMINO_HPP_
#define _TETROMINO_HPP_

enum struct tetrominoShape: char {
    I = 'I',
    O = 'O',
    T = 'T',
    J = 'J',
    L = 'L',
    S = 'S',
    Z = 'Z',
    B = ' ' // for to represent empty space in tetromino Shape
};

enum struct direction: char {
    R = 'R',
    L = 'L'
};

// global operator overloadings for strong enum tetrominoShape are below:
istream & operator >> (istream & cInput, tetrominoShape & assignable);
istream & operator >> (istream & cInput, direction & assignable);
ostream & operator << (ostream & cOutput, tetrominoShape & printable);
ostream & operator << (ostream & cOutput, tetrominoShape printable);
// for different orders and const cases
bool operator == (tetrominoShape & t, char c);
bool operator == (const tetrominoShape & t, char c);
bool operator == (char c, tetrominoShape & t);
bool operator == (char c, const tetrominoShape & t);
bool operator == (char c, const direction & d);
bool operator == (const direction & d, char c);

class Tetromino
{
public:
    // constructors
    Tetromino(const tetrominoShape & );  // 2D base constructor
    Tetromino(); // no-parameter overloading of constructor
    
    void setType(const tetrominoShape & );  // sets the type of an object and constructs it accordingly
    Tetromino rotate(const direction & ); // rotates Tetromino object left or right and returns it
    void print() const; // prints caller Tetromino object
    Tetromino bestCanFit(Tetromino & ); // it checks whether caller tetromino object can Fit or not with given parameter object at given side and any possible rotation without any useless holes ?

private:
    vector<vector<int>> shapeVector; // 2-Dimensional tetromino Shape Vector
    tetrominoShape type; // one of these tetromino shapes: I, O, T, J, L, S, Z
    
    int width; // width of the tetromino object
    int height; // height of the tetromino object

    static bool shouldMoveInX; // canFit function should increase or decrease XmoveQnty2 parameter depending on a direction
    
    Tetromino connect(const Tetromino & , const direction, const int ) const; // connects caller and argument tetromino objects as one connected tetromino object and returns it
};

#endif /* _TETROMINO_HPP_ */
