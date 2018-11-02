//  
//  Hotel Selection (non leetcode)
//  
//  There are 2 roommates who come up with the restaurants they want to eat at. 
//  Find the common hotel which has the maximum weightage as per both of them.
//  
//  If there is no common restaurant, they go to "yelpwich"
//  
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

string select(vector<string> a, vector<string> b) {
    
    unordered_map<string, int> hash;
    string finalRestaurant = "yelpwich";
    int minWt = INT_MAX;
    
    for (int i=0; i<a.size(); i++) {
        hash.insert(make_pair(a[i],i));    
    }

    for (int j=0; j< b.size(); j++) {
        auto hotel = b[j];

        auto it = hash.find(hotel);
        if (it != hash.end()) {
            // Found common hotel
            auto currentWt = j+ (it->second);
            if(currentWt < minWt) {
                finalRestaurant = hotel;
                minWt = currentWt;
            }
        }
    }
    
    return finalRestaurant;

}


int main(){
    
    vector<string> a = {
                        "madras",
                        "shah",
                        "gingercafe",
                     };
    
    cout << "Friend 1 prefers:" << endl;
    for(auto str: a)
        cout << str << endl;

    cout << endl << endl;
    vector<string> b=  {
                        "gingercafe",
                        "madras",
                        "shah",
                     };
    cout << "Friend 2 prefers:" << endl;
    for(auto str: b)
        cout << str << endl;
    
    cout << endl;
    cout << "Final Choice: " << select(a,b) << endl;
    return 0;
}
