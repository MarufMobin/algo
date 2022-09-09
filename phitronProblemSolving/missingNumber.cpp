#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;

    while( t-- ){
        int total, first, second, third;
        cin >> total >> first >> second >> third;
        int due = first + second + third;
        cout << total - due;
    }
    
    return 0;
}