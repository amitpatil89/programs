#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    vector<int> res;

    for(int i = 0; i < nums.size(); i++){
        while(nums[i] != i+1){
            if(nums[i] == nums[nums[i]-1]){
                if(find(res.begin(), res.end(), nums[i]) == res.end()){
                    res.push_back(nums[i]);
                }
                break;
            }
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    return res;
}



int main(){

    return 0;
}
