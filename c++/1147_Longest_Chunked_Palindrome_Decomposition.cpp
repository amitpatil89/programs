//  1147. Longest Chunked Palindrome Decomposition
//  https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
//  
//  Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:
//  
//  Each a_i is a non-empty string;
//  Their concatenation a_1 + a_2 + ... + a_k is equal to text;
//  For all 1 <= i <= k,  a_i = a_{k+1 - i}.
//   
//  Example 1:
//  
//  Input: text = "ghiabcdefhelloadamhelloabcdefghi"
//  Output: 7
//  Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
//  Example 2:
//  
//  Input: text = "merchant"
//  Output: 1
//  Explanation: We can split the string on "(merchant)".
//  Example 3:
//  
//  Input: text = "antaprezatepzapreanta"
//  Output: 11
//  Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
//  Example 4:
//  
//  Input: text = "aaa"
//  Output: 3
//  Explanation: We can split the string on "(a)(a)(a)".
//   
//  
//  Constraints:
//  text consists only of lowercase English characters.
//  1 <= text.length <= 1000
//  
//  Solution:
//      1. Get the first character c_start
//      2. Find the occurence (i.e. end_idx) of this character from the back of the string
//      3. Now, check where the string matches from these 2 indexes (start  and end_idx).
//      4. If they match, increment count by 2.
//      5. Else, find the next occurence of c_start and repeat.
//  
//  
//  

class Solution {
public:
    int longestDecomposition(string text) {

        int count = 0;              // result
        int size = text.size();

        int start = 0;   // start index of the string we are working on
        int end = size-1; // end index of the string we are working on
        int search_end = end; // while seaching for a occurence of a character
                              // from the back of the string, this index is where
                              // we start looking for a character.

        while(start <= end) {

            // Get the first character - 'c_start'
            char c_start = text[start];

            // Get the last occurence of the 'c_start'
            //      In other words, start from the back of the string
            // and find the index of 1st occurence of 'c_start'
            int end_idx = text.rfind(c_start, search_end);

            // If start and end_idx are same. We are done
            if (start == end_idx) {
                count++;
                break;
            }

            // Get the possible length of the substring which is equal.
            int n = end-end_idx;

            // Check if substring matches. Substring starts from index
            // start and end_idx and have length n.
            if (start < end_idx && text[start+n] == text[end]) {
                if (stringMatch(text, start, end_idx, n)) {
                    // substrings are matching. Increase count by 2
                    count+=2;

                    // Update start and end
                    start += (n+1);
                    end = end_idx-1;
                }
            }
            // Let's update the search_end
            search_end = end_idx-1;
        }
        return count;
    }

    // API to check whether 2 strings are same
    // input:
    //      text: complete string
    //      front_idx: start index of 1st string
    //      back_index: start index of 2nd string
    //      n: legth of the string from the start index.
    // output:
    //      true: if all the 'n' characters match from the start
    //             index
    //      false: if not true^.
    bool stringMatch(string &text, int front_idx, int back_idx, int n) {
        for (int i=0; i<=n; i++) {

            if (text[front_idx+i] != text[back_idx+i]) {
                return false;
            }
        }
        return true;
    }
};

