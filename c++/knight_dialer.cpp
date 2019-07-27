//Leetcode 935. Knight Dialer

//https://leetcode.com/problems/knight-dialer/




using namespace std;

#define MODULO (1000000000 + 7)
class Solution {
public:
    int knightDialer(int N) {

        // paths table helps us in knowing what are the possible jumps
        // from a dialer number.
        vector<vector<int>> paths {
                                    {4, 6},     // 0 i.e. we can go to 4 OR 6 from number 0.
                                    {6, 8},     // 1
                                    {7, 9},     // 2
                                    {4, 8},     // 3
                                    {0, 3, 9},  // 4
                                    {},         // 5
                                    {0, 1, 7},  // 6
                                    {2, 6},     // 7
                                    {1, 3},     // 8
                                    {2,4}       // 9
                                 };
        int count = 0;
        // Create a DP table of size 10 x (N+1)
        // Here, row represents the dialer number
        //       col represents the Hop
        vector<vector<int>> dp(10, vector<int>(N+1, 0));

        // Initialize
        // We know that for Hop=1, we just stay in the same cell
        //  so for col=1 dp values should be 1.
        for (int row=0; row<=9; row++) {
            dp[row][1] = 1;
        }

       // DP in progress
       //    For every hop, we take a starting dialer number i.e a row
       // and then we use 'paths' table above to know the possible jumps from
       // that number.
       //
       // .  For e.g. take number 4. There are three numbers {0,3 and 9} that we can
       //              reach from 4. So the formula for calculating value for 4 is in
       //              Nth iteration is.
       // .
       //    dp[4][N] = dp[0][N-1] + dp[3][N-1] + dp[9][N-1]

       for(int col=2; col<N+1; col++) {         // Hop traverse
           for(int row=0; row<10; row++) {      // Dialer number traverse

               for(auto path: paths[row]) {
                    dp[row][col] = (dp[row][col] + dp[path][col-1] % MODULO)%MODULO;
               }

           }
       }

       // Final output is nothing but the sum of all the values in the last column
       for(int i=0; i<10; i++) {
           count = (count + dp[i][N]) % MODULO;
       }

        return count;
    }

};


