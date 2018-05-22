//  Leetcode: 42.Trapping Rain Water (https://leetcode.com/problems/trapping-rain-water/description/)
//  
//  Question: Given n non-negative integers representing an elevation map where 
//            the width of each bar is 1, compute how much water it is able to 
//            trap after raining.
//  
//  Example: Input: [0,1,0,2,1,0,1,3,2,1,2,1]
//           Output: 6
//  
//  Solution: There are 2 ways to solve this problem. Both the algorithms can be understood by going
//            through them below.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    public:
        //
        // Algorithm 1
        //
        int trap1(vector<int>& height) {
            //
            // Get the size of the vector
            //
            int n = height.size();

            //
            // Let's keep 2 vectors which will carry information we need
            // leftMax  : value at index i is the max value betn height[0] and height[i-1]
            // rightMax : value at index i is the max value betn height[i+1] and height[n-1]
            //
            vector<int> leftMax(n,0);
            vector<int> rightMax(n,0);
            int lMax = 0;
            int rMax = 0;
            int water = 0;
            
            //
            // populate the leftMax vector
            //
            for(int i=0; i< n-1; ++i) {
                lMax = max(lMax, height[i]);
                leftMax[i+1] = lMax;
            }

            //
            // populate the rightMax vector
            //
            for(int i=n-1; i>0; --i) {
                rMax = max(rMax, height[i]);
                rightMax[i-1] = rMax;
            }
            
            //
            // For each element in the array, we find the maximum level of water it can trap after 
            // the rain, which is equal to the minimum of maximum height of bars on both the sides 
            // minus its own height. We add it to the variable water ONLY IF the subtraction is +ve
            //
            for(int i=0; i< n; i++) {
                int current = min(leftMax[i], rightMax[i]) - height[i];
                water += ( current<0)? 0: current;
            }

            return water;
        }


        //
        // Algorithm 2 (Refer Approach #4: https://leetcode.com/problems/trapping-rain-water/solution/)
        //
        int trap2(vector<int>& height) {

            int left = 0;
            int right = height.size() - 1;
            //
            // Return if we do not have more than 1 elements
            //
            if (right < 2)
                return 0;

            int water = 0;

            //
            // left and right are   the 2 pointers we use to go through the elements.
            // Initialize the maxL and maxR 
            // maxL: keeps track of the max value on the left of pointer left
            // maxR: keeps track of the max value on the right of pointer right
            //
            int maxL = height[left];
            left++;
            int maxR = height[right];
            right--;
            int current = 0;

            //
            // Since left and right move towards each other, we use the while
            // until left < right
            //
            while (left <= right) {
                //
                // For each element in the array, we find the maximum level of water it can trap after 
                // the rain, which is equal to the minimum of maximum height of bars on both the sides 
                // minus its own height. We add it to the variable water ONLY IF the subtraction is +ve
                //
                // if (maxL < maxR)
                //      calculate the 'current' with pointer left as index
                //      if 'current' is +ve, add it to the 'water'
                //      move left by 1
                // if (maxR > maxL)
                //      calculate the 'current' with pointer right as index
                //      if 'current' is +ve, add it to the 'water'
                //      move right by 1
                //
                if(maxL < maxR) {
                    current = maxL - height[left];
                    water += (current > 0)? current : 0;
                    if(maxL < height[left])
                        maxL = height[left];
                    left++;

                } else {
                    current = maxR - height[right];
                    water += (current > 0)? current : 0;
                    if(maxR < height[right])
                        maxR = height[right];
                    right--;
                }
            }
            return water;
        }
};



int main(){
    
    return 0;
}
