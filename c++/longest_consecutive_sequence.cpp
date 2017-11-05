//  Leetcode 128. Longest Consecutive Sequence
//  
//  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//  
//  For example,
//      Given [100, 4, 200, 1, 3, 2],
//      The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//  
//      Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {

            // unordered because it is efficient than regular(ordered) set.
            // set is required to remove any duplicate elements in nums
            unordered_set<int> numSet (nums.begin(), nums.end());
            
            // initialize variables
            int maxCount = 0;
            int count = 0;
            int currElement;
            
            // Take 1 element from the nums at a time. 
            for(auto element: nums){

                count = 0;
                currElement = element;

                // if the element is not in numSet, it means it has already been 
                // removed from the set. In other words, we have considered that 
                // number in a sequence before. So move ahead

                if(numSet.find(currElement) == numSet.end()){
                    continue;
                }else{
                    // Let's see if we have any elements on either side of element
                    // first we will see if we have elements in currElement-- direction
                    // and then currElement++ 
                    // Also, if such element is present, remove it from the set to
                    // avoid recomputation. 

                    // Let's go in the descending direction from this element
                    while(numSet.find(currElement) != numSet.end()){
                        numSet.erase(numSet.find(currElement));
                        ++count;
                        --currElement;
                    }

                    // Let's go in the ascending direction from this element
                    currElement = element + 1;
                    while(numSet.find(currElement) != numSet.end()){
                        numSet.erase(numSet.find(currElement));
                        ++count;
                        ++currElement;
                    }
                }    

                maxCount = max(maxCount, count);
            }    
            return maxCount;

        }
};


int main(){
    
    vector<int> vec{100, 0, 3, 56, 57, 54, 51, 52, 53, 55};
    Solution obj;

    cout << "largest seq legth = " << obj.longestConsecutive(vec) << endl;
    return 0;
}
