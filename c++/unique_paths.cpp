//  
//  
//  Leetcode #62 Unique Paths (https://leetcode.com/problems/unique-paths/description/)
//  
//  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//  
//  The robot can only move either down or right at any point in time. The robot is trying to reach 
//  the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//  
//  How many possible unique paths are there?
//  
//  
//  Example 1:
//  
//  Input: m = 3, n = 2
//  Output: 3
//  Explanation:
//  From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
//  1. Right -> Right -> Down
//  2. Right -> Down -> Right
//  3. Down -> Right -> Right
//  
//  Example 2:
//  
//  Input: m = 7, n = 3
//  Output: 28
//  

class Solution {
    public:
        int uniquePaths(int m, int n) {

            vector<vector<int>> dp(m, vector<int>(n,0));
            //
            // There are 2 directions allowed, down or right. 
            // Hence, any cell can be entered from above or left.
            // f(a,b) = f(a,b-1) + f(a-1,b)
            //
            // It also gives us the indication for first row and col
            // should be initialized to 1.


            // Initialize the row0 and col0 to 1
            for(int i=0; i<m; i++)
                dp[i][0] = 1;

            for(int j=0; j<n; j++)
                dp[0][j] = 1; 

            
            //
            // Start updating cells
            //
            for(int i=1;  i<m; i++) {
                for(int j=1; j<n; j++) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
            
            //
            // Return the value in the destination cell
            //
            return dp[m-1][n-1];
        }
};
