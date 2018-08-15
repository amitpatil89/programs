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
//  Solution: 1. Constantly run a loop betn (1,n) until 1,2,4 ...n/2, n; such that (n/2)^2 <= num <= n^2
//            2. Now do the same in (1)  between (n/2, n/2+1, n/2+2, n/2+4 ...n) and keep doing
//  
//  TRICKY THING TO NOTE: observe following code. We MUST use long to avoid overflow.
//  
//            Complexity O(log n)
//  
//       example:
//       [1]  input = 289 expected output = true (17*17 = 289)
//  
//              a: 1 b: 1
//              a: 1 b: 2
//              a: 2 b: 4
//              a: 4 b: 8
//              a: 8 b: 16
//              a: 16 b: 32 <== square root could be between [16,18]
//              New 
//              a: 16 b: 17 <== We reached 17! Return TRUE
//  
//       [2]    input: 1122 expected output: false
//  
//              a: 1 b: 1
//              a: 1 b: 2
//              a: 2 b: 4
//              a: 4 b: 8
//              a: 8 b: 16
//              a: 16 b: 32
//              a: 32 b: 64 <== square root could be between [32,64]
//  
//              a: 32 b: 33
//              a: 33 b: 34 <== square root could be between [33, 34]
//  
//              a: 33 b: 34 <== got repeated bcoz there is no integer between them. Return FALSE
//  

class Solution {
    public:
        bool isPerfectSquare(int num) {

            int a = 1;
            long b; // long is needed for bigger numbers such as num=2147483648

            // Find the range a,b such that a^2 <= num <= b2
            bool update;
            int base = 0;
            b = base + pow(2,0);

            do {
                int i = 1;
                update = false;

                while(b*b<= num) {
                    update = true;
                    if (b*b == num) return true;
                    a = b;
                    b = base + pow(2,i); // we can use 1<<i with i starting at 0. Instead of pow 
                    i++;
                }

                if(update == false) {
                    return false;
                }
                base = a;
                b = base + pow(2,0);

            } while(1);

        }
};
