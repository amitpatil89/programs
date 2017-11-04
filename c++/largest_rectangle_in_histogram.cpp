// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Leetcode Problem: 84. Largest Rectangle in Histogram
// 
// Question: Given n non-negative integers representing the histogram's bar 
//           height where the width of each bar is 1, find the area of largest 
//           rectangle in the histogram.

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    private:
        vector<int> _heights;
    public:
        int largestRectangleArea() {

            //     We will be keeping 2 stacks - pos & ht
            //     pos = keeps the track of positions i.e. indices
            //     ht  = keeps track of heights

            //     while traversing through the histogram i.e. vector argument heights, 
            //     at any index i, there are 3 possibilities:

            //     1. ht[top] < heights[i]
            //         push the heights[i] on ht stack.
            //         push the index i on pos stack.
            //     2. ht[top] == heights[i]
            //         ++i // do nothing else
            //     3. ht[top] > heights[i]
            //         pop ht[top] and calculate possible area using formula [ht[top] * (i - pos[top])]
            //         Now, there are 2 cases:
            //          (i) if new ht[top] < heights[i], push heights[i] on ht

            //         (ii) if new ht[top] is again > heights[i], pop pos[top] as well and calculate the area again
            //         keep doing above untill pos[top] < heights[i] 

            //      Note: at the end of each step, no of elements in ht and pos should be equal.        

            //     ref: https://www.youtube.com/watch?v=VNbkzsnllsU

            stack<int> pos;
            stack<int> ht;

            int i;
            int height;
            int maxArea = 0;
            int area;

            if(_heights.size() == 0){
                return 0;
            }

            pos.push(0);
            ht.push(_heights[0]);

            cout << pos.top() << endl;

            bool popPos = false;
            for(i = 1; i < _heights.size(); ++i){
                height = _heights[i];
                if(ht.top() == height){
                    continue;
                }
                if(ht.top() < height){
                    ht.push(height);
                    pos.push(i);
                    continue;
                }
                if(ht.top() > height){
                    popPos = false;
                    do{
                        // this is for the case when we are removing 2 elements from ht stacks
                        if(popPos){
                            pos.pop();
                        }
                        // Pop the ht top since the height we have is lower than it.
                        // Also, calculate area for the same
                        area = ht.top() * (i - pos.top());
                        ht.pop();
                        if (maxArea < area){
                            maxArea = area;
                        }
                        popPos = true;

                    }while(!(ht.empty()) && ht.top() > height);
                    ht.push(height);
                }

            }

            if(ht.size() != pos.size()){
                cout << "Something terribly went wrong htSize = " << ht.size() << "posSize = " << pos.size() << endl;
            }


            // Let's see if there are any other calculations left to do
            while(!ht.empty() && !pos.empty()){

                // cout << "i = " << i << " ht = " << ht.top() << "pos = " << pos.top() << endl;
                area = ht.top() * (i - pos.top());
                ht.pop();
                pos.pop();
                if (maxArea < area){
                    maxArea = area;
                }            

            }

            return maxArea;

        }

        Solution(vector<int> vec) : _heights(vec){};
};// class end


int main(){
    
    
    Solution obj(vector<int>{6,4,2,8,5,5,0,7,7});

    cout << "maxArea = " << obj.largestRectangleArea() << endl;


    return 0;
}


