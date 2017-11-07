//  
//  Leetcode  391. Perfect Rectangle
//  
//  Given N axis-aligned rectangles where N > 0, determine if they all together 
//  form an exact cover of a rectangular region.
//  
//  Each rectangle is represented as a bottom-left point and a top-right point. 
//  For example, a unit square is represented as [1,1,2,2]. 
//  (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
//  
//  Example:
//  rectangles = [
//      [1,1,3,3],
//      [3,1,4,2],
//      [3,2,4,4],
//      [1,3,2,4],
//      [2,3,3,4]
//  ]
//  
//  Return true. All 5 rectangles together form an exact cover of a rectangular region.
//  
//  Link: https://leetcode.com/problems/perfect-rectangle/description/
//  
//  
//  
//  Solution:
//  ==========
//  
//  This is a hard problem to solve but solution is comparatively easy. 
//  
//  1.  Each rectangle [a,b,c,d] has (a,b) as bottom left and (c,d) as top-rght corner.
//      It is intuitive that to find the bottom-left corner and top-right corener of the
//      possible perfect rectangle, we need min (a,b) and max (c,d) from all the rectangles. 
//      Let's call them (botRow, botCol) and (topRow, topCol).
//  
//  2.  Consider a rectangle [a,b,c,d]; four corners for this rectangle 
//      can be represented in the form of a pair  (a,b) (c,d) (a,d) and (c,a). 
//  
//  3.  Take a set _refSet which has elements in the form of pairs. Put the corners of ALL 
//      the rectangles in this set in following way:
//  
//      if pair(x,y) is not in _refSet:
//          insert (x,y) in _refSet
//      else:
//          remove (x,y) from _refSet
//  
//  4.  Now, in the case where we have a perfect rectangle, we will be left with only 4 corners
//      which must be (topRow, topCol), (topRow, botCol), (botRow, topCol) and (botRow, botCol)
//  
//  5.  if we try to update the refSet with these remaining 4 corners, we will have empty set which means
//      PROBABLY we have the perfect square.
//  
//  6.  PROBABLY because, above solution fails for following case:
//      rectangles = [
//          [0,0,3,3],
//          [1,1,2,2],
//          [1,1,2,2],
//      ]
//  
//  7.  To tackle this, we can use the area. From step 1, we have the 2 diagonal corners of rectangle.
//      From that, we can calculate the maximum area (A) we are looking for. 
//      Now, while parsing through the rectangle vector, for each rectangle, we will calculate its area
//      and then subtract it from the (A). If at any point, this A < 0. We know that we have overlapping 
//      areas and we can directly return false. Else, true.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    private:
        set<pair<int, int>> _refSet;

    public:
        bool isRectangleCover(vector<vector<int>>& rectangles) {

            // get the bottom-left and top-right corner for the final rectangle
            int botRow = INT_MAX;
            int botCol = INT_MAX;
            int topRow = 0;
            int topCol = 0;

            for(auto row: rectangles){
                if(row[0] < botRow) botRow = row[0];
                if(row[1] < botCol) botCol = row[1];
                if(row[2] > topRow) topRow = row[2];
                if(row[3] > topCol) topCol = row[3];
            }
            
            // Now that we have the co-ordinates for possible perfect rectangle, 
            // calc its area (refered as A above)
            long area = (topRow - botRow) * (topCol - botCol);

            // Parse through each rectangle and update _refSet with rectangle's corners
            for(auto row: rectangles){

                refSetUpdate(pair<int, int> (row[0],row[1]));
                refSetUpdate(pair<int, int> (row[2],row[3]));
                refSetUpdate(pair<int, int> (row[0],row[3]));
                refSetUpdate(pair<int, int> (row[2],row[1]));
                
                // deduct this rectangles's area from the total area we calculated
                area = area - (row[2] - row[0]) * (row[3] - row[1]);
                if(area < 0){
                    // we can safely say that overlapping rectangles exist i.e. return false
                    cout << "area cought this" << endl;
                    return false;
                }
            }
            
            // Let's see if we empty the _refSet if we update it with our possible perfect rectangle
            refSetUpdate(pair<int, int> (botRow,botCol));
            refSetUpdate(pair<int, int> (botRow,topCol));
            refSetUpdate(pair<int, int> (topRow,botCol));
            refSetUpdate(pair<int, int> (topRow,topCol));        
            
            // if _refSet is empty, return true.
            return (_refSet.size() == 0)? true: false;
        }
        
        // Update the _refSet as per the Algorithms in Step 3.
        void refSetUpdate(pair<int, int> tempPair){
            if(_refSet.find(tempPair) != _refSet.end()){
                _refSet.erase(_refSet.find(tempPair));
            }else{
                _refSet.insert(tempPair);
            }
        }
};

int main(){
  vector<vector<int>> rectangles {{1,1,3,3}, {3,1,4,2}, {3,2,4,4}, {1,3,2,4},{2,3,3,4}}; // expected output : true

  Solution S;
  cout << ((S.isRectangleCover(rectangles)) ? "true":"false") << endl;

  rectangles = {{0,0,3,3}, {1,1,2,2}, {1,1,2,2}}; // expected output : false (due to reason mentioned in step 6)
  cout << ((S.isRectangleCover(rectangles)) ? "true":"false") << endl;

}
