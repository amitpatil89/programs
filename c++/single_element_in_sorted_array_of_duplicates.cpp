
//  Leetcode 540. Single Element in a Sorted Array
//  
//  Given a sorted array consisting of only integers where every element appears 
//  twice except for one element which appears once. Find this single element that appears only once.
//  
//  Input: [1,1,2,3,3,4,4,8,8]
//  Output: 2
//  
//  Input: [3,3,7,7,10,11,11]
//  Output: 10
//  
//  Note: Your solution should run in O(log n) time and O(1) space.
//  
//  
//  Algorithm:
//  
//  We will always get an array of size 2n+1. 
//  To find the single elements, we are doing binary search on the array(which is already sorted). 
//  Now, consider the mid element of this array, 
//      1.  if this element is not equal to its next/previous element, return this element itself
//      2.  If this middle element(M) is equal to next(N) OR previous(P) element, we can deduce the half where
//          the single element should be present. 
//          case 1: M == N and 2nd half has EVEN number of elements ==> check the 2nd half
//          case 1: M == P and 1st half has EVEN number of elements ==> check the 1st half
//          case 1: M == N and 2nd half has ODD number of elements ==> check the 1st half
//          case 1: M == P and 1st half has ODD number of elements ==> check the 2nd half
//  
//     Above 2 examples, will help understanding why exactly we need to consider the even/odd property of half array.
        

#include<iostream>
#include<vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {

    if(nums.size() == 0) return 0;
    int start = 0;
    int end = nums.size() - 1;
    int middle;
    int result;
    bool isOdd;

    while(1){

        // If there is only 1 element left, that is our result
        if(start == end){
            result = nums[start];
            break;
        }
        // Check if the half of the array is odd/even
        isOdd = (((end - start)/2)%2 == 1); 

        // Calculate middle index
        middle = (start + end) / 2;
        
        // case M == N
        if(nums[middle] == nums[middle +1]){
            if(isOdd){
                end = middle - 1; 
            }else{
                start = middle + 2;
            }
            continue;
        }

        // Case M == P
        if(nums[middle] == nums[middle - 1]){
            if(isOdd){
                start = middle + 1;
            }else{
                end = middle - 2;
            }
            continue;
        }

    }
    return result;
}


int main(){

    vector<int> vec1 { 1,1,2,3,3,4,4,8,8};
    cout << "for vec1 { 1,1,2,3,3,4,4,8,8}, single element is "<< singleNonDuplicate(vec1) << endl;
    vector<int> vec2 { 3,3,7,7,10,11,11};
    cout << "for vec2 {3,3,7,7,10,11,11}, single element is "<< singleNonDuplicate(vec2) << endl;
    
    return 0;
}
