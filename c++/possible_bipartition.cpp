// 
// Leetcode #890. Possible Bipartition
// Link: https://leetcode.com/problems/possible-bipartition/description/
// 
// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
// 
// Each person may dislike some other people, and they should not go into the same group. 
// 
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
// 
// Return true if and only if it is possible to split everyone into two groups in this way.
// 
// Example 1:
// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// 
// Example 2:
// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// 
// Example 3:
// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
// 
// Note:
// 
// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].



#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
    public:
        //
        // See if bipartition is possible for dislikes elements. Refer question!
        //
        bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
            
            //
            // If size of dislikes is less than 2 return true
            //
            if(dislikes.size() < 2)
                return true;

            //
            // Bipartition = 2 groups. Hence, let's create 2 groups to keep track of 
            // 2 partitions. Initialize everything to 0. Using N+1 so that we can 
            // directly use person's number as in index in this map.
            //
            vector<int> groupA(N+1,0);
            vector<int> groupB(N+1,0);
            int p1, p2;

            //
            // Very first pair will not have any collision. So let's set the corresponding
            // indexes in groupA and groupB to 1.
            //
            p1 = dislikes[0][0];
            p2 = dislikes[0][1];
            groupA[p1] = 1;
            groupB[p2] = 1;

            //
            // Queue is used to go through the remaining dislikes pairs. Initialize the queue with all the
            // remaining dislike pairs. This Q is used to do a BFS with a twist. The motivation is 
            // to initialize the map as above and then use the queue to do the following
            // for any pair (p1, p2) in the Queue.
            // 
            // Concept: if p1 or/and p2 is set to 1 in groupA/B, we know that there is some
            // pre-existing requrement for them. So we check the following
            //
            // (1) If p1 and p2 are set in the same group, this is Collision! return false.
            // (2) If p1 and p2 are not set in any group, we are not sure which group p1/p2 should go
            //     so, if 'adjust' is not set to true (explained later when it is set/reset), just 
            //     put the pair in the queue again. Chances are that the upcoming pairs will add some
            //     information to chose a group for these people.
            // (3) If p1 and p2 are already set in opposite groups, our work is done for that pair.
            // (4) If only one of {p1,p2} is set in a group, we set the other person in opposite group.
            //
            // Now the 'twist' i.e. adjust == true/false
            // In our algorithm, it is quite possible that there are some pairs which are pretty distant
            // from the digested pairs. Consider the following.
            //
            // Input: N=6; dislikes=[[1,2],[2,3],[1,4],[5,6]]
            //
            // In the above case, our BFS will keep on looping due to pair [5,6] as per (2). To break this loop, we keep
            // track of current queue size i.e. qSize and previous/old queue size i.e. oldSize. 
            // When qSize == oldSize; that is an indication for us to 'adjust' the mapping. In this case,
            // we take the first pair(p1,p2) in the existing queue and put p1 and groupA and p2 in groupB.
            // Since they were not related to any of the digested pair in any way, chosing groupB for p1
            // groupA for p2 is also fine and wouldn't make any difference. This way, we break the loop.
            // 
            // We also remember to turn this adjust flag to false after doing 1 'adjustment'. 
            //
            queue<vector<int>> Q;

            for (auto couple: vector<vector<int>> (dislikes.begin()+1, dislikes.end())) {
                Q.push(couple);
            }
            
            bool adjust;
            int qsize=0;
            vector<int> current;

            int qSize = 0, oldSize=0;

            // Standard BFS with a twist of 'adjust'
            while(!(Q.empty())) {
                qSize = Q.size();
                
                if(qSize == oldSize) {
                    // if there is a loop!, break it using 'adjust'
                    adjust = true;
                }
                oldSize = qsize;
                
                while(qSize > 0) {

                    current = Q.front(); Q.pop();
                    p1 = current[0];
                    p2 = current[1];

                    if((groupA[p1] == 1 && groupA[p2] == 1) || (groupB[p1] == 1 && groupB[p2] == 1)) {
                        return false;
                    }

                    if((groupA[p1] == 0 && groupB[p2] == 0) && (groupA[p2] == 0 && groupB[p1] == 0)) {

                        if(adjust) {
                            groupA[p1] = 1;
                            groupB[p2] = 1;
                            adjust = false;
                        } else {

                            Q.push(vector<int>{p1,p2});
                        }
                    }else{ 

                        if(groupA[p1] == 1) groupB[p2] = 1;
                        if(groupA[p2] == 1) groupB[p1] = 1;     
                        if(groupB[p1] == 1) groupA[p2] = 1;
                        if(groupB[p2] == 1) groupA[p1] = 1;
                    }

                    qSize--;
                }

            }
            return true;

        }

};


int main(int argc, char *argv[]) {

    Solution obj;
    
    vector<vector<int>> input = {{1,2},{1,3},{2,3}}

    int N =  3;

    cout << obj.possibleBipartition(N, input);

    return 0;
}
