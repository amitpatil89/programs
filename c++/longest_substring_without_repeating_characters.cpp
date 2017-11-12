
#include <string>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {

    int start = 0;
    int current = 0;
    unordered_set<char> refSet;
    int maxLen = 0;
    int currLen = 0;
    char c;
    bool notFound; // flag for do-while loop

    while(current < s.length()){
        notFound = true;

        c = s[current];
        ++currLen;

        auto it = refSet.find(c);
        if(it == refSet.end()){
            // current char is not there in the refSet this becomes part of
            // longest substring with unique charcters
            maxLen = (maxLen < currLen) ? currLen: maxLen;  
            refSet.insert(c);
        }else{
            // this char is present in the refSet. So start removing elements
            // from set and also change the currLen untill we reach the element 
            // with repeating character.
            do{
                if(s[start] == c)
                    notFound = false;
                else{
                    // we don't want to remove the character c from this set 
                    // becuase it still is part of our next search for substring
                    // consider "abca" and think about it.. 
                    refSet.erase(s[start]);
                }
                start++;
                currLen--;

            }while(notFound);
        } 
        current++;
    }
    return maxLen;
}

int main(){
    
    cout << "Enter a substring : ";
    string str;
    cin >> str;
    cout << "length of longest substr without repeating chars = "<< lengthOfLongestSubstring(str) << endl;
    return 0;
}
