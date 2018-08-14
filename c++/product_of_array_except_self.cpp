
//  Leetcode #238. Product of Array Except Self
//  
//  Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//  NOTE: Please solve it WITHOUT DIVISION and in O(n) AND constant space complexity.
//  Follow up:
//  Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
//  
//  Example:
//  
//  Input:  [1,2,3,4]
//  Output: [24,12,8,6]
//  
//  Algorithm 1: First let's ignore the space complexity, in this case, we can keep 2 vectors forward and backward which keep the 
//               total multiplication value of all the elements until index 'i' i.e.(0...i-1) and (i+1...n-1).
//               Now, result[i] = forward[i-1] * backwards[i+1]
//  
//  Algorithm 2: Now, to save the space complexity, we use result vector to store the backward vector information. AND we use a
//               simple variable (total) to keep track of the multiplication which forward array was providing for any index i.

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {

            int n = nums.size();
            vector<int> result(n,1);
            int total=1;

            for(int i=n-1; i>=0; i--){
                total = total*nums[i];
                result[i] = total;
            }
            total = 1;
            for(int i=0; i<n; i++) {
                result[i] = total * ((i+1 != n)?result[i+1]:1);
                total = total*nums[i];
            }
            return result;
        }
};
