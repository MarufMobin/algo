#include<bits/stdc++.h>
using namespace std;
void printArray( int arr[], int n ){
    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
}
int main(){

    int arr[50];

    int n;
    cin>>n;

    for( int i = 0; i < n; i++ ){
        cin>>arr[i];
    }
    //Print Output
    printArray( arr, n );
    return 0;
}
