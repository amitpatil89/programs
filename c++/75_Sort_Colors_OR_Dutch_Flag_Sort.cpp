//  75. Sort Colors
//  https://leetcode.com/problems/sort-colors/
//  
//  Given an array with n objects colored red, white or blue, sort them in-place so that objects 
//  of the same color are adjacent, with the colors in the order red, white and blue.
//  
//  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//  
//  Note: You are not suppose to use the library's sort function for this problem.
//  
//  Example:
//  
//  Input: [2,0,2,1,1,0]
//  Output: [0,0,1,1,2,2]
//  Follow up:
//  
//  A rather straight forward solution is a two-pass algorithm using counting sort.
//  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//  Could you come up with a one-pass algorithm using only constant space?
//  
//  
//  Solution Algorithm:
//  
//  Go through the array and keep 2 pointers, p0 and p2.
//  p0 ==> points to the first index from the left where there is a non-zero value. I.e. 1 or 2.
//  p2 ==> points to the first index from the end of the array where there is a non-two value. i.e. 0 or 1.
//  
//  Now, third pointer i, will go from p0 to p2 and
//      if it encounters 2, it pushes it to p2.
//      if it encounters 0 it pushes it to p0, 
//      if it encounters 1, it doesn't do anything
//  
//      NOTE: sequence of checking presence of 2 before 0 is IMPORTANT.


class Solution {
public:
    void sortColors(vector<int>& flag) {
            int size = flag.size();
    int p0 = 0;
    int p2 = size-1;
    
    // Init p0
    for (int i=0; i<size; i++) {
        if (flag[i] != 0) {
            p0 = i;
            break;
        }
    }
    
    // Init p2
    for (int i=size-1; i>=0; i--) {
        if (flag[i] != 2) {
            p2 = i;
            break;
        }
    }
    
    // Pointer i will go from p0 and p2. 
    for(int i=p0; i<=p2; i++) {
        // If we encounter 2, swap that 2 with the value pointed by p2.
        if (flag[i] == 2) {
            swap(flag[i], flag[p2]);
            p2--;
            if(flag[i] == 2) {
                // Value pointed by p2 was also 2. 
                // So we just update p2 and do this again ->continue
                i--;
                continue;
            }
        }
        
        // If we encounter 0, swap that 0 with the value pointed by p0
        // Understand that, p0 is always equal of behind i, hence we
        // don't need to check for 2 again.
        if (flag[i] == 0) {
            swap(flag[i], flag[p0]);
            p0++;
        }

    }
    }
};
