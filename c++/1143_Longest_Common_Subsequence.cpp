1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/
Medium
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.
Constraints:
1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Solution:
    LCS is a well-known problem, and there are similar problems here:

    1092. Shortest Common Supersequence
    1062. Longest Repeating Substring
    516. Longest Palindromic Subsequence


    Dynamic Programming.
    ====================
    Assume the lengths of strings are m and n.
    Bottom-up DP utilizes a matrix m where we track LCS sizes for each combination of i and j.

    If a[i] == b[j]
        LCS for i and j would be 1 plus LCS till the i-1 and j-1 indexes.
    Otherwise, we will take the largest LCS if we skip a charracter from one of the string (max(m[i - 1][j], m[i][j - 1]).


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int count = 0;
        // Get the length of 2 strings
        int m = text1.size();
        int n = text2.size();
        
        // Let's create a dp table where each value i, j keeps track of the
        // longest subsequence until text1[:i] and text2[:j]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (text2[j-1] == text1[i-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
