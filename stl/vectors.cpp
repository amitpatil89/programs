
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
print (vector<int> &vec){
    for(auto element : vec)
        cout << element << " ";
    cout << endl << endl;
}

void
print2d (vector<vector<int>> &vec){
    for(auto row : vec){
        for(auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){

    // 1. create a vector with 10 elements and initialize these elements with value 100.
    vector<int> vec (10, 100); 
    print(vec);

    vector<int> vec3 (10);
    print(vec3);

    // 2. Create a 2D vector of size (nRow x ncol) and initialize all of its elements to 100
    //    Check from 1 that syntax remains the same. Since this is vector of vectors, we
    //    are saying that vec1 has nRow number of vectors with each vector of size nCol and element 100.
    int nRow = 3;
    int nCol = 4;
    vector<vector<int>> vec1 (nRow, vector<int>(nCol, 100));
    print2d(vec1);

    // 3. Initialize a 2D vector with initializer list
    vector<vector<int>> vec2 {{0,1,2,3}, {2,3,4,5}, {5,6,7,8}};
    print2d(vec2);

    // 4. copy a 2d vector
    vector<vector<int>> vec4(vec1);
    print2d(vec4);

    // 5. generate a vector of 10 elements {0,1,2 ...9}
    vector<int> vec5;
    generate_n(back_inserter(vec5), 10, [](){static int i = 0; return i++;});
    print(vec5);

}


