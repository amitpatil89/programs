//  Leetcode #367. Valid Perfect Square
//  
//  Given a positive integer num, write a function which returns True if num is a perfect square else False.
//  
//  Note: Do not use any built-in library function such as sqrt.
//  
//  Example 1:
//  Input: 16
//  Returns: True
//  
//  Example 2:
//  Input: 14
//  Returns: False
//  
//  
//  Solution: Use binary search to find the possible sqrt, if we don't find one, return false.  
//  
class Solution {
    public:
        bool isPerfectSquare(int num) {

            long a=1;
            long b=num;    
            long mid;

            //
            // In the binary search, moment a>b, end this loop
            //
            while (a<=b) {
                //
                // Get the mid
                //
                mid = (a+b)/2;

                //
                // If we mid is the square root, return
                //
                if(mid*mid == num)
                    return true;

                //
                // If mid^2 < num, possible sqrt is > mid
                // Else possible sqrt < mid
                //
                if (mid*mid < num) {
                    a = mid+1;
                } else {
                    b = mid-1;
                }
            }

            //
            // Couldn't find the sqrt, return false.
            //
            return false;  
        }  
};

