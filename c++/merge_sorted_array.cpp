//  Leetcode #88. Merge Sorted Array
//  
//  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//  
//  Note:
//  
//  The number of elements initialized in nums1 and nums2 are m and n respectively.
//  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//  Example:
//  
//  Input:
//  nums1 = [1,2,3,0,0,0], m = 3
//  nums2 = [2,5,6],       n = 3
//  
//  Output: [1,2,2,3,5,6]
//  
//  Trick: Start the sorting from highest->lowest. Also, cover the edge case where one of the vector elements are all used.

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

            int i = m-1;
            int j = n-1;
            int index = (m+n-1);

            while(index >= 0) {
                //cout << "nums1: " << nums1[i] << " nums2: " << nums2[j] ;

                int a = (i<0)? INT_MIN:nums1[i];
                int b = (j<0)? INT_MIN:nums2[j];

                nums1[index] = max(a,b);
                (a<b)? j--:i--;
                index--;
            }

        }
};
