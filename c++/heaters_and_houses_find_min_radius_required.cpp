 
//  Leetcode 475. Heaters
//  
//  you are given positions of houses and heaters on a horizontal line, find out minimum 
//  radius of heaters so that all houses could be covered by those heaters.
//  
//  So, your input will be the positions of houses and heaters seperately, and your 
//  expected output will be the minimum radius standard of heaters.
//  
//  Note:
//      1. Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
//      2. Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
//      3. As long as a house is in the heaters' warm radius range, it can be warmed.
//      4. All the heaters follow your radius standard and the warm radius will the same.
//  
//  Input: [1,2,3,4],[1,4]
//  Output: 1
//  Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, 
//               then all the houses can be warmed.




#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {


            int i = 0;
            int radius = 0;
            int start = 0;
            int rad = INT_MAX;
            int currRad;
            int minRad;

            // Sorting is required because rest of the algorithm things that 
            // houses and heaters are in sorted order.
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());

            for(auto house: houses){
                // initiate the minRad to INT_MAX
                minRad = INT_MAX;

                // Go through each of the heaters, remember that since
                // we sorted the vector before, we need start from 0 everytime.
                for(i=start; i<heaters.size(); ++i){
                    // Get the current radius
                    currRad = abs(house - heaters[i]);

                    // if curr_rad <= minRad ? update: break;
                    // Think: if house is equidistant from 2 heaters we want to select the higher index because
                    //        the houses coming next will be closer to that anyway. 
                    if(currRad <= minRad){
                        minRad = currRad;
                    }else{
                        // We have got our minRad for this house break the 
                        // loop and move ahead
                        start = i - 1;
                        break;
                    }
                }
                if(start == heaters.size()){
                    start = heaters.size() -1;
                }

                // Update the max radius so far
                radius = max(radius, minRad);

            }

            return radius;

        }

};

int main(){

    vector<int> houses {1,2,4,70};
    vector<int> heaters {90};
    Solution obj;

    cout << "radius = " << obj.findRadius(houses,heaters) << endl;

    return 0;   
}
