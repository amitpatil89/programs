//  Leetcode #198. House Robber
//  
//  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//  
//  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//  
//  Example 1:
//  Input: [1,2,3,1]
//  Output: 4
//  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//               Total amount you can rob = 1 + 3 = 4.
//  
//  Example 2:
//  Input: [2,7,9,3,1]
//  Output: 12
//  Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//            Total amount you can rob = 2 + 9 + 1 = 12.
//  
//  ===========
//   Solution
//  ===========
//  Refer: https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
//  While reaching house i thief has two options, either he robs it or leave it. Let dp[i] represents the maximum value stolen so far on reaching house i. We can calculate the value of dp[i] as following –
//  
//  dp[i] = max (hval[i] + dp[i-2], dp[i-1])
//  
//  hval[i] + dp[i-2] is the case when thief decided to rob house i. In that situation 
//  maximum value will be the current value of house + maximum value stolen till last robbery 
//  at house not adjacent to house i which will be house i-2.  
//       
//  dp[i-1] is the case when thief decided not to rob house i. So he will check adjacent 
//  house for maximum value stolen till now. Thief will consider both options and decide 
//  whether to rob or not and maximum of both values will be the maximum stolen value till reaching house i.
//  
//  

class Solution {
    public:
        int rob(vector<int>& nums) {

            int n = nums.size();
            vector<int> dp(n, 0);

            // initialize
            if(n==0) return 0;
            if(n >= 1) dp[0] = nums[0];

            // Special case: n=2
            if(n >= 2) dp[1] = max(nums[0],nums[1]);

            //
            // f(n) = max(f(n-2) + nums[n], f(n-1))
            //
            for (int i=2; i<n; i++) {
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            }

            return dp[n-1];

        }
};






