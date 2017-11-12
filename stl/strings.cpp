#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string complexNumberMultiply(string s) {
    stringstream ss(s);
    string token;
    while(getline(ss, token, ' ')){

        cout << token << endl;
    }
    return s;
}

int main(int argc, char *argv[]){

    cout << complexNumberMultiply("amit is great!");
    
    return 0;
}
