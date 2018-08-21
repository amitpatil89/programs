Leetcode #891. Sum of Subsequence Widths

Given an array of integers A, consider all non-empty subsequences of A.
For any sequence S, let the width of S be the difference between the maximum and minimum element of S.
Return the sum of the widths of all subsequences of A. 
As the answer may be very large, return the answer modulo 10^9 + 7.

Example 1:

Input: [2,1,3]
Output: 6

Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
 
Note:
1 <= A.length <= 20000
1 <= A[i] <= 20000

Solution/Trick: 

1. First sort the array (nlogn)
2. In a subsequence, only minimum and maximum element matter.
3. Now, take any element A[i]. All the elements from A[0] ...A[i-1] are smaller than A[i] 
   and elements from A[i+1] to A[n-1] are bigger than A[i].
4. From above, we can safely say that A[i] will be maximum in the subsequences containing A[i] 
   and different combinations sets elements from index 0 .. i-1. (including null set where A[i] itself is the subsequence).
5. With this knowledge, we know that A[i] will be maximum in 2^(i) subsequences. Hence we need to add this as below:
   res = res + A[i]*2^(i) for i = 0 to n-1
6. Similarly we can see that A[i] will be the minimum in subsequence containing A[i] and elements from index i+1 to n-1.
7. There are 2^(n-1-i) such subsequences. Hence we need to subtract this value as below:
   res = res - A[i]*2^(n-1-i) for i = 0 to n-1
8. Final res can be written as below:

   res = 0
   for(i=0; i<n; i++)
       res = res + A[i]*2^(i) - A[i]*2^(n-1-i)

9. NOTE: above sum grows exponentially with n and int/long won't be able to hold the 2^(x) part. This is why the Q asks us to
   return the mod (1e9+7) of the ans. And hence, we can't reach to big numbers such as 2^100 directly without using mod. 
   Check the implementation.


class Solution {
   public:
       int sumSubseqWidths(vector<int> A) {
           //
           // Sort the array
           //
           sort(A.begin(), A.end());

           //Initialize the variables
           long c=1, res = 0, mod = 1e9 + 7;
           int n = A.size();

           for (int i = 0; i < n; ++i){
               //
               // We use different form of summation than (8) because we want to 
               // use 2^(i) for min and max when we have it. Hence, we use 
               // A[i] * 2^i - A[n-1-i]* 2^i
               //        
               res = (res + A[i] * c - A[n-1-i]*c) % mod;

               //
               // c ~ 2^(i)
               //
               c = (c<<1)%mod;
           }

           //
           // Important to use + mod because in c++ mod of -ve is -ve.
           //
           return (res+mod)%mod;

       }
};


