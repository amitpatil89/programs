//  Leetcode #672. Bulb Switcher II
//  
//  There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.
//  
//  Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:
//  
//  Flip all the lights.
//  Flip lights with even numbers.
//  Flip lights with odd numbers.
//  Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
//  Example 1:
//  Input: n = 1, m = 1.
//  Output: 2
//  Explanation: Status can be: [on], [off]
//  Example 2:
//  Input: n = 2, m = 1.
//  Output: 3
//  Explanation: Status can be: [on, off], [off, on], [off, off]
//  Example 3:
//  Input: n = 3, m = 1.
//  Output: 4
//  Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
//  Note: n and m both fit in range [0, 1000].
//  
//  Trick: Bulb pattern repeats itself after first 6 bulbs. So for (n>5) we consider only 1st 6 bulbs. 
//         Check the implementation below to see how we can use mask in this scenario.


class Solution {

// 
// Default masks
//
#define DEFAULT 0x2F   
#define ALL     0x2F    // Flip all the lights.
#define EVEN    0x15    // Flip lights with even numbers.
#define ODD     0x2A    // Flip lights with odd numbers.
#define THREE   0x11    // Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

    public:
        int flipLights(int n, int m) {

            //
            // After 6 bulbs, pattern keeps on repeating utself
            // so if (n > 5), we consider only first 6 bulbs.
            //
            int num = (n>5)? 6 : n;

            auto j=0;
            int mask = 0;

            //
            // let's calculate the mask for the default masks,
            // This is needed if the number of bulbs is less
            // than 6
            //
            while(j<num){
                mask=mask|(1<<j);
                j++;
            }

            int mask1 = ALL & mask;     // mask of --> Flip all the lights.
            int mask2 = EVEN & mask;    // mask of --> Flip lights with even numbers.
            int mask3 = ODD & mask;     // mask of --> Flip lights with odd numbers.
            int mask4 = THREE & mask;   // mask of --> Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...


            set<int> mySet{};
            int bulbs = DEFAULT; // We care about the 6 bits at max.   
            mySet.insert(bulbs); // initialize the set
            queue<int> myQ;      
            setToQ(mySet, myQ);

            int item;

            while (m>0 && !myQ.empty()) {

                // Clear the set
                mySet.erase(mySet.begin(), mySet.end());

                while (!myQ.empty()) {

                    // Take front item in the queue.
                    item = myQ.front();

                    // operation 1
                    mySet.insert(item^mask1);

                    // operation 2
                    mySet.insert(item^mask2);

                    // operation 3
                    mySet.insert(item^mask3);

                    // operation 4
                    mySet.insert(item^mask4);

                    // remove this item from queue we are done with it
                    myQ.pop();

                }

                // convert the set into queue so that we can crunch it again if we have any m left
                setToQ(mySet, myQ);
                m--;
            }

            // numbre of unique combinations are nothing but size of the set.
            return mySet.size();

        }

        void setToQ(set<int>& mySet, queue<int>& myQ){
            for(auto vec: mySet){
                myQ.push(vec);
            }
        }
};
