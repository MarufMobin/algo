#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for( int i = 0; i < n-2; i+=2 ){
        for( int s = i/2; s < n/2; s++ ){
            cout << " ";
        }
        for( int j = 0; j <= i; j++ ){
            cout << "*";
        }
        cout << endl;
    }
    for( int i = 0; i <= n-1; i+=2 ){
       for( int s = 0; s < i-1; s+=2 ){
            cout << " ";
        }
        for( int j = i; j < n; j++ ){
            cout << "*";
        }
        cout << endl;
    }
   
}