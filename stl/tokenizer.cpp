#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//  This method uses iterator for creating tokens. 
vector<string> split(string str, char delimiter){

    string::iterator itStart, itEnd= str.begin();
    cout << "tokenizing from split()" << endl;
    cout << str << endl << endl;
    vector<string> ret;
    do{

        itStart = find_if(itEnd, str.end(), [delimiter](char c){return (c != delimiter);});
        itEnd = find_if(itStart, str.end(), [delimiter](char c){return (c == delimiter);});
        if(itStart == str.end()){
            break;
        }
        ret.push_back(string (itStart, itEnd));  // Check that we are creating string object in place using 2 operators.
    }while(itEnd != str.end());
    return ret;
}

//  This method uses stringstream *requires us to include sstream*
vector<string> streamSplit(string str, char delimiter){
    string token;
    stringstream ss(str);
    vector<string> ret;
    cout << "tokenizing from streamSplit()" << endl;
    cout << str << endl << endl;

    while(getline(ss, token, delimiter)){
        ret.push_back(token);
    }
    return ret;
}

void print(vector<string> tokens){
    cout << " ----------------------" << endl;
    for(auto token : tokens){
        cout << token << endl;
    }
    cout << " ----------------------" << endl;
    cout << endl << endl;
}

int main(int argc, char *argv[]){

    string str = "This is so cool!";
    vector<string> tokens1, tokens2;
    tokens1 = split(str, ' ');
    print(tokens1);
    tokens2 = streamSplit(str, ' ');
    print(tokens2);

    
    return 0;
}
