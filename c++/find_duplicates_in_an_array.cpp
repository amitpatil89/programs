//  Leetcode 442. Find All Duplicates in an Array
//  
//  Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//  
//  Find all the elements that appear twice in this array.
//  
//  Could you do it without extra space and in O(n) runtime?
//  
//  Example:
//      Input:
//      [4,3,2,7,8,2,3,1]
//  
//      Output:
//      [2,3]
//  
//  Algorithm 1: 
//  1.  Since all the elements in the array are betwen [1,n] we have all the positive numbers.
//  2.  Parse the element a[i] in the array, to keep track of this element we will make the element
//      at index value abs(a[i])-1 negative (-1 bcoz indexes start from 0). 
//  3.  In this process, if we come across an index abs(a[i])-1 which is already negative, that abs(a[i])
//      is the repeated one. 
//  
//  Algorithms 2: (Coded below)
//  1.  Since all the elements in the array are betwen [1,n], we can map these elements with indexes of array.
//  2.  Starting with the first element a[i] we swap the element with the value at a[a[i]-1], keep doing this until 
//      a[i] == i+1 OR a[i] == a[a[i]-1] do this for all the elements in that array
//  
//      if (a[i] == i+1) ==> move to next element 
//      if (a[i] == a[a[i]-1]) ==> add a[i] in the list of duplicates 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    vector<int> res;

    for(int i = 0; i < nums.size(); i++){
        while(nums[i] != i+1){
            if(nums[i] == nums[nums[i]-1]){
                if(find(res.begin(), res.end(), nums[i]) == res.end()){
                    res.push_back(nums[i]);
                }
                break;
            }
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    return res;
}



int main(){

    return 0;
}
