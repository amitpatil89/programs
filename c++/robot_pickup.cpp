#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <climits>
#include <queue>
#include <stack>

#define PASSAGE INT_MAX
#define BLOCKAGE (-1)
#define PRODUCT INT_MIN


bool _debug = true;
bool _verbose = false;
using namespace std;

vector<pair<int, int>> _path;
vector<pair<int, int>> _products;

// Debug API for printing board
void printBoard(vector<vector<int>> &mat) {

    int row = mat.size();
    int col = (row)? mat[0].size():0;
    cout << "    |";
    for(int i=0; i<col; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    cout << "----|---";
    for(int i=1; i<col; i++) {
        cout << "----";
    }
    cout << endl;
    for (int i=0; i<row; i++) {
        cout << setw(4) << i << "|";
        for (int j=0; j<col; j++) {

            if (mat[i][j] < 0) {
                if(mat[i][j] == -1)
                    // Block
                    cout << setw(4) << 'B';
                else
                    // Product
                    cout << setw(4) << 'X';
            } else {
                // Passage
                if (mat[i][j] == PASSAGE)
                    cout << setw(4) << 'P';
                else 
                    cout << setw(4) << mat[i][j];
            }

        }

        cout << endl;

    }
}


// 
// Create a refBoard from original board
//  0  --> INT_MAX
// -1 --> -1
//  Procut IDs ==> INT_MIN
void
initRefBoard(vector<vector<int>> &board,
             vector<vector<int>> &refBoard,
             pair<int, int> startP) 
{
    int nRow = board.size();
    int nCol = (nRow)? board[0].size():0;

    for(int i=0; i<nRow; i++) {
        for(int j=0; j<nCol; j++) {

            if (board[i][j] == 0) {
                refBoard[i][j] = PASSAGE;
                continue;
            } 

            if (board[i][j] > 1) {
                refBoard[i][j] = PRODUCT;
            } else {
                refBoard[i][j] = BLOCKAGE;
            }
            
        }
    }

    // Mark the start point with value 1.
    refBoard[startP.first][startP.second] = 1;

 }

// Print pixel in readable format
inline string
printPair(pair<int, int> pixel) {
    
    return "[" + to_string(pixel.first) + "][" + to_string(pixel.second) + "]";
}


//
// Run BFS from the starting point
//
pair<int, int>
bfs(vector<vector<int>> &refBoard, pair<int, int> startP, int &cost)
{
    bool productFound = false;
    int row, col;
    queue<pair<int, int>> bfsQ;
    bfsQ.push(startP);
    pair<int, int> current, neighbor;

    int nRow = refBoard.size();
    int nCol = (nRow)?refBoard[0].size():0;

    if(_verbose) cout << "Start Point is " << printPair(startP) << endl;

    while(!bfsQ.empty()) {
        // Get the number of pixels
        int n = bfsQ.size();

        while(n > 0) {
            // Update the surrounding pixels
            current = bfsQ.front(); bfsQ.pop();
            row = current.first;
            col = current.second;

            // Get the value in the current pixel.
            int pixelValue = refBoard[row][col];

            // Update the pixel on the right. If allowed and req.
            if(col+1 < nCol) {

                if (_verbose) cout << "Processing " << printPair(make_pair(row, col+1)) << endl;
                if (refBoard[row][col+1] == PRODUCT) {
                    //Found Product
                    cost = pixelValue + 1;
                    if(_verbose) cout << "Found product at " << printPair(make_pair(row, col+1)) << " Cost: " << cost << endl;
                    return pair<int, int>(row, col+1);
                }

                if (refBoard[row][col+1] != BLOCKAGE) {
                    // Update if necessary
                    if (refBoard[row][col+1] > pixelValue+1) {
                        refBoard[row][col+1] = pixelValue+1;
                        bfsQ.push(pair<int,int>(row, col+1));
                    }
                }
            }

            // Update the pixel on the left. If allowed and req.
            if(col-1 >= 0) {
                if (_verbose) cout << "Processing " << printPair(make_pair(row, col-1)) << endl;
                if (refBoard[row][col-1] == PRODUCT) {
                    //Found Product
                    cost = pixelValue + 1;
                    if(_verbose) cout << "Found product at " << printPair(make_pair(row, col+1)) << " Cost: " << cost << endl;
                    return pair<int, int>(row, col-1);
                }

                if (refBoard[row][col-1] != BLOCKAGE) {
                    // Update if necessary
                    if (refBoard[row][col-1] > pixelValue+1) {
                        refBoard[row][col-1] = pixelValue+1;
                        bfsQ.push(pair<int,int>(row, col-1));
                    }
                }
            }

            // Update the pixel on the top. If allowed and req.
            if(row-1 >= 0) {
                if (_verbose) cout << "Processing " << printPair(make_pair(row-1, col)) << endl;
                if (refBoard[row-1][col] == PRODUCT) {
                    //Found Product
                    cost = pixelValue + 1;
                    if(_verbose) cout << "Found product at " << printPair(make_pair(row-1, col)) << " Cost: " << cost << endl;
                    return pair<int, int>(row-1, col);
                }

                if (refBoard[row-1][col] != BLOCKAGE) {
                    // Update if necessary
                    if (refBoard[row-1][col] > pixelValue+1) {
                        refBoard[row-1][col] = pixelValue+1;
                        bfsQ.push(pair<int,int>(row-1, col));
                    }
                }
            }

            // Update the pixel on the botoom. If allowed and req.
            if(row+1 < nRow) {
                if (_verbose) cout << "Processing " << printPair(make_pair(row+1, col)) << endl;
                if (refBoard[row+1][col] == PRODUCT) {
                    //Found Product
                    cost = pixelValue + 1;
                    if(_verbose) cout << "Found product at " << printPair(make_pair(row+1, col)) << " Cost: " << cost << endl;
                    return pair<int, int>(row+1, col);
                }

                if (refBoard[row+1][col] != BLOCKAGE) {
                    // Update if necessary
                    if (refBoard[row+1][col] > pixelValue+1) {
                        refBoard[row+1][col] = pixelValue+1;
                        bfsQ.push(pair<int,int>(row+1, col));
                    }
                }
            }
        }

        n--;
        
    }
    return startP;
}

//
// Debug API for printing stack data
//
void printStack(stack<pair<int, int>> stackPair) 
{
    pair<int, int> current;

    cout << "The Path is: " << endl;
    while(!stackPair.empty()) {
        
        current = stackPair.top(); stackPair.pop();
        cout << printPair(current) << endl;

    }
}

//
// Update final path with the current segment we just found.
//
void
updatePath(stack<pair<int, int>> stackPair)
{
    
    while(!stackPair.empty()) {
        _path.push_back(stackPair.top());

        stackPair.pop();
    }
}


//
// Trace path from the endP to startP
//
void 
tracePath(vector<vector<int>> &refBoard, pair<int, int> endP, int cost) {
    
    int row = endP.first;
    int col = endP.second;
    int nRow = refBoard.size();
    int nCol = (nRow)?refBoard[0].size():0;

    stack<pair<int, int>> stackPair;

    int target = cost-1;
    while(target > 0) {
        if (_verbose) cout << "At pixel" << printPair(make_pair(row, col)) << " current target = " << target << endl;
        if(target > 0 && col+1 < nCol && refBoard[row][col+1] == target) {
            col = col+1;
            target--;
            stackPair.push(make_pair(row, col));
            continue;
        }
        if(target > 0 && col-1 >=0 && refBoard[row][col-1] == target) {
            col = col-1;
            target--;
            stackPair.push(make_pair(row, col));
            continue;
        }
        if(target > 0 && row+1 < nRow && refBoard[row+1][col] == target) {
            row = row+1;
            target--;
            stackPair.push(make_pair(row, col));
            continue;
        }
        if(target > 0 && row-1 >=0 && refBoard[row-1][col] == target) {
            row = row-1;
            target--;
            stackPair.push(make_pair(row, col));
            continue;
        }
    }
    
    updatePath(stackPair);
    //printStack(stackPair);
}

//
// get the number of products on this board.
// Also, populate the startP.
// We are assuming that Product IDs are always connected
//
int getNumOfProducts(vector<vector<int>> &board, pair<int, int> &startP) 
{
    int nRow = board.size();
    int nCol = (nRow)? board[0].size():0;
    int nProducts = 0;
    bool foundStartP = false;

    for(int i=0; i<nRow; i++) {
        for(int j=0; j<nCol; j++) {
            if(board[i][j] > 1){
                if(!foundStartP) {
                    startP.first = i;
                    startP.second = j;
                    foundStartP = true;
                }
                nProducts++;
            }
        }
    }

    return nProducts;
}

//
// Print final output
//
void printPath() {
    
    cout << endl << endl << "------- OUTPUT PATH --------" << endl;
    for(auto pixel: _path) {
        cout << printPair(pixel) << endl;
    }
}
 

int main(){
    
    vector<vector<int>> board = {
                                { 0,  0,  0,  0, -1, 11, -1},
                                { 0,  5,  6,  8, -1,  0, -1},
                                {-1,  0,  0, -1, -1,  0, -1},
                                {-1,  0,  0,  0, -1,  0,  0},
                                {-1, -1,  0,  0, -1,  0,  0},
                                { 6, -1,  7,  0,  0,  0,  0},
                                { 0, -1,  0,  0,  0,  0,  0},
                                { 0, -1,  0,  0,  0, 12,  0},
                                { 0,  0,  0,  0,  0,  0,  0}

                              };
    if (_debug) cout << "INPUT: " << endl << endl;
    if (_debug) printBoard(board);

    // Algorithm
    // 1. Decide on the starting point - 'startP'
    // 2. Create refBoard
    // 3. Start BFS from startP
    // 4. Stop when we find any of the Product IDs - 'endP'
    // 5. Save the Path
    // 6. Make 'End' your new starting point. 
    //    And repeate from step 1 untill there is no product ID  left.
           

    pair<int, int> startP(0,0);
    pair<int, int> endP;

    int nRow = board.size();
    int nCol = (nRow)? board[0].size():0;

    // Get number of products and startP
    int nProducts = getNumOfProducts(board, startP);

    // Create a refBoard

    _products.push_back(startP);
    
    while(nProducts != _products.size()) { 
        vector<vector<int>> refBoard(nRow, vector<int>(nCol, 0));
        // Init redBoard
        initRefBoard(board, refBoard, startP);
        if(_verbose) printBoard(refBoard);

        // Start BFS from the startP. 
        int cost = 0;
        endP = bfs(refBoard, startP, cost);

        if(_verbose) cout << "Product found at " << printPair(endP) << " Cost: " << cost<< endl;

        if(_verbose) printBoard(refBoard);

        // Track the path from endP to startP
        tracePath(refBoard, endP, cost);

        // Update startP so that it wil be removed from the future runs
        board[startP.first][startP.second] = 0;

        // endP will be our new startP
        startP = endP;
        _products.push_back(endP);

        
    }

    _path.push_back(endP);
    printPath();

    return 0;
}
