//  #Leetcode 523. Continuous Subarray Sum
//  Medium
//  
//  Given a list of non-negative numbers and a target integer k, write a function to check if the array 
//  has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, 
//  sums up to n*k where n is also an integer.
//  
//   
//  
//  Example 1:
//  
//  Input: [23, 2, 4, 6, 7],  k=6
//  Output: True
//  Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
//  Example 2:
//  
//  Input: [23, 2, 6, 4, 7],  k=6
//  Output: True
//  Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
//   
//  
//  Note:
//  
//  The length of the array won't exceed 10,000.
//  You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
//  
//  
//  Solution Hint:  if (a+b)%k = (a+b+c+d+e)%k ; then c+d+e = m*K  where m is an integer.


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // Keep track of the running sum.
        int sum = 0;

        // k could be negative. Take Absolute value of k
        k = abs(k);

        // Map for maintaining the visited mods
        // key   = mod
        // value = index
        map<int, int> ref;

        // Initialize the map with key = 0 and index = -1
        // This is needed if first 2 element themselves make sum n*k
        // For e.g. [11,7,8,7,3] ; k= 6
        ref[0] = -1;


        for(int i=0; i<nums.size(); i++) {

            sum = sum + nums[i];

            // Take mod of sum for base k.
            // We need to check for k=0 (Divide by zero error)
            int mod = (k!=0)?sum%k:sum;

            // Check if this mod is already present in the map
            auto it = ref.find(mod);
            if (it == ref.end()) {
                // mod is not present. Let's add <mod, i> in the map
                ref[mod] = i;
            } else {

                // We found the mod. BUT, we need to ensure that the
                // differce of the index is more than 1.
                // Think about [3,6,7,8]; k=6 to understand it.
                if (i - it->second > 1) {
                    return true;
                }
            }
        }

        return false;

    }
};
