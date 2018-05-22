//  Leetcode 17: Letter Combinations of a Phone Number
//  
//  Question: Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
//            that the number could represent.
//  
//  Example: Input: "23"
//           Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//  
//  Note: Although the above answer is in lexicographical order, your answer could be in any order you want.
//  
//  Answer/Hint: Think BFS



#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
    public:
        vector<string> letterCombinations(string digits) {

            //
            // Store all the strings in a vector
            //
            vector<string> num{"","","abc", "def","ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};

            //
            // For empty string return empty vector
            //
            vector<string> result;
            if (digits == "") {
                return result;
            }

            //
            // Queue for BFS. Initialized to ""
            //
            queue<string> _queue;
            _queue.push("");

            //
            // Basically, when we go through the digit, with every digit we get a string num[digit]
            // We need to append each of these characters to all the string combos we have in the
            // Queue. Hence BFS. 
            //
            // For e.g. consider difits = "23"
            //          _queue starts with "". Now, num[2] = "abc" --> that means we need to append 
            //          a, b and c to every string present from the last level of the _queue
            //          This gives us _queue = {"a", "b", "c"}       ---------------------------------------- (1)
            //          Similarly next if 3 i.e. num[3] = "def". This time we have 3 elements in last 
            //          level of _quque from (1). So now we will append "d", "e", and "f" separetaly
            //          on all the elements from (1) giving us the following
            //          _queue = {"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"}
            //
            for (auto d: digits) {
                auto digit = d - '0';

                int n = _queue.size();
                while(n) {
                    string qElement = _queue.front();
                    _queue.pop();
                    string current = num[digit];

                    for(auto c: current) {
                        _queue.push(qElement+c);
                    }
                    n--;
                }

            }

            while(!_queue.empty()){
                result.push_back(_queue.front());
                _queue.pop();
            }

            return result;

        }
};

using namespace std;

int main(){
    return 0;
}
