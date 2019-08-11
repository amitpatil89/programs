//  1138. Alphabet Board Path
//  https://leetcode.com/problems/alphabet-board-path/
//  
//  On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
//  
//  Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z...."]
//  
//  We may make the following moves:
//  
//  'U' moves our position up one row, if the position exists on the board;
//  'D' moves our position down one row, if the position exists on the board;
//  'L' moves our position left one column, if the position exists on the board;
//  'R' moves our position right one column, if the position exists on the board;
//  '!' adds the character board[r][c] at our current position (r, c) to the answer.
//  NOTE: (Here, the only positions that exist on the board are positions with letters on them.)
//  
//  Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  
//  You may return any path that does so.
//  
//  Example 1:
//  
//  Input: target = "leet"
//  Output: "DDR!UURRR!!DDD!"
//  Example 2:
//  
//  Input: target = "code"
//  Output: "RR!DDRR!UUL!R!"
//   
//  
//  Constraints:
//  1 <= target.length <= 100
//  target consists only of English lowercase letters.




// Class Point
// row and col
class Point {
public:
    int row;
    int col;
    
    Point(int _row, int _col) {
        row = _row;
        col = _col;
    }
    
    // For printing point information.
    string point() {
        return "[" + to_string(row) + "]["+ to_string(col) + "]";
    }
};

class Solution {
public:
    string alphabetBoardPath(string target) {
        string result;
        
        // We start at [0][0]
        Point start(0,0), end(0,0);

        // Go through the characters of target and keep updating result.
        for (auto c: target) {
            // Get the position of character c.
            end = getPosition(c);

            // update the result by adding the string for start --> end point.
            // Also, put a '!' at the end.
            result = result + getString(start, end) + "!";
            start = end;
        }
        
        return result;
    }
    
    // Return the co-ordinates for character c.
    Point getPosition(char c) {
        int digit = c - 'a';
        int row = digit/5;
        int col = digit%5;
        return (Point(row, col));
    }
    
    // Create the string for reaching end from start.
    string getString(Point start, Point end) {
        string moves;
        
        if (start.row < end.row ) {
            // First calculate left <---> right. Then UP <---> DOWN
            moves = moves + createStringLR(start.col - end.col);
            moves = moves + createStringUD(start.row - end.row);
        } else {
            // First calculate UP <---> DOWN, then left <----> right
            moves = moves + createStringUD(start.row - end.row);
            moves = moves + createStringLR(start.col - end.col);
        }
        
        return moves;
    }
    
    // create LR string from the value passed.
    // For e.g. val = 3, return RRR
    //          val = -3 return LLL
    inline
    string createStringLR(int val) {
        string result;
              
        auto c = (val < 0)?'R':'L';
        val = (val>0)?val: (val*-1);
        
        return string(val, c);
    }
    
    // create UP string from the value passed.
    // For e.g. val = 3, return UUU
    //          val = -3 return DDD
    inline
    string createStringUD(int val) {
        string result;
              
        auto c = (val > 0)?'U':'D';
        val = (val>0)?val: (val*-1);
        
        return string(val, c);
    }
};























