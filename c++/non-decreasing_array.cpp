Leetcode #665. Non-decreasing Array

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].

Solution: There are 2 cases: 
          Refer diagram - https://github.com/amitpatil89/programs/blob/master/non_code_misc/Leetcode_655.jpg
          case I : nums[i] < nums[i-1] && nums[i-2] <= nums[i] 
          case II: nums[i] < nums[i-1] && nums[i-2] > nums[i]
          

Class Solution {
    public:

        bool checkPossibility(vector<int>& nums) {
            //
            // Less than 3 elements, return true. 
            //
            if(nums.size() < 3) return true;

            // flag to track if we modified anything so far
            bool modified = false;

            for(int i=1; i<nums.size(); i++) {

                //
                // For the case where i=1, i-2 is invalid. So use INT_MIN there.
                //
                int b = (i-2>=0)?nums[i-2]:INT_MIN; 

                if (nums[i] < nums[i-1]) { 
                    //
                    // We need to modify something to make thing non-decreasing
                    //
                    if (!modified) {
                        // We haven't modified before, so let's check which case we are facing
                        if (nums[i] >= b) { 
                            // This is case I
                            nums[i-1] = b;
                        } else {
                            // This is case II
                            nums[i] = nums[i-1];
                        }
                        modified = true;
                    } else {
                        // We can modify just once. So return false.
                        return false;
                    }
                }
            }
            
            //
            // We didn't face any issues, return true. 
            //
            return true;     
        }
};


