//    Leetcode 723. Candy Crush
//
//    https://leetcode.com/problems/candy-crush/description/
//



#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:

        // Clears the refBoard i.e. marks all the positions as 1. 
        // For this table:-
        // 1 => keep this position
        // 0 => delete this position
        vector<vector<int>> clearReferenceTable(vector<vector<int>>& refBoard){
            for (auto &row: refBoard){
                for(auto &col: row){
                    col = 1;
                }
            }
            return refBoard;
        }

        // print the board/refBoard for debug
        void print(vector<vector<int>>& refBoard){
            for (auto row: refBoard){
                for(auto col: row){
                    cout << setw(4) << col << " ";
                }
                cout << endl;
            }
        }

        // parse the board and see if there is anything we need to update
        // update the refBoard with 0 and 1 as per the following
        // 1 => keep this position
        // 0 => delete this position
        // returns true if there is any update required.
        // returns false if no update is required

        bool parseBoard(vector<vector<int>>& board, vector<vector<int>>& refBoard){
            int nRow = board.size();
            int nCol = (nRow)? board[0].size() : 0;
            bool ret = false;
            // we will go from upper left corner, we will check if the 
            // [row][col] = [row+1][col]  AND [row][col] = [row+2][col]
            // OR
            // [row][col] = [row][col+1]  AND [row][col] = [row][col+2]
            // if yes --> mark corresponding refBoard 0 also ret = true
            // if no ---> move ahead

            for(auto i = 0; i < nRow; ++i){
                for(auto j = 0; j < nCol; ++j){

                    if((j < nCol -2) && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] != 0){
                        refBoard[i][j] = 0;
                        refBoard[i][j+1] = 0;
                        refBoard[i][j+2] = 0;
                        ret = true;
                    }
                    if((i < nRow -2) && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] != 0){
                        refBoard[i][j] = 0;
                        refBoard[i+1][j] = 0;
                        refBoard[i+2][j] = 0;
                        ret = true;
                    }
                }
            }

            return ret;
        }

        // update the board with the help of refBoard  
        void updateBoard(vector<vector<int>>& board, vector<vector<int>>& refBoard){
            int nRow = board.size();
            int nCol = (nRow)? board[0].size() : 0;

            int start = 0;
            for(auto j = 0; j < nCol; ++j){
                vector<int> temp(nRow, 0);
                start = nRow - 1;
                for(auto i = nRow - 1 ; i >= 0 ; --i){
                    if(refBoard[i][j] == 1){
                        temp[start--] = board[i][j];
                    }
                }
                for(auto k = 0; k < nRow ; ++k){
                    board[k][j] = temp[k];   
                }    

            }
        }

        vector<vector<int>> candyCrush(vector<vector<int>>& board) {

            int nRow = board.size();
            int nCol = (nRow)? board[0].size() : 0;

            auto refBoard(board);

            // clear the refBoard
            clearReferenceTable(refBoard);

            // continuesly parse and update the board with the help of refBoard
            while(parseBoard(board, refBoard)){ 

                updateBoard(board, refBoard);
                // clear refBoard before next parse
                clearReferenceTable(refBoard);       
            }

            return board;

        }
};
