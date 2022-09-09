#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char ch[n];
    for( int i = 0; i < n; i++ ){
        cin >> ch[i];
    }
    int plus = 0, minus = 0;
    for( int i = 0; i < n; i++ ){
        if( ch[i] == '+' ) plus++;
        if( ch[i] == '-' ) minus++;
    }
    if( plus > minus ) cout << plus;
    else cout << minus;
    return 0;
}