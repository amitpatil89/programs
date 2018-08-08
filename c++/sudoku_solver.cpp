// https://leetcode.com/problems/sudoku-solver/description/
// 
// Leetcode Problem 37: Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// 
// A sudoku solution must satisfy all of the following rules:
// 
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.
// 
// Great Explanation: https://www.geeksforgeeks.org/backtracking-set-7-suduku/
//


class Solution {
    public:

#define SIZE 9

        //
        // Find the first free row and col. i.e. pixel which contains '.'
        // populate row and col values and return true/false
        //
        bool findFreePixel(vector<vector<char>>& board, int &row, int &col) {
            for(int i=0; i < SIZE; i++) {
                for (int j=0; j<SIZE; j++) {
                    if(board[i][j] == '.'){
                        row = i;
                        col = j;
                        return true;
                    }
                }
            }
            // Didn't find anything
            return false;
        }

        //
        // check if c appears in the existing row, col or box
        // return true only if it doesn't exists in any of them
        //
        bool ifSafe(vector<vector<char>>& board, int row, int col, char c) {

            int box = (row/3)*3 + (col/3);

            return (!presentInRow(board, row, c) &&
                    !presentInColumn(board, col, c) &&
                    !presentInBox(board, box, c));
        }

        //
        // If the char c is already present in the row return true
        //
        bool presentInRow (vector<vector<char>>& board, int row, char c) {

            for(int j=0; j<SIZE; j++) {
                if (board[row][j] == c) {
                    // found!
                    return true;
                }
            }
            // character doesn't exist in this row
            return false;
        }

        //
        // If the char c is already present in the col return true
        //
        bool presentInColumn (vector<vector<char>>& board, int col, char c) {
            for(int i=0; i<SIZE; i++) {
                if (board[i][col] == c) {
                    // found!
                    return true;
                }
            }
            // character doesn't exist in this col
            return false;        
        }
        
        //
        // If the char c is already present in the box return true
        //
        bool presentInBox (vector<vector<char>>& board, int box, char c) {

            int rowStart = (box/3)*3;
            int colStart = (box%3)*3;

            for(int i=rowStart; i<rowStart+3; i++) {
                for(int j=colStart; j<colStart + 3; j++) {
                    if (board[i][j] == c) {
                        // found!
                        return true;
                    }
                }
            }
            // character doesn't exist in this box
            return false;        
        }
        
        //
        // Main function which solves the sudoku
        // Just call the helper. Helper alone is sufficient 
        //

        void solveSudoku(vector<vector<char>>& board) {

            solvingSudoku(board);

            return;
        }

        //
        // Function that does the real magic. 
        // This method is called backtracking.
        //
        bool solvingSudoku(vector<vector<char>>& board) {

            int row, col;
            //
            // Check if this sudoku is unsolved so far
            // If there is no free pixel to solve, we know that
            //    sudoku is completely solved.
            // Else, we get the row, col from next free pixel 
            //    we need to solve.
            //
            if (!findFreePixel(board, row, col)) {
                return true;
            }

            //
            // Now that we have the empty pixel (row, col)
            // Let's start the backtracking with trial ans error
            //
            for(char c='1'; c < '1'+ SIZE ; c++) {
                
                //
                // Check if c is safe for this pixel, means it is
                // not present in the row,col or box.
                //
                if (ifSafe(board, row, col, c)) {
                    //
                    // c is safe so far. Let's put values recursively
                    // in the remaining cells and see if we solve sudoku entirely.
                    //
                    board[row][col] = c;
                    if (solvingSudoku(board)) {
                        //
                        // solved! return true
                        //
                        return true;
                    } else{
                        //
                        // oops! c is not the correct value as the solvingSudoku couldn't
                        // solve using that value. Reset the value from c to '.' and move
                        // to the next numeber in the for loop.
                        //
                        board[row][col] = '.';
                    }
                }
            }

            //
            // None of these characters fit this pixel
            // return false and trigger backtracking.
            //
            return false;
        }
};
