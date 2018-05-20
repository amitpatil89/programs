//  Leetcode 11 : Container With Most Water
//  
//  https://leetcode.com/problems/container-with-most-water/description/
//  
//  Question: Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
//            n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//            Find two lines, which together with x-axis forms a container, such that the container contains 
//            the most water.
//  
//            Note: You may not slant the container and n is at least 2.
//  
//  Solution: The intuition behind this approach is that the area formed between the lines will always be limited 
//            by the height of the shorter line. Further, the farther the lines, the more will be the area obtained.
//  
//            We take two pointers (left and right), one at the beginning and one at the end of the array constituting 
//            the length of the lines. Futher, we maintain a variable maxA to store the maximum area obtained till now. 
//            At every step, we find out the area formed between them, update maxA and move the pointer 
//            pointing to the shorter line towards the other end by one step.
//  
//  Note: Check the solution section (https://leetcode.com/problems/container-with-most-water/solution/) 
//        to see/understand algorithm in a video


#include <iostream>
#include <vector>

using namespace std;

class Area {
    public:
        int maxArea(vector<int>& heights) {

            int maxA = 0;    // maximum area
            int left = 0;    // left index
            int right = heights.size()-1; // right index

            while(left != right) {

                int leftLen = heights[left];
                int rightLen = heights[right];

                maxA = max(maxA,(min(leftLen, rightLen) * (right-left)));

                if(leftLen <= rightLen) {
                    left++;
                }else{
                    right--;
                }
            }

            return maxA;

        }
};

int main (int argc, char* argv[]) {
    vector<int> heights{1,2,3,4,523,4,5,67,78};

    Area water;

    cout << "water contained in this is : " << water.maxArea(heights) << endl;
    return 0;
}


