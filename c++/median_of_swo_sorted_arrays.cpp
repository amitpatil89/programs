
//#   4. median_of_swo_sorted_arrays.cpp
//#   
//#   Highly recommended: https://www.youtube.com/watch?time_continue=1483&v=LPFhl65R7ww&feature=emb_logo
//#   
//#

class Solution {
public:
    double findMedianSortedArrays(vector<int>& X, vector<int>& Y) {

        /* Get the size of each array */
        int x = X.size();
        int y = Y.size();

        /* We want to have X as the smaller/equal size array than Y */
        if (x > y) {
            /* Call the same API again with switched inputs */
            return findMedianSortedArrays(Y, X);
        }


        /*
            Total number of elements T = (x+y)
            For T ~ Odd, median is at (x+y+1)/2
                T ~ Even, median is avg of {(x+y+1)/2, ((x+y+1)/2 + 1)}
        */

        // Let's define low and hi which are the places where partition can be made.
        // Note: We are defining the patition place, it's not the index and hence hi = x is valid

        int low = 0; // if we partition at this, there will be no elements on the Left
        int hi  = x; // if we partition at this, there will be no elements on the Right

        while(low <= hi) {
            int partitionX = (low+hi)/2;
            int partitionY = (x+y+1)/2 - partitionX;

            /* If we are partitioning at the left edge, assume the element as INT_MIN */
            int maxLeftX = (partitionX == 0) ? INT_MIN: X[partitionX-1];
            int maxLeftY = (partitionY == 0) ? INT_MIN: Y[partitionY-1];

             /* If we are partitioning at the right edge, assume the element as INT_MAX */
            int minRightX = (partitionX == x) ? INT_MAX: X[partitionX];
            int minRightY = (partitionY == y) ? INT_MAX: Y[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x+y)%2 == 1) {
                    /* Odd number of elements, result = highest on the Left */
                    return max(maxLeftX, maxLeftY);
                } else {
                    /* Even number of elements, result = (highest on the Left + Lowest on the right)/2 */
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
                }
            } else {
                if (maxLeftX > minRightY) {
                    /* Need to shift the partitionX towards left */
                    hi = partitionX - 1;
                } else {
                    /* Need to shift the partitionX towards right */
                    low = partitionX + 1;
                }
            }
        }

        /* We should never reach here */
        return 0;
    }
};
