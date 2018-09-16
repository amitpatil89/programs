// 
// Asked to someone in UBER
// We want to process driver online and offline logs to gain some insight. Logging system doesn't guarantee log delivery order.
//  Input:
//  driver_uuid online_ts   offline_ts
//  1           900         1000
//  2           930         940
//  3           915         925
//  1           1001        1200
//  
//  For each timestamp from the input, in chronological order print out the number of active drivers at the timestamp, each record as `(timestamp, num)`, where `num` is number of active drivers at this timestamp. online_ts is inclusive, offline_ts is exclusive.
//  Output:
//  900, 1
//  915, 2
//  925, 1
//  930, 2
//  940, 1
//  1000, 0
//  1001, 1
//  1200, 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;


void getLogs(vector<vector<int>> logs) {
    
    vector<int> online, offline;
    for (auto row: logs) {
        online.push_back(row[1]);
        offline.push_back(row[2]);
    }

    // sort both the vectors
    sort(online.begin(), online.end());
    sort(offline.begin(), offline.end());

    //speacial merge
    int i=0, j=0, count = 0;
    while(i<online.size() || j<offline.size()) {

        int a = INT_MAX;
        int b = INT_MAX;

        if (i<online.size()) {
            a = online[i];
        }

        if (j<offline.size()) {
            b = offline[j];
        }

        if (a == b ) {
            i++;
            j++;
            cout << a << "," << count << endl;;
        } else {
            if(a < b) {
                i++;
                count++;
                cout << a << "," << count << endl;;
            } else {
                j++;
                count--;
                cout << b << "," << count << endl;
            }
        }
    }

}

int main(){
    
    int i,j;
    vector< vector<int>> ref {{1,  900,  1000},
                              {2,  930,  940},
                              {3,  915,  925},
                              {1, 1001, 1200}
                             };
    cout << "Input: " << endl;
    for (auto row: ref){
        for(auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }    
    
    cout << "Output: " << endl;
    getLogs(ref);

    return 0;
}
