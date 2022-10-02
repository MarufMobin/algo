#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[n];
    for( int i = 0; i < n; i++ ){
        cin >> array[i];
    }
    map<int,int>mp;
    for( int i = 0; i < n; i++ ){
        mp[array[i]]++;
    }
    map<int,int> :: iterator it;
    for( it = mp.begin(); it != mp.end(); it++ ){
        cout << it->first << " = " << it->second << endl;
    }
    return 0;
}

/* 
10
2 1 2 2 3 4 9 4 3 5
 */