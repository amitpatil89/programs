//  Leetcode #6 ZigZag Conversion (https://leetcode.com/problems/zigzag-conversion/description/)
//  
//  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//  (you may want to display this pattern in a fixed font for better legibility)
//  
//  P   A   H   N
//  A P L S I I G
//  Y   I   R
//  And then read line by line: "PAHNAPLSIIGYIR"
//  
//  Write the code that will take a string and make this conversion given a number of rows:
//  
//  string convert(string s, int numRows);
//  
//  Example 1:
//  Input: s = "PAYPALISHIRING", numRows = 3
//  Output: "PAHNAPLSIIGYIR"
//  
//  
//  Example 2:
//  Input: s = "PAYPALISHIRING", numRows = 4
//  Output: "PINALSIGYAHRPI"
//  Explanation:
//  
//  P     I    N
//  A   L S  I G
//  Y A   H R
//  P     I
//  
//  ========= 
//  Solution
//  =========
//  
//  Algorithm : Take a vector of strings with number of elements = numRows. Lets call them string0 ..string(n-1)
//              Purpose of these strings is as follows
//              string[0]       P     I    N
//              string[1]       A   L S  I G
//              string[2]       Y A   H R
//              string[3]       P     I
//  
//              Now, we are just moving from row0-->row3 and back and putting 1 char each. In the end,
//              result = string[0] + string[1] + string[2] + string[3]
//  
//              Time complexity: O(n)
//              Space complexity: O(n)


class Solution {
    public:
        string convert(string s, int numRows) {
            
            //
            // numRows less than 2, return string as is.
            //
            if (s.size() < numRows || numRows == 1) {
                return s;
            }

            string result = "";
            vector<string> refStr(numRows, ""); // vector to store the result

            bool inc = true; // indicates the directions. Incrementing rows = true.

            int i = 0;
            for (auto c : s){

                refStr[i].push_back(c);
                i = (inc) ? i + 1 : i - 1;
                if (i==numRows && inc) {
                    i = numRows - 2;
                    inc = false;
                }

                if (i== -1 && !inc) {
                    i = 1;
                    inc = true;
                }
            }

            //
            // combine result.
            //
            for (string str: refStr) {
                result.append(str);
            }

            return result;

        }
};


