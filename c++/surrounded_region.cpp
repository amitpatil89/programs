//  Leetcode 130. Surrounded Regions
//  
//  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//  A region is captured by flipping all 'O's into 'X's in that surrounded region.
//  
//  For example,
//      input:  X X X X
//              X O O X
//              X X O X
//              X O X X
//  
//      output: X X X X
//              X X X X
//              X X X X
//              X O X X
//  
//  Algorithm:
//     Observe that any region of 'O' which is not surrounded by 'X' will definitely be connected to some 'O'
//     on the boarder rows/columns of the board. Check the following algorithm which uses this observation -
//     1. We will not change 'X' anywhere. But, if 'O' is on the border, we will mark it as 'N'. 
//     2. We start with upper-left corner of the board, when board[i][j] is 'O', we check the previous and above
//        square value. If any of them has 'N' in it, we change 'O' --> 'N' 
//     3. Just like step 2, we also, start with lower-right corner and when board[i][j] is 'O', we check its next 
//        and lower square. If any of them is 'N', we change 'O' --> 'N'
//     4. Step 2 and 3 are repeated as long as we have a change like 'O' --> 'N'. This is tracked through the flag
//        named change. and do{ // step 2, 3 }while(change);
//     5. Now, parse through all the elements, and update 'O' --> 'X' and 'N' --> 'O'.


class Solution {
  public:
      void solve(vector<vector<char>>& board) {

          int nRow = board.size();
          int nCol = (nRow) ? board[0].size() : 0;
          bool change;

          do{
              change = false;
              for(int i = 0; i < nRow; ++i){
                  for(int j = 0; j < nCol; ++j){
                      // This is Step 1. To optimise, we can take this out of do-while loop.
                      if(i==0 || j==0 || i==(nRow-1) || j==(nCol-1)){
                          if(board[i][j] == 'O'){
                              board[i][j] = 'N';
                              change = true;
                          }
                      }else{
                          // This is step 2. 
                          if(board[i][j] == 'O' && (board[i-1][j] == 'N' || board[i][j-1] == 'N')){
                              board[i][j] = 'N';
                              change = true;
                          }
                      }
                  }
              }

              for(int i = nRow - 1; i > 0; --i){
                  for(int j = nCol-1; j > 0; --j){
                      if(i==0 || j==0 || i==(nRow-1) || j==(nCol-1)){
                          continue;
                      }else{
                          // This is step 3. 
                          if(board[i][j] == 'O' && (board[i+1][j] == 'N' || board[i][j+1] == 'N')){
                              board[i][j] = 'N';
                              change = true;
                          }
                      }
                  }
              }
          }while(change); // loop thorogh only if there is a change.

          for(auto &row: board){
              for(auto &col: row){
                  // It is important to do 0 --> X before N --> 0 because otherwise, all N's will become X.
                  if(col == 'O') col = 'X';
                  if(col == 'N') col = 'O';
              }
          }
      }

      // For debug purposes
      void print(vector<vector<char>>& board){
          for(auto row: board){
              for(auto col: row){
                  cout << col << " ";
              }
              cout << endl << endl;
          }
      }
};



