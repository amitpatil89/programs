//  Leetcode 887. Super Egg Drop https://leetcode.com/problems/super-egg-drop/description/
//  
//  You are given K eggs, and you have access to a building with N floors from 1 to N. 
//  
//  Each egg is identical in function, and if an egg breaks, you cannot drop it again.
//  
//  You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.
//  
//  Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 
//  
//  Your goal is to know with certainty what the value of F is.
//  
//  What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?
//  
//  Example 1:
//  
//  Input: K = 1, N = 2
//  Output: 2
//  Explanation: 
//  Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
//  Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
//  If it didn't break, then we know with certainty F = 2.
//  Hence, we needed 2 moves in the worst case to know what F is with certainty.
//  Example 2:
//  
//  Input: K = 2, N = 6
//  Output: 3
//  Example 3:
//  
//  Input: K = 3, N = 14
//  Output: 4
//   
//  
//  Note:
//  
//  1 <= K <= 100
//  1 <= N <= 10000


#include<iostream>
#include<vector>

using namespace std;


///
/// Note this solution is O(KN^2) and sucks with bigger inputs. Explanation: https://www.youtube.com/watch?time_continue=836&v=KVfxgpI3Tv0
/// Refer this for better time complexity: https://leetcode.com/problems/super-egg-drop/discuss/158974/C++JavaPython-2D-and-1D-DP  
///

class Solution {
    public:
        int superEggDrop(int K, int N) {

            vector<vector<int>> dp(K+1, vector<int>(N+1,0));

            for (int i=0; i<K+1; i++) {
                dp[i][1] = 1;
            }
            for (int j=0; j<N+1; j++) {
                dp[1][j] = j;
            }

            //
            // f(k,n) = min(1 + max(f(k-1,n-1), f(k, n-k))
            //
            for (int k=2; k<K+1; k++) {
                for(int n=2; n<N+1; n++) {

                    // f current floor
                    int moves = INT_MAX;
                    for(int f=1; f<n; f++) {
                        moves = min(moves, max(dp[k-1][f-1], dp[k][n-f]));
                    }
                    cout << ".";
                    dp[k][n] = 1 + moves;

                }
            }

            return dp[K][N];
        }

};

int main(int argc, char *argv[]) {
    
    Solution obj;
    cout << "Anser: " << obj.superEggDrop(100,10000) << endl;

    return 0;
}
