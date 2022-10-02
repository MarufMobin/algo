#include<bits/stdc++.h>
using namespace std;

int main(){
    // map<int, int> mp;
    unordered_map<int , int> mp;
    mp[3] = 9;
    mp[2] = 3;
    mp.insert( make_pair(1,4) );
    cout << "Key" << "  | " << "Value " << endl; 
    for( auto i : mp ){
        cout << i.first << "    | " << i.second << endl;
    }
    return 0;
}